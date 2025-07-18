// example.cpp
#include <windows.h>
#include <iostream>

int main() {
    std::cout << "Example target process is running.\n";
    std::cout << "PID: " << GetCurrentProcessId() << "\n";
    std::cout << "Waiting for DLL injection...\n";
    
    // Keep the process alive
    while (true) {
        Sleep(1000);
    }

    return 0;
}
