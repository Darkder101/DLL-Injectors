# Windows DLL Injector - Level 1

This project demonstrates a simple DLL injection tool built in C++ using the Windows API. It injects a DLL into a running process by taking the target's PID and using functions like `OpenProcess`, `VirtualAllocEx`, `WriteProcessMemory`, and `CreateRemoteThread`.

## 🧰 Features

- Basic DLL injection into target processes
- Uses Windows API functions for memory allocation and thread creation
- Successfully injects a sample `MessageBox.dll` into a custom executable

## 📁 Project Structure
```
DLL Injector/
├── Simple_Dll_injector/
│ ├── Local_Dll_injector.cpp
│ ├── MessageBox.cpp
| ├── example.cpp
│ └── README.md
```

## 🧪 Usage

1. Run your target executable and get its PID.
2. Run the injector: ./Local_Dll_injector.exe  
3. Enter the PID when prompted.
4. If successful, the DLL will be injected and its code executed.

> ✅ Tested on Windows 10/11. Some system apps like Notepad might have protection — use a custom test app instead.

## 🛠️ Future Plans

- Add advanced injection techniques (manual mapping, reflective injection, shellcode injection)
- Support for DLL Hijacking examples
- Create an interactive GUI version of the injector
- Detection bypass techniques for AV/EDR evasion

## 🔐 Disclaimer

This project is strictly for educational and ethical research purposes. Do not use it for unauthorized or malicious activities.

---
