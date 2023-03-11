
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <iomanip>
#include <io.h>
#include "AcademyGroup.h"

using namespace std;

void PrintMenu()
{
    char Menu[] = "\tM E N U:\n1.Add student\n2.Delete student\n3.Edit student\n4.Print academy group\n5.Sort list\n6.Search student\n0.Exit\n";
    system("cls");
    cout << Menu;
}

int main()
{
    AcademyGroup obj;

    //obj.Save();
    obj.Load();

    while (true)
    {
        PrintMenu();
        char res = _getch();
        switch (res)
        {
        case '1': obj.AddStudents();         //���������� ��������� � ������;
            break;
        case '2': obj.DeleteStudent();       //�������� �������� �� ������;
            break;
        case '3': obj.EditStudent();         //����������� ������ ��������;
            break;
        case '4': obj.Print();               // ������ ������������� ������;
            break;
        case '5': obj.Sort();                //���������� ������ ���������;
            break;
        case '6': obj.FindStudent();         // ����� �������� �� ��������� ��������;
            break;
        case '0': obj.Save();                // ����� �� ���������.
            cout << "\nThank you!" << endl;
            system("exit");
            return 0;
            break;

        default:

            cout << "\nERROR! Pressed wrong key\n";
            system("pause");
            break;
        }
    }
    return 0;
}

