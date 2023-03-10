#include <iostream>
#include <windows.h>
#include <string>

using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");

    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(STARTUPINFO));
    si.cb = sizeof(STARTUPINFO);

    string path = "C:\\Users\\artem\\OneDrive\\Documents\\mdk\\win api\\child\\child\\x64\\Debug\\child.exe ";

    string args;
    cout << "Введите аргументы -> ";
    getline(cin, args);

    path = path + " " + args;

    char process[MAX_PATH];

    strcpy_s(process, path.c_str());

    BOOL isStart = CreateProcess(NULL, process, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);

    CloseHandle(pi.hThread);
    CloseHandle(pi.hProcess);
}