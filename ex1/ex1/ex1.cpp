//Гумеров, Крюков, Челомбитько

#include <iostream>
#include <windows.h>

using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");

    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(STARTUPINFO));
    si.cb = sizeof(STARTUPINFO);

    while (true) {
        cout << "Выберите программу:" << endl;
        cout << "1 - Notepad" << endl;
        cout << "2 - Calc" << endl;
        cout << "3 - Cmd" << endl;
        cout << "4 - Своя программа" << endl;
        cout << "5 - Выход" << endl;

        int choose = 0;
        cin >> choose;

        char process[MAX_PATH];

        if (choose == 1)
        {
            strcpy_s(process, "Notepad.exe");
        }
        else if (choose == 2)
        {
            strcpy_s(process, "Calc.exe");
        }
        else if (choose == 3)
        {
            strcpy_s(process, "Cmd.exe");
        }
        else if (choose == 4)
        {
            cout << "Введите путь -> ";
            cin.ignore();
            cin.getline(process, MAX_PATH);
        }
        else if (choose == 5)
        {
            return false;
        }
        else
        {
            cout << "Введена неверная команда!";
        }


        if (!CreateProcess(
            NULL,
            process,
            NULL,
            NULL,
            FALSE,
            0,
            NULL,
            NULL,
            &si,
            &pi
        ))
        {
            cout << "" << endl
                << "" << endl;
            return 0;
        }

        CloseHandle(pi.hThread);
        CloseHandle(pi.hProcess);
    }

    return 0;
}
