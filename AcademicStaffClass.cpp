#include "AcademicStaffClass.h"

void importstudent(ifstream& f, stu* student)
{
    stu* cur = nullptr;
    while (!f.eof())
    {
        if (student == nullptr)
        {
            student = new stu;
            f >> student->No
                >> student->ID;
            f.get(student->fullname, 99);
            f.ignore();
            f.get(student->gender, 6);
            f.ignore();
            f >> student->year
                >> student->month
                >> student->day;
            f.get(student->clas, 10);
            f.ignore();
            cur = student->pNext;
            cur = nullptr;
        }
        else
        {
            cur = new stu;
            f >> cur->No
                >> cur->ID;
            f.get(student->fullname, 99);
            f.ignore();
            f.get(cur->gender, 6);
            f.ignore();
            f >> cur->year
                >> cur->month
                >> cur->day;
            f.get(student->clas, 10);
            f.ignore();
            cur = cur->pNext;
            cur = nullptr;
        }
    }
}
void savedata(stu* student, ofstream& f)
{
    while (student != nullptr)
    {
        f << student->No
            << student->ID;
        f << student->fullname;
        f << student->gender;
        f << student->year
            << student->month
            << student->day;
        f << student->clas;
        student = student->pNext;
    }
}
void changeclass(stu*& student, ofstream& f, char name[])
{
    while (student->pNext != nullptr)
    {
        if (strcmp(student->fullname, name) == 0)
        {
            char check[9], classB[9];
            cout << student->fullname << "ID:" << student->ID;
            cout << "Is this the right student: ";
            cin.get(check, 9);
            cin.ignore();
            if (check == "no")
                return;
            cout << "This student is currently in class" << student->clas
                << "\nMove to class?";
            cin.get(student->clas, 10);
            cin.ignore();
            savedata(student, f);
        }
        student = student->pNext;
    }
    savedata(student, f);
}

void editstudent(stu* student, ofstream& f, char name[])
{
    while (student != nullptr)
    {
        if (strcmp(student->fullname, name) == 0)
        {
            cout << "Please re_enter student information: \n"
                << "Student full name: ";
            cin.get(student->fullname, 99);
            cin.ignore();
            cout << "Student's ID:";
            cin >> student->ID;
            cout << "Student's day of birth:\n DD MM YYYY:";
            cin >> student->day >> student->month >> student->year;
            cout << "Student's gender (Male/ Female): ";
            cin.get(student->gender, 6);
            cin.ignore();
            cout << "Student's class: ";
            cin.get(student->clas, 10);
            cin.ignore();
            savedata(student, f);
            return;
        }
        student = student->pNext;
    }
    savedata(student, f);
}
void Int_to_Char(int n, char a[])
{
    int len = strlen(a);
    while (len > 0)
    {
        int temp;
        temp = n % 10;
        n = n / 10;
        a[len] = temp;
        --len;
    }
}
void AddAStudent(stu*& student, ofstream& f)
{
    int choice;
    cout << "Do you want to enrole into any class: (yes = 1, no = 0) ";
    cin >> choice;
    if (choice == 1)
    {
        cout << "Student full name: ";
        cin.get(student->fullname, 99);
        cin.ignore();
        cout << "Student's ID: ";
        cin >> student->ID;
        cout << "Student's day of birth:\n DD MM YYYY: ";
        cin >> student->day >> student->month >> student->year;
        cout << "Student's gender (Male/ Female): ";
        cin.get(student->gender, 6);
        cin.ignore();
        cout << "Student's class: ";
        cin.get(student->clas, 10);
        cin.ignore();
        Int_to_Char(student->ID, student->username);
        int password = student->year * 10000 + student->month * 100 + student->day;
        Int_to_Char(password, student->password);
        cout << "Your username is: " << student->username << "\nYour password is: " << student->password;
        cout << "\nYou should change your password!!!";
        savedata(student, f);
    }
    savedata(student, f);
}
void RemoveStudent(stu*& student, ofstream& f)
{
    int choice;
    cout << "Delete any student ? (yes = 1, no = 0) ";
    cin >> choice;
    if (choice == 1)
    {
        int ID;
        cout << "Enter the student's ID: ";
        cin >> ID;
        while (student != nullptr)
        {
            if (student->ID == ID)
            {
                delete student;
                savedata(student, f);
                return;
            }
            student = student->pNext;
        }
    }
}
void viewlistofclass()
{
    ifstream classes;
    classes.open("Class.txt");
    if (!classes.is_open())
        cout << "Can not open file!";
    else
    {
        int n;
        classes >> n;
        char a[8];
        for (int i = 0; i < n; i++)
        {
            classes.get(a, 9);
            classes.get();
            cout << a;
        }
    }
    classes.close();
}
void viewlistofstudent(stu* student)
{
    int i = 0;
    while (student != nullptr)
    {
        i++;
        cout << "\nNo." << i << " Name: " << student->fullname << "\t ID: " << student->ID;
    }
}
