#include "AcademicStaffClass.h"

void staff_2_1() {
    //Import list of classes from file

    //import filepath

    string filepath;

    //inputData(filepath);
    cout << "\n\nPlease enter the CSV file path: ";
    getline(cin, filepath,'\n');
    
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
        if (classList.find(newclassNode->classID, ALL))
        {
            if (!skipAll && !replaceAll)
            {
                int choice;
                cout << "Skip? Skip All? Replace? Repace All?";
                //cin >> something ;
                if (choice == 1)//skip
                {
                    delete newclassNode;
                    continue;
                }
                if (choice == 2)//skipAll
                {
                    skipAll = false;
                    delete newclassNode;
                    continue;
                }
                if (choice == 3)//replace
                {

                }
            }
            //
        }
    else
                newclassNode.pushBack(newStudentNode);
    }


    
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
    //Import list of classes from file

    //import filepath

    string filepath;

    //inputData(filepath);
    cout << "\n\nPlease enter the CSV file path: ";
    getline(cin, filepath, '\n');

    ifstream fin;
    fin.open(filepath);

    if (!fin.is_open())
        EXITCODE(4);

    StudentList studentList;
    StudentNode studentNode;

    if (!studentList.load())
        EXITCODE(6);

    string temp;
    getline(fin, temp, '\n');

    StudentNode* newStudentNode = nullptr;
    
    bool skipAll = false;
    bool replaceAll = false;

    while (getline(fin, temp, ','))
    {
        newStudentNode = new StudentNode;
        getline(fin, temp,',');
        getline(fin, newStudentNode->studentID, ',');
        getline(fin, newStudentNode->studentName, ',');
        getline(fin, temp, ',');
        newStudentNode->DOB.y = 1000 * (temp[0] - '0') + 100 * (temp[1] - '0') + 10 * (temp[2] - '0') + (temp[3] - '0');
        newStudentNode->DOB.m = 10 * (temp[5] - '0') + (temp[6] - '0');
        newStudentNode->DOB.d = 10 * (temp[8] - '0') + (temp[9] - '0');
        getline(fin, newStudentNode->classID);
        if (studentList.find(newStudentNode->studentID, ALL))
        {
            if (!skipAll && !replaceAll)
            {
                int choice;
                cout << "Skip? Skip All? Replace? Repace All?";
                //cin >> something ;
                if (choice==1)//skip
                {
                    delete newStudentNode;
                    continue;
                }
                if (choice == 2)//skipAll
                {
                    skipAll = false;
                    delete newStudentNode;
                    continue;
                }
                if (choice == 3)//replace
                {

                }
            }
            //
        }
        else
            studentList.pushBack(newStudentNode);
    }
    studentList.save();
    cout << "\n\nImport successfully";
    fin.close();
    staffClassMenu();
    return;
}

void staff_5_2();

void staff_5_3();

void staff_5_4();

void staff_5_5();

bool checkStaff_5_1();

bool checkStaff_5_2();

bool checkStaff_5_3();

bool checkStaff_5_4();

bool checkStaff_5_5();
