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
    
    StudentList studentList;
    StudentNode studentNode;

    if (!studentList.load())
        EXITCODE(6);

    string temp;
    getline(fin, temp, '\n');

    while (getline(fin, temp, ','))
    {
        StudentNode* newStudentNode = new StudentNode;
        getline(fin, temp,',');
        getline(fin, newStudentNode->studentID, ',');
        getline(fin, newStudentNode->studentName, ',');
        /*getline(fin, newStudentNode->DOB.y, '-');
        getline(fin, newStudentNode->DOB.m, '-');
        getline(fin, newStudentNode->DOB.d, ',');*/
        getline(fin, newStudentNode->classID);
        studentList.pushBack(newStudentNode);
        delete newStudentNode;
    }
    studentList.save();
    cout << "Import successfully";
    fin.close();
    staffClassMenu();
    return;
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
