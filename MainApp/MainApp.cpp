//*********************************************************
//
// Copyright (c) Microsoft. All rights reserved.
// THIS CODE IS PROVIDED *AS IS* WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING ANY
// IMPLIED WARRANTIES OF FITNESS FOR A PARTICULAR
// PURPOSE, MERCHANTABILITY, OR NON-INFRINGEMENT.
//
//*********************************************************


#include <iostream>
#include <conio.h>
#include <Shlwapi.h>
#pragma comment(lib, "shlwapi.lib")

HRESULT LaunchApp(const std::wstring& path) 
{
    // Get working directory from executable path.    
    WCHAR szDirectory[MAX_PATH];
    wcscpy_s(szDirectory, path.c_str());
    PathRemoveFileSpec(szDirectory);

    SHELLEXECUTEINFO info;
    ZeroMemory(&info, sizeof(info));
    info.cbSize = sizeof(info);
    info.lpVerb = L"open";
    info.fMask = SEE_MASK_DEFAULT;
    info.lpFile = path.c_str();
    info.lpParameters = NULL;
    info.lpDirectory = szDirectory;
    info.nShow = SW_SHOW;
    ShellExecuteEx(&info);
    return GetLastError();
}

void GetAppPath(std::wstring& path)
{
    wchar_t dest[MAX_PATH];
    DWORD length = GetModuleFileName(NULL, dest, MAX_PATH);
    PathRemoveFileSpec(dest);
    path = dest;
}

int main()
{
    std::cout << "Main App!" << std::endl;
    std::wstring path;
    GetAppPath(path);
    path.append(L"\\..\\HelperApp\\HelperApp.exe");
    std::wcout << L"Launching Helper App " << path << std::endl;
    HRESULT h = LaunchApp(path);
    std::cout << "Press any key to exit...\n";
    auto c = _getch();
}
