#include "AcademicStaffClass.h"

void staff_2_1() {
    //Import list of classes from file

    //import classID

    string filepath;

    //inputData(filepath);
    cout << "\n\nPlease enter the CSV file path: ";
    getline(cin, filepath, '\n');

    ifstream fin;
    fin.open(filepath);

    if (!fin.is_open())
        EXITCODE(4);

    //loadCSV
    ClassList classList;
    ClassNode classNode;

    if (!classList.load())
        EXITCODE(6);
    string temp;
    getline(fin, temp, '\n');

    ClassNode* newclassNode = new ClassNode;

    bool skipAll = false;
    bool replaceAll = false;

    while (getline(fin, temp, ','))
    {
        getline(fin, temp, ',');
        getline(fin, newclassNode->classID);

        ClassNode* dupp;

        if (classList.find(newclassNode->classID, ALL))
        {
            if (!skipAll && !replaceAll)
            {
                string ID;
                int choice = 0;
                char keyPress;

                cout << "\n\nThe student with ID '" << ID << "' has already added.\n";
                cout << "[1 + enter] Skip.\n";
                cout << "[2 + enter] Replace.\n";
                cout << "[3 + enter] Skip all.\n";
                cout << "[4 + enter] Replace all.\n";

                while (choice == 0) {
                    fflush(stdin);
                    keyPress = cin.get();
                    fflush(stdin);

                    switch (keyPress) {
                    case '1':
                        choice = SKIP;
                        delete newclassNode;
                        break;
                    case '2':
                        choice = REPLACE;
                       
                        dupp = classList.find(classNode.classID, ALL);
                        dupp->active = 1;
                        //dupp->DOB = newStudentNode->DOB;
                        //dupp->Next = newStudentNode->Next;
                        //dupp->studentName = newStudentNode->studentName;
                        dupp->classID = newclassNode->classID;
                        break;
                    case '3':
                        choice = SKIP_ALL;
                        skipAll = true;
                        delete newclassNode;
                        break;
                    case '4':
                        choice = REPLACE_ALL;
                        replaceAll = true;
                        dupp = classList.find(newclassNode->classID, ALL);
                        dupp->active = 1;
                        //dupp->DOB = newStudentNode->DOB;
                        //dupp->Next = newStudentNode->Next;
                        //dupp->studentName = newStudentNode->studentName;
                        dupp->classID = newclassNode->classID;
                        break;
                    default:
                        choice = 0;
                    }

                }
                if (skipAll)
                    delete newclassNode;
                if (replaceAll)
                {
                    dupp = classList.find(newclassNode->classID, ALL);
                    dupp->active = 1;
                    //dupp->DOB = newStudentNode->DOB;
                    //dupp->Next = newStudentNode->Next;
                    //dupp->studentName = newStudentNode->studentName;
                    dupp->classID = newclassNode->classID;
                }
            }
            else
                classList.pushBack(newclassNode);
        }



    }
    classList.save();
}

void staff_2_2() {
    //Create a new class

    //Input nothing
    ClassList classList;
    SemesterList semeList;
    if (!semeList.load() || !classList.load())
        EXITCODE(6);
    //Input classID not exist in class list
    string newClass, newSeme;
    cout << "\n\nEnter Semester: ";
    getline(cin, newSeme, '\n');
    cout << "\n\n Enter the new class ID: ";
    getline(cin, newClass, '\n');
    
    if (!classList.find(newClass, ACTIVE))
        EXITCODE(6);
    //pushBack --> save to class list
    ClassNode* newClassNode = new ClassNode;
    newClassNode->classID = newClass;
    classList.pushBack(newClassNode);


    //create [semesterID]-classID-course.txt with 0 course
    ofstream fout;
    fout.open(semeList.Head->semesterID + "classID-course.txt");
    fout << "0";
    fout.close();
    staffClassMenu();
    return;
}

