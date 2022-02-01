cpp-registry-playground
=======================
This sample code tries to list all the `%USERPROFILE%` by reading `HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows NT\CurrentVersion\ProfileList` in Windows Registry.

### Notes
- C++17
- `desiredAccess` of type `REGSAM` should be defined when declaring a new `RegKey`