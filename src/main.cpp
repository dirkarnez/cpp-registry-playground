#define  _WIN32_WINNT  0x0600
#include <Windows.h>

#define HKEY_CURRENT_USER_LOCAL_SETTINGS ((HKEY) (ULONG_PTR)((LONG)0x80000007))
#include "WinReg.hpp"   // Module to test

#include <exception>
#include <iostream>
#include <string>
#include <optional>
#include <vector>
#include <algorithm>    // std::copy_if, std::distance

using std::endl;
using std::optional;
using std::pair;
using std::string;
using std::vector;
using std::wcout;
using std::wstring;

using winreg::RegKey;
using winreg::RegException;

void Test()
{
    wcout << "\n *** Testing Common RegKey Methods *** \n\n";

    const wstring testSubKey = L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\ProfileList";
    RegKey key{ HKEY_LOCAL_MACHINE, testSubKey, KEY_READ };

    vector<wstring> subKeyNames = key.EnumSubKeys();
	vector<wstring> filteredSubKeyNames;

	std::copy_if (subKeyNames.begin(), 
		subKeyNames.end(), 
		std::back_inserter(filteredSubKeyNames), 
		[](wstring i){
			return i.size() > 8;
		}
	);

    wcout << L"Filtered subkeys:" << endl;
    for (const auto& s : filteredSubKeyNames)
    {
		wstring newKey;
		newKey
		.append(testSubKey)
		.append(L"\\")
		.append(s);
		
		RegKey subkey{ HKEY_LOCAL_MACHINE, newKey, KEY_READ };

        wcout << L"  [" << subkey.GetStringValue(L"ProfileImagePath") << L"]" << endl;
    }
    wcout << L'\n';
}

int main()
{
    const int kExitOk = 0;
    const int kExitError = 1;

    try
    {
        wcout << L"=========================================\n";
        wcout << L"*** Testing Giovanni Dicanio's WinReg ***\n";
        wcout << L"=========================================\n\n";

        Test();

        wcout << L"All right!! :)" << endl;

		string str;
		getline(std::cin, str);
    }
    catch (const RegException& e)
    {
        wcout << L"\n*** Registry Exception: " << e.what();
        wcout << L"\n*** [Windows API error code = " << e.code() << L"]\n\n";
        return kExitError;
    }
    catch (const std::exception& e)
    {
        wcout << L"\n*** ERROR: " << e.what() << L'\n';
        return kExitError;
    }

    std::cin.get();
    return kExitOk;
}