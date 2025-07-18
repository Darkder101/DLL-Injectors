#include <windows.h>
#include <iostream>

int main() {
    // Get PID of target process (e.g., Notepad)
    DWORD pid;
    std::cout << "Enter the PID of the target process: ";
    std::cin >> pid;

    // Path to the DLL (adjust if needed)
    const char *dllPath = "Simple_DLL_injector\MessageBox.dll";

    // Open target process with necessary permissions
    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
    if (hProcess == NULL) {
        std::cerr << "[-] Failed to open target process. Error: " << GetLastError() << "\n";
        return 1;
    }

    // Allocate memory in target process for DLL path
    LPVOID pRemoteMemory = VirtualAllocEx(hProcess, NULL, strlen(dllPath) + 1, MEM_COMMIT, PAGE_READWRITE);
    if (pRemoteMemory == NULL) {
        std::cerr << "[-] Failed to allocate memory in target process.\n";
        CloseHandle(hProcess);
        return 1;
    }

    // Write DLL path to allocated memory
    if (!WriteProcessMemory(hProcess, pRemoteMemory, dllPath, strlen(dllPath) + 1, NULL)) {
        std::cerr << "[-] Failed to write to target process memory.\n";
        VirtualFreeEx(hProcess, pRemoteMemory, 0, MEM_RELEASE);
        CloseHandle(hProcess);
        return 1;
    }

    // Get address of LoadLibraryA
    LPVOID pLoadLibrary = (LPVOID)GetProcAddress(GetModuleHandleA("kernel32.dll"), "LoadLibraryA");

    // Create remote thread in target process to call LoadLibraryA(dllPath)
    HANDLE hThread = CreateRemoteThread(hProcess, NULL, 0, (LPTHREAD_START_ROUTINE)pLoadLibrary, pRemoteMemory, 0, NULL);
    if (hThread == NULL) {
        std::cerr << "[-] Failed to create remote thread.\n";
        VirtualFreeEx(hProcess, pRemoteMemory, 0, MEM_RELEASE);
        CloseHandle(hProcess);
        return 1;
    }

    std::cout << "[+] DLL injected successfully.\n";

    // Cleanup
    CloseHandle(hThread);
    CloseHandle(hProcess);
    return 0;
}