void staff_2_3() {
    //Update a specific class

    //Input oldClass which is active
    string semeID;
    cout << "\n\nEnter semester's ID: ";
    getline(cin, semeID, '\n');
    SemesterList semeList;
    if (!semeList.load())
        EXITCODE(6);

    ClassList classlist;
    if (!classlist.load())
        EXITCODE(6);

    string oldClass;
    getline(cin, oldClass, '\n');
    if (!classlist.find(oldClass, ACTIVE))
        EXITCODE(6);
    //Input newClassID which does not exist in class list
    string newClass;
    getline(cin, newClass, '\n');
    if (classlist.find(newClass, ACTIVE))
        EXITCODE(6);
    //Update oldClassID to newClassID
    ClassNode* newClassNode = new ClassNode;
    newClassNode = classlist.find(oldClass, ACTIVE);
    classlist.find(oldClass, ACTIVE)->active = 0;
    classlist.pushBack(newClassNode);
    classlist.save();
    //copy all files [semesterID]-newClassID-course.txt to [semesterID]-newClassID-course.txt
    CourseList courseList;
    if (!courseList.load(semeID, oldClass))
        EXITCODE(6);
    courseList.save(semeID, newClass);
    //each file [semesterID]-newClassID-course.txt, copy all files [semesterID]-newClassID-[courseID]-student.txt to [semesterID]-newClassID-[courseID]-student.txt

    //Ask for help

    //EX:
//    courseList.load(semesterID, oldClassID);
//    courseList.save(semesterID, newClassID);

    staffClassMenu();
    return;
}

void staff_2_4() {
    //Remove a specific class

    //Input classID which is active
    ClassList classlist;
    if (!classlist.load())
        EXITCODE(6);

    string oldClass;
    getline(cin, oldClass, '\n');
    if (!classlist.find(oldClass, ACTIVE))
        EXITCODE(6);
    //remove classID: active -> 0
    classlist.find(oldClass, ACTIVE)->active = 0;
    cout << "Successfully deleted class";
    staffClassMenu();
    return;
}

void staff_2_5() {
    //View list of classes

    //Input nothing

    //View list of active classes
    ClassList classList;
    if (!classList.load())
        EXITCODE(6);
    ClassNode* cur;
    cur = classList.Head;
    while (cur != nullptr)
    {
        cur->classID;
        cur = cur->Next;
    }
}

bool checkStaff_2_1() {
    return false;
}

bool checkStaff_2_2() {
    return false;
}

bool checkStaff_2_3() {
    return false;
}

bool checkStaff_2_4() {
    return false;
}

bool checkStaff_2_5() {
    return false;
}

