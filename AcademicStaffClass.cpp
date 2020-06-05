//#include "AcademicStaffClass.h"
////#include "AllRoles.h"
//
//stu* importstudent()
//{
//    ifstream f;
//    f.open("19APCS1-Student.csv");
//    
//    stu* student = nullptr;
//    if (!f.is_open())
//    {
//        cout << "Error";
//        return student;
//    }
//    stu* cur = nullptr;
//    string temp;
//    getline(f, temp, '\n');
//    while(f.good())
//    {
//        if (student == nullptr)
//        {
//            student = new stu;
//            getline(f, student->No, ',');
//            getline(f, student->ID, ',');
//            getline(f, student->fullname, ',');
//            //getline(f, student->gender, ',');
//            getline(f, student->date, ',');
//            getline(f, student->clas);
//            student->pNext = nullptr;
//            cur = student;
//        }
//        else
//        {
//            cur->pNext = new stu;
//
//            cur = cur->pNext;
//            getline(f, cur->No, ',');
//            getline(f, cur->ID, ',');
//            getline(f, cur->fullname, ',');
//            //getline(f, cur->gender, ',');
//            getline(f, cur->date, ',');
//            getline(f, cur->clas);
//            cur->pNext = nullptr;
//        }
//    }
//    f.close();
//    return student;
//}
//void savedata(stu* student, ofstream& f)
//{
//    f << "No,Student ID,Fullname,DoB,Class\n";
//    while (student->pNext != nullptr)
//    {
//        f << student->No << ","
//            << student->ID << ","
//            << student->fullname << ","
//            //<< student->gender << ","
//            << student->date << ","
//            << student->clas << "\n";
//        student = student->pNext;
//    }
//}
//void delete_all(stu*& head) {
//    while (head) {
//        stu* tmp = head->pNext;
//        delete head;
//        head = tmp;
//    }
//}
//
//void changeclass()
//{
//    stu* student = importstudent();
//    stu* head = student;
//    if (student == nullptr)
//        return;
//
//    string  name;
//    cout << "Enter name of the student you want to change class: ";
//    cin.get();
//    getline(cin,  name);
//     
//
//    while (student->pNext != nullptr)
//    {
//        if (student->fullname == name)
//        {
//            string check;
//            cout << student->fullname << "\nID:" << student->ID;
//            cout << "\nIs this the right student: ";
//            getline(cin, check);
//             
//            if (check == "no")
//                return;
//            cout << "This student is currently in class" << student->clas
//                << "\nMove to class?";
//            getline(cin, student->clas);
//             
//            ofstream f;
//            f.open("19APCS1-Student.csv");
//            savedata(head, f);
//            f.close();
//        }
//        student = student->pNext;
//    }
//    delete student;
//}
//
//void editstudent()
//{
//
//    stu* student = importstudent();
//    if (student == nullptr)
//        return;
//    stu* head = student;
//
//    string  name;
//    cout << "Enter name of the student you want to edit information: ";
//    cin.get();
//    getline(cin, name);
//     
//
//    while (student != nullptr)
//    {
//        if (student->fullname == name)
//        {
//            string check;
//            cout << student->fullname << "\nID:" << student->ID;
//            cout << "\nIs this the right student: ";
//            getline(cin, check);
//
//            if (check == "no")
//                return;
//
//            cout << "Please re_enter student information: \n"
//                << "Student full name: ";
//            getline(cin,  student->fullname);
//             
//            cout << "Student's ID:";
//            getline(cin, student->ID);
//            cout << "Student's day of birth:\n DD/MM/YYYY:";
//            getline(cin, student->date);
//            cout << "Student's gender (Male/ Female): ";
//            getline(cin,  student->gender);
//             
//            cout << "Student's class: ";
//            getline(cin,  student->clas);
//            
//            cout << "Your password has been reset to default !!!";
//            //getHashedPassword(defaultPassword);
//            ofstream f;
//            f.open("19APCS1-Student.csv");
//            savedata(head, f);
//            f.close();
//            return;
//        }
//        student = student->pNext;
//    }
//
//
//    delete student;
//}
//string removeSpecialCharacter(string s)
//{
//    for (int i = 0; i < s.size(); i++) 
//    {
//        if (s[i] < 'A' || s[i] > 'Z' && s[i] < 'a' || s[i] > 'z')
//        { 
//            s.erase(i, 1);
//            i--;
//        }
//    }
//    return s;
//}
//void AddAStudent()
//{
//    stu* student = importstudent();
//    if (student == nullptr)
//    {
//        cout << "Error!!!\nThe file is empty\n";
//        return;
//    }
//
//    stu* head = student;
//    while (student->pNext != nullptr)
//        student = student->pNext;
//    int choice;
//    cout << "Do you want to enrole into any class: (yes = 1, no = 0) ";
//    cin >> choice;
//    if (choice == 1)
//    {
//        
//        student->pNext = new stu;
//        student = student->pNext;
//        student->pNext = nullptr;
//        cout << "Student full name: ";
//        cin.get();
//        getline(cin, student->fullname, '\n');
//         
//        cout << "Student's ID: ";
//        getline(cin, student->ID, '\n');
//        cout << "Student's day of birth:\n DD/MM/YYYY:";
//        getline(cin, student->date, '\n');
//        cout << "Student's gender (Male/ Female): ";
//        getline(cin,  student->gender, '\n');
//         
//        cout << "Student's class: ";
//        getline(cin,  student->clas);
//         
//        student->username = student->ID;
//        student->password = student->date;
//        student->password = removeSpecialCharacter(student->password);
//        cout << "Your username is: " << student->username << "\nYour password is: " << student->password;
//        cout << "\nYou should change your password to protect your account !!!\n";
//        ofstream f;
//        f.open("19APCS1-Student.csv");
//        savedata(head, f);
//        f.close();
//
//    }
//    delete student;
//}
//void RemoveStudent()
//{
//    
//
//    stu* student = importstudent();
//    if (student == nullptr)
//        return;
//
//    stu* head = student;
//
//    int choice;
//    cout << "Do you want to remove any student : (yes = 1, no = 0) ";
//    cin >> choice;
//    if (choice == 1)
//    {
//        string ID;
//        cout << "Enter the student's ID: ";
//        getline(cin, student->ID);
//        while (student != nullptr)
//        {
//            if (student->ID == ID)
//            {
//                string check;
//                cout << student->fullname << "\nID:" << student->ID;
//                cout << "\nIs this the right student: ";
//                getline(cin, check);
//
//                if (check == "no")
//                    return;
//
//                delete student;
//                ofstream f;
//                f.open("19APCS1-Student.csv");
//                savedata(head, f);
//                f.close();
//                return;
//            }
//            student = student->pNext;
//        }
//    }
//    delete student;
//}
//void viewlistofclass()
//{
//    ifstream classes;
//    classes.open("Class.txt");
//    if (!classes.is_open())
//        cout << "Can not open file!";
//    else
//    {
//        int n;
//        classes >> n;
//        string a;
//        for (int i = 0; i < n; i++)
//        {
//            getline(cin, a);
//            cout << a;
//        }
//    }
//    classes.close();
//}
//void viewlistofstudent()
//{
//    stu* student = importstudent();
//    if (student == nullptr)
//    {
//        cout << "Error!!!\nThe list is empty\n";
//        return;
//    }
//    while (student->pNext != nullptr)
//    {
//        cout << "\nNo." << student->No << " Name: " << student->fullname << "\t ID: " << student->ID << "\t Class: " << student->clas << "\t DoB: " << student->date;
//        student = student->pNext;
//    }
//    cout << endl;
//    
//    delete student;
//}
//
//
//
