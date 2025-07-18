#include <windows.h>

BOOL APIENTRY DllMain(HMODULE hModule,DWORD  ul_reason_for_call,LPVOID lpReserved) 
{
    switch (ul_reason_for_call) 
    {
        case DLL_PROCESS_ATTACH:
            MessageBoxA(NULL, "DLL Injected Successfully!", "DLL Injection", MB_OK | MB_ICONINFORMATION);
            break;
        case DLL_THREAD_ATTACH:
            MessageBoxA(NULL, "Thread Injected Successfully!", "DLL Injection", MB_OK | MB_ICONINFORMATION);
            break;
        case DLL_THREAD_DETACH:
            MessageBoxA(NULL, "Thread Detached Successfully!", "DLL Injection", MB_OK | MB_ICONINFORMATION);
            break;
        case DLL_PROCESS_DETACH:
            MessageBoxA(NULL, "DLL Detached Successfully!", "DLL Injection", MB_OK | MB_ICONINFORMATION);
            break;
    }
    return TRUE;
}