void staff_5_1()
{
    //Import list of students from file

    //input classID

    string classID;

    cout << "\n\nClass ID: ";
    getline(cin, classID, '\n');

    normalize(classID);

    ifstream fin;
    fin.open(classID + "-student.csv");

    if (!fin.is_open())
        EXITCODE(4);

    StudentList studentList;

    ClassStudentList classStudentList;

    if (!studentList.load())
        EXITCODE(6);

    if (!classStudentList.load(classID))
        EXITCODE(6);

    string temp;
    getline(fin, temp, '\n');

    StudentNode* newStudentNode = nullptr;
    ClassStudentNode* newClassStudentNode = nullptr;

    bool skipAll = false;
    bool replaceAll = false;

    while (getline(fin, temp, ','))
    {
        newStudentNode = new StudentNode;
        getline(fin, temp, ',');
        getline(fin, newStudentNode->studentID, ',');
        getline(fin, newStudentNode->studentName, ',');
        getline(fin, temp, ',');
        newStudentNode->DOB.y = 1000 * (temp[0] - '0') + 100 * (temp[1] - '0') + 10 * (temp[2] - '0') + (temp[3] - '0');
        newStudentNode->DOB.m = 10 * (temp[5] - '0') + (temp[6] - '0');
        newStudentNode->DOB.d = 10 * (temp[8] - '0') + (temp[9] - '0');
        getline(fin, newStudentNode->classID);
        
        newClassStudentNode->studentID = newStudentNode->studentID;
        
        StudentNode* dupp;
        string pw;

        if (studentList.find(newStudentNode->studentID, ALL))
        {
            if (!skipAll && !replaceAll)
            {
                string ID;
                int choice = 0;
                char keyPress;

                cout << "\n\nThe student with ID '" << ID << "' has already added.\n";
                cout << "[1 + enter] Skip.\n";
                cout << "[2 + enter] Replace.\n";
                cout << "[3 + enter] Skip all.\n";
                cout << "[4 + enter] Replace all.\n";

                while (choice == 0) {
                    fflush(stdin);
                    keyPress = cin.get();
                    fflush(stdin);

                    switch (keyPress) {
                    case '1':
                        choice = SKIP;
                        delete newStudentNode;
                        break;
                    case '2':
                        choice = REPLACE;
                        dupp = studentList.find(newStudentNode->studentID, ALL);
                        dupp->active = 1;
                        dupp->DOB = newStudentNode->DOB;
                        //dupp->Next = newStudentNode->Next;
                        pw = to_string(dupp->DOB.y * 10000 + dupp->DOB.m * 100 + dupp->DOB.d);
                        dupp->password = getHashedPassword(pw);
                        dupp->studentName = newStudentNode->studentName;
                        dupp->classID = newStudentNode->classID;
                        break;
                    case '3':
                        choice = SKIP_ALL;
                        skipAll = true;
                        delete newStudentNode;
                        break;
                    case '4':
                        choice = REPLACE_ALL;
                        replaceAll = true;
                        dupp = studentList.find(newStudentNode->studentID, ALL);
                        dupp->active = 1;
                        dupp->DOB = newStudentNode->DOB;
                        //dupp->Next = newStudentNode->Next;
                        pw = to_string(dupp->DOB.y * 10000 + dupp->DOB.m * 100 + dupp->DOB.d);
                        dupp->password = getHashedPassword(pw);
                        dupp->studentName = newStudentNode->studentName;
                        dupp->classID = newStudentNode->classID;
                        break;
                    default:
                        choice = 0;
                    }

                }
                if (skipAll)
                    delete newStudentNode;
                if (replaceAll)
                {
                    dupp = studentList.find(newStudentNode->studentID, ALL);
                    dupp->active = 1;
                    dupp->DOB = newStudentNode->DOB;
                    //dupp->Next = newStudentNode->Next;
                    pw = to_string(dupp->DOB.y * 10000 + dupp->DOB.m * 100 + dupp->DOB.d);
                    dupp->password = getHashedPassword(pw);
                    dupp->studentName = newStudentNode->studentName;
                    dupp->classID = newStudentNode->classID;
                }
            }
            else
            {
                studentList.pushBack(newStudentNode);
                classStudentList.pushBack(newClassStudentNode);
            }
        }
        studentList.save();
        classStudentList.save(classID);

        cout << "\n\nImport successfully";
        cout << "Data saved to student.txt and " << classID << "-student.txt";
        fin.close();
        staffStudentMenu();
        return;
    }
}

void staff_5_2()
{
    //Create a new student
    string classID;

    cout << "\n\nClass ID: ";
    getline(cin, classID, '\n');

    normalize(classID);

    StudentList studentList;

    ClassStudentList classStudentList;

    if (!studentList.load())
        EXITCODE(6);

    if (!classStudentList.load(classID))
        EXITCODE(6);

    StudentNode* newStudentNode = nullptr;
    ClassStudentNode* newClassStudentNode = nullptr;

    string temp;

    cout << "Student's ID: ";
    getline(cin, newStudentNode->studentID, '\n');
    cout << "Student's Full Name: ";
    getline(cin, newStudentNode->studentName, '\n');

    cout << "Student's Date of Birth:\n Date: ";
    getline(cin, temp, '\n');
    newStudentNode->DOB.d = stoi(temp);
    cout << "\nMonth: ";
    getline(cin, temp, '\n');
    newStudentNode->DOB.m = stoi(temp);
    cout << "\nYear: ";
    getline(cin, temp, '\n');
    newStudentNode->DOB.y = stoi(temp);

    cout <<"Enter "
}

void staff_5_3()
{
    //Update a specific student
}

void staff_5_4()
{
    //Remove a specific student
}

void staff_5_5()
{
    //View list of students of a class
}

bool checkStaff_5_1();

bool checkStaff_5_2();

bool checkStaff_5_3();

bool checkStaff_5_4();

bool checkStaff_5_5();
