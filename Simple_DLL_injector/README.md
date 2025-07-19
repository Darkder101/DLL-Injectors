---------------------------------------------------------------------------------------------------------------
⚙️ Compilation Instructions
---------------------------------------------------------------------------------------------------------------

1. Compile the DLL using this command "g++ -shared -o MessageBox.dll MessageBox.cpp -Wl,--subsystem,windows"
    
    This command creates a DLL named MessageBox.dll.
        -shared: for DLL creation
        --subsystem,windows: hides console window when injected


2. Compile the Injector Executable using this command "g++ -o Local_Dll_injector.exe Local_Dll_injector.cpp"

    This builds the injector executable that injects the DLL into another process.


3. Compile the Target Process (Optional Test App) using this command "g++ -o example.exe example.cpp"

    This creates a dummy program that stays alive, making it an ideal test target for DLL injection.

---------------------------------------------------------------------------------------------------------------
---------------------------------------------------------------------------------------------------------------
🚀 How to Use
---------------------------------------------------------------------------------------------------------------

Step 1: Run the Target Program

Open a terminal or double-click the compiled target app: example.exe

You will see:
    Example target process is running.
    PID: 1234
    Waiting for DLL injection...

🔍 Note down the displayed PID (e.g., 1234). You will use it in the next step.


Step 2: Run the Injector

Open a new terminal window (or tab) and run the injector: Local_Dll_injector.exe

You will see: 
    Enter the PID of the target process: 💡 Paste the PID from Step 1 (e.g., 1234) and press Enter.

If successful, you’ll see:[+] DLL injected successfully.
A message box will also appear in the target process saying: DLL Injected Successfully!

🎉 That means your DLL was successfully injected into the target!

---------------------------------------------------------------------------------------------------------------




