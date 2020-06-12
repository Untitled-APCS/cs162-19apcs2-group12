#include "AcademicStaffClass.h"

void staff_2_1() {
    //Import list of classes from file

    //import classID

    //string filepath;

    //inputData(filepath);
    string* s = new string[1]{ "" };
    fPtr* p = new fPtr[1]{ inputPathClassListCSV };
    inputData(s, p, 1, 0, checkStaff_2_1);
    if (s[0].length() == 0)
    {
        staffClassMenu();
        delete[]s;
        delete[]p;
        return;
    }


    string
        filepath = s[0];
    //cout << "\n\nPlease enter the CSV file path: ";
    //getline(cin, classID, '\n');
   // normalize(filepath);
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

    ClassNode* newclassNode;

    bool skipAll = false;
    bool replaceAll = false;

    while (getline(fin, temp, ','))
    {
        newclassNode = new ClassNode;
        //getline(fin, temp, ',');
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
                {
                    delete newclassNode;
                    continue;
                }

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

        }

        else
        {
            newclassNode->active = 1;
            classList.pushBack(newclassNode);
        }
    }
    classList.save();

    fin.close();
    cout << "Successfully import class [ENTER]";
    fflush(stdin);
    cin.get();
    fflush(stdin);
    staffClassMenu();
    delete[]s;
    delete[]p;
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

    if (classList.find(newClass, ACTIVE))
    {
        cout << "\nClass has already existed, you may NOT want to new one!!!\n";
        EXITCODE(6);
    }
    //pushBack --> save to class list
    ClassNode* newClassNode = new ClassNode;
    newClassNode->classID = newClass;
    newClassNode->active = 1;
    classList.pushBack(newClassNode);
    classList.save();

    //create [semesterID]-classID-course.txt with 0 course
    // + ALL semester

    SemesterList seme;
    seme.load();
    SemesterNode* cur;
    cur = seme.Head;
    while (cur != nullptr)
    {
        ofstream fout;
        fout.open(getLocation() + "/data/" + cur->semesterID + "-" + newClass + "-course.txt");
        fout << "0";
        fout.close();
        cur = cur->Next;
    }


    cout << "Successfully create new class [ENTER]";
    fflush(stdin);
    cin.get();
    fflush(stdin);
    staffClassMenu();
    return;
}

void staff_2_3() {
    //Update a specific class

    //Input oldClass which is active
    string* s = new string[1]{ "" };
    fPtr* p = new fPtr[1]{ inputClass };
    inputData(s, p, 1, 0, checkStaff_2_3);
    if (s[0].length() == 0)
    {
        staffClassMenu();
        delete[]s;
        delete[]p;
        return;
    }
    string
        oldClass = s[0];

    SemesterList semeList;
    if (!semeList.load())
        EXITCODE(6);

    ClassList classlist;
    if (!classlist.load())
        EXITCODE(6);

    ClassNode* oldClassNode = classlist.find(oldClass, ACTIVE);
    if (oldClassNode->active == 0)
        EXITCODE(6);
    //Input newClassID which does not exist in class list
    string newClass;

    cout << "\n\nEnter new class ID";
    cin.ignore();
    getline(cin, newClass, '\n');
    normalize(newClass);
    if (classlist.find(newClass, ACTIVE))
        EXITCODE(6);
    if (classlist.find(newClass, ALL)) {

        //set the oldclass to inactive and re_active the existing class 

        classlist.find(newClass, ALL)->active = 1;
        classlist.find(oldClass, ACTIVE)->active = 0;
        classlist.save();
    }
    else
    {
        //Update oldClassID to newClassID
        ClassNode* newClassNode = new ClassNode;
        //newClassNode = oldClassNode;
        newClassNode->classID = newClass;
        newClassNode->active = 1;

        //oldClassNode->active = 0;
        //classlist.pushBack(newClassNode);
        //classlist.save();
        //copy all files [semesterID]-newClassID-course.txt to [semesterID]-newClassID-course.txt
        CourseList courseList;

        SemesterNode* cur_seme = semeList.Head;
        if (courseList.load(cur_seme->semesterID, oldClass) == 0)
            EXITCODE(6);
        courseList.save(cur_seme->semesterID, newClass);

        oldClassNode->active = 0;
        classlist.pushBack(newClassNode);
        classlist.save();
        //each file [semesterID]-newClassID-course.txt, copy all files [semesterID]-olClassID-[courseID]-student.txt to [semesterID]-newClassID-[courseID]-student.txt
        CourseStudentList courseStudentList;
        CourseNode* cur = courseList.Head;
        while (cur != nullptr) {
            cout << cur->courseID;
            if (!courseStudentList.load(cur_seme->semesterID, oldClass, cur->courseID))
                EXITCODE(6);
            courseStudentList.save(cur_seme->semesterID, newClass, cur->courseID);
            courseStudentList.destroy();
            cur = cur->Next;
        }
    }
    //EX:
//    courseList.load(semesterID, oldClassID);
//    courseList.save(semesterID, newClassID);

    cout << "Successfully update class [ENTER]";
    fflush(stdin);
    cin.get();
    fflush(stdin);
    staffClassMenu();
    delete[]s;
    delete[]p;
    return;
}

void staff_2_4() {
    //Remove a specific class

    //Input classID which is active
    ClassList classlist;
    if (!classlist.load())
        EXITCODE(6);
    string* s = new string[1]{ "" };
    fPtr* p = new fPtr[1]{ inputClass };
    inputData(s, p, 1, 0, checkStaff_2_4);
    if (s[0].length() == 0)
    {
        staffClassMenu();
        delete[]s;
        delete[]p;
        return;
    }
    string
        oldClass = s[0];

    //string oldClass;
    //getline(cin, oldClass, '\n');
    if (!classlist.find(oldClass, ACTIVE))
        EXITCODE(6);
    //remove classID: active -> 0
    classlist.find(oldClass, ACTIVE)->active = 0;
    classlist.save();
    cout << "Successfully deleted class [ENTER]";
    fflush(stdin);
    cin.get();
    fflush(stdin);
    staffClassMenu();
    delete[]s;
    delete[]p;
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

    cout << "\n\nList of active class(es): \n\n";
    while (cur != nullptr)
    {
        cout << cur->classID << endl;
        cur = cur->Next;
    }
    cout << "\n\nSuccessfully view list of class(es) [ENTER]";
    fflush(stdin);
    cin.get();
    fflush(stdin);
    staffClassMenu();
    return;
}

bool checkStaff_2_1(string* s, int n) {

    return true;
}

bool checkStaff_2_2(string* s, int n) {
    return true;
}

bool checkStaff_2_3(string* s, int n) {
    ClassList classlist;
    if (!classlist.load())
    {
        cout << "\n\nCan not load list of Classes!!!";
        return false;
    }
    if (!classlist.find(s[0], ACTIVE))
        return false;
    return true;
}

bool checkStaff_2_4(string* s, int n) {
    ClassList classlist;
    classlist.load();
    if (!classlist.find(s[0], ACTIVE))
        return false;
    return true;
}

bool checkStaff_2_5(string* s, int n) {
    return true;
}

void staff_5_1()
{
    //Import list of students from file

    //input classID


    string* s = new string[2]{ "","" };
    fPtr* p = new fPtr[2]{ inputClass,inputPathStudentListCSV };
    inputData(s, p, 2, 0, checkStaff_5_1);
    if (s[0].length() == 0 || s[1].length() == 0)
    {
        staffStudentMenu();
        delete[]s;
        delete[]p;
        return;
    }
    string
        classID = s[0],
        filepath = s[1];
    //string classID;

    //cout << "\n\nClass ID: ";
    //getline(cin, classID, '\n');


    /*string filepath;
    cout << "\n\nfilepath: ";
    getline(cin, filepath, '\n');*/

    //normalize(classID);

    ifstream fin;
    fin.open(filepath);

    if (!fin.is_open())
        EXITCODE(4);

    StudentList studentList;

    ClassStudentList classStudentList;

    if (!studentList.load())
        EXITCODE(6);

    if (!classStudentList.load(classID))
        EXITCODE(6);

    string temp1, temp2, temp;
    getline(fin, temp2, '\n');

    StudentNode* newStudentNode = nullptr;
    ClassStudentNode* newClassStudentNode;

    bool skipAll = false;
    bool replaceAll = false;

    while (fin.good())
    {
        newStudentNode = new StudentNode;
        newClassStudentNode = new ClassStudentNode;
        getline(fin, temp, ',');
        cout << temp << " ";
        if (temp == "") {
            delete newStudentNode;
            delete newClassStudentNode;
            cout << "ok" << endl;
            continue;
        }
        getline(fin, temp, ','); // newStudentNode->studentID
        newStudentNode->studentID = temp;
        cout << temp << " ";
        getline(fin, temp, ','); // name
        newStudentNode->studentName = temp;
        cout << temp << " ";
        getline(fin, temp);
        cout << temp << endl;
        newStudentNode->DOB.y = 1000 * (temp[0] - '0') + 100 * (temp[1] - '0') + 10 * (temp[2] - '0') + (temp[3] - '0');
        newStudentNode->DOB.m = 10 * (temp[5] - '0') + (temp[6] - '0');
        newStudentNode->DOB.d = 10 * (temp[8] - '0') + (temp[9] - '0');
        newStudentNode->classID = classID;

        newClassStudentNode->studentID = newStudentNode->studentID;

        newStudentNode->active = 1;
        newClassStudentNode->active = 1;

        //    StudentNode* dupp;
        //    string pw;
        //    pw = to_string((newStudentNode->DOB.y * 10000 + newStudentNode->DOB.m * 100 + newStudentNode->DOB.d));
        //    newStudentNode->password = getHashedPassword(pw);

        //    if (studentList.find(newStudentNode->studentID, ALL))
        //    {
        //        if (!skipAll && !replaceAll)
        //        {
        //            string ID;
        //            int choice = 0;
        //            char keyPress;

        //            cout << "\n\nThe student with ID '" << ID << "' has already added.\n";
        //            cout << "[1 + enter] Skip.\n";
        //            cout << "[2 + enter] Replace.\n";
        //            cout << "[3 + enter] Skip all.\n";
        //            cout << "[4 + enter] Replace all.\n";

        //            while (choice == 0) {
        //                fflush(stdin);
        //                keyPress = cin.get();
        //                fflush(stdin);

        //                switch (keyPress) {
        //                case '1':
        //                    choice = SKIP;
        //                    delete newStudentNode;
        //                    break;
        //                case '2':
        //                    choice = REPLACE;
        //                    dupp = studentList.find(newStudentNode->studentID, ALL);
        //                    dupp->active = 1;
        //                    dupp->DOB = newStudentNode->DOB;
        //                    //dupp->Next = newStudentNode->Next;
        //                    pw = to_string((dupp->DOB.y * 10000 + dupp->DOB.m * 100 + dupp->DOB.d));
        //                    dupp->password = getHashedPassword(pw);
        //                    dupp->studentName = newStudentNode->studentName;
        //                    dupp->classID = newStudentNode->classID;
        //                    break;
        //                case '3':
        //                    choice = SKIP_ALL;
        //                    skipAll = true;
        //                    delete newStudentNode;
        //                    break;
        //                case '4':
        //                    choice = REPLACE_ALL;
        //                    replaceAll = true;
        //                    dupp = studentList.find(newStudentNode->studentID, ALL);
        //                    dupp->active = 1;
        //                    dupp->DOB = newStudentNode->DOB;
        //                    //dupp->Next = newStudentNode->Next;
        //                    pw = to_string(dupp->DOB.y * 10000 + dupp->DOB.m * 100 + dupp->DOB.d);
        //                    dupp->password = getHashedPassword(pw);
        //                    dupp->studentName = newStudentNode->studentName;
        //                    dupp->classID = newStudentNode->classID;
        //                    break;
        //                default:
        //                    choice = 0;
        //                }

        //            }
        //            if (skipAll)
        //                delete newStudentNode;
        //            if (replaceAll)
        //            {
        //                dupp = studentList.find(newStudentNode->studentID, ALL);
        //                dupp->active = 1;
        //                dupp->DOB = newStudentNode->DOB;
        //                //dupp->Next = newStudentNode->Next;
        //                pw = to_string(dupp->DOB.y * 10000 + dupp->DOB.m * 100 + dupp->DOB.d);
        //                dupp->password = getHashedPassword(pw);
        //                dupp->studentName = newStudentNode->studentName;
        //                dupp->classID = newStudentNode->classID;
        //            }
        //        }

        //    }
        //    else
        //    {
        //        studentList.pushBack(newStudentNode);
        //        classStudentList.pushBack(newClassStudentNode);
        //    }

        //}
        /*studentList.save();
        classStudentList.save(classID);*/
        delete newStudentNode;
        delete newClassStudentNode;
    } // nho xoa
    cout << "\n\nImport successfully";
    cout << "\nData saved to student.txt and " << classID << "-student.txt\n[ENTER]";
    fin.close();

    fflush(stdin);
    cin.get();
    fflush(stdin);
    staffStudentMenu();
    delete[]s;
    delete[]p;
    return;
}

void staff_5_2()
{
    //Create a new student
    string* s = new string[1]{ "" };
    fPtr* p = new fPtr[1]{ inputClass };
    inputData(s, p, 1, 0, checkStaff_5_2);
    if (s[0].length() == 0)
    {
        staffStudentMenu();
        delete[]s;
        delete[]p;
        return;
    }
    string
        classID = s[0];

    /*string classID;

    cout << "\n\nClass ID: ";
    getline(cin, classID, '\n');*/

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
    cin.ignore();
    getline(cin, newStudentNode->studentID, '\n');
    newClassStudentNode->studentID = newStudentNode->studentID;
    cout << "Student's Full Name: ";
    cin.ignore();
    getline(cin, newStudentNode->studentName, '\n');

    cout << "Student's Date of Birth:\n Date: ";
    cin.ignore();
    getline(cin, temp, '\n');
    newStudentNode->DOB.d = stoi(temp);
    cout << "\nMonth: ";
    cin.ignore();
    getline(cin, temp, '\n');
    newStudentNode->DOB.m = stoi(temp);
    cout << "\nYear: ";
    cin.ignore();
    getline(cin, temp, '\n');
    newStudentNode->DOB.y = stoi(temp);
    newStudentNode->classID = classID;

    studentList.pushBack(newStudentNode);
    classStudentList.pushBack(newClassStudentNode);

    studentList.save();
    classStudentList.save(classID);
    cout << "\n\nNew student created. [ENTER]";
    fflush(stdin);
    cin.get();
    fflush(stdin);
    staffStudentMenu();
    delete[]s;
    delete[]p;
    return;
}

void staff_5_3()
{
    //Update a specific student

    string* s = new string[2]{ "","" };
    fPtr* p = new fPtr[2]{ inputClass,inputStudent };
    inputData(s, p, 2, 0, checkStaff_5_3);
    if (s[0].length() == 0 || s[1].length() == 0)
    {
        staffStudentMenu();
        delete[]s;
        delete[]p;
        return;
    }
    string
        classID = s[0],
        oldStudentID = s[1];


    /*string classID;
    cout << "Enter class's ID: ";
    getline(cin, classID, '\n');

    string oldStudentID;
    cout << "\n\nEnter student's ID: ";
    getline(cin, oldStudentID, '\n');*/

    ClassStudentList classStudentList;
    if (!classStudentList.load(classID))
        EXITCODE(6);

    StudentList studentList;
    if (!studentList.load())
        EXITCODE(6);

    if (!studentList.find(oldStudentID, ACTIVE))
        EXITCODE(6);
    if (!classStudentList.find(oldStudentID, ACTIVE))
        EXITCODE(6);

    //update old to new
    StudentNode* newstudent = new StudentNode;
    newstudent = studentList.find(oldStudentID, ACTIVE);
    ClassStudentNode* newclassstudent = new ClassStudentNode;
    newclassstudent = classStudentList.find(oldStudentID, ACTIVE);

    newstudent->active = 1;

    string temp;

    getline(cin, newstudent->studentName, '\n');
    normalizeFullName(newstudent->studentName);
    getline(cin, temp, '\n');
    newstudent->DOB.y = 1000 * (temp[0] - '0') + 100 * (temp[1] - '0') + 10 * (temp[2] - '0') + (temp[3] - '0');
    newstudent->DOB.m = 10 * (temp[5] - '0') + (temp[6] - '0');
    newstudent->DOB.d = 10 * (temp[8] - '0') + (temp[9] - '0');
    getline(cin, newstudent->classID, '\n');
    normalize(newstudent->classID);

    //flag to tell if the class can be changed or not
    bool changeclass = false;
    if (newstudent->classID != classID)
    {
        SemesterList semester;
        semester.load();

        CourseList course;
        course.load(semester.currentSemester, classID);
        if (course.Head != nullptr)
        {
            cout << "You can not change this student class!!!";
            newstudent->classID = classID;
        }
        else
        {
            changeclass = true;
            //inactivate student in the old class
            newclassstudent->active = 0;
            classStudentList.pushBack(newclassstudent);
            classStudentList.save(classID);


            //activete and save student to new class
            ClassStudentList newclassStudentlist;
            newclassstudent->active = 1;
            newclassStudentlist.load(newstudent->classID);
            newclassStudentlist.pushBack(newclassstudent);
            newclassStudentlist.save(newstudent->classID);
        }
    }
    if (!changeclass)
    {
        ClassStudentList newclasslist;
        newclasslist.load(newstudent->classID);
        newclasslist.pushBack(newclassstudent);
    }
    studentList.pushBack(newstudent);
    studentList.save();

    cout << "\n\nUpdate student's information completed [ENTER]";
    fflush(stdin);
    cin.get();
    fflush(stdin);
    staffStudentMenu();
    delete[]s;
    delete[]p;
    return;
}

void staff_5_4()
{
    //Remove a specific student
    //input classID

    string* s = new string[2]{ "","" };
    fPtr* p = new fPtr[2]{ inputClass,inputStudent };
    inputData(s, p, 2, 0, checkStaff_5_3);
    if (s[0].length() == 0 || s[1].length() == 0)
    {
        staffStudentMenu();
        delete[]s;
        delete[]p;
        return;
    }
    string
        classID = s[0],
        studentID = s[1];

    //string classID;
    //cout << "\n\nEnter class ID: ";
    //getline(cin, classID, '\n');
    //normalize(classID);

    ////input student ID
    //string studentID;
    //cout << "\n\nEnter class ID: ";
    //getline(cin, studentID, '\n');
    //normalize(studentID);

    //load and check if the student is in class
    ClassStudentList classStudentList;
    if (!classStudentList.load(classID))
        EXITCODE(6);
    if (classStudentList.find(studentID, ACTIVE) == nullptr)
        EXITCODE(6);

    classStudentList.find(studentID, ACTIVE)->active = 0;

    StudentList studentList;
    if (!studentList.load())
        EXITCODE(6);
    if (studentList.find(studentID, ACTIVE) == nullptr)
        EXITCODE(6);
    StudentNode* node = studentList.find(studentID, ACTIVE);
    //if (node == nullptr)
    //    EXITCODE(6);
    node->active = 0;
    //studentList.find(studentID, ACTIVE)->active = 0;
    classStudentList.save(classID);
    studentList.save();

    cout << endl << studentID << " deleted! [ENTER]";
    fflush(stdin);
    cin.get();
    fflush(stdin);
    staffStudentMenu();
    delete[]s;
    delete[]p;
    return;
}

void staff_5_5()
{
    //View list of students of a class
    //input classID

    string* s = new string[1]{ "" };
    fPtr* p = new fPtr[1]{ inputClass };
    inputData(s, p, 1, 0, checkStaff_5_2);
    if (s[0].length() == 0)
    {
        staffStudentMenu();
        delete[]s;
        delete[]p;
        return;
    }
    string
        classID = s[0];

    /*string classID;
    cout << "\n\nEnter class ID: ";
    getline(cin, classID, '\n');
    normalize(classID);*/

    //load and check if the class is valid
    ClassStudentList classStudentList;
    if (!classStudentList.load(classID))
        EXITCODE(6);
    StudentList studentList;
    if (!studentList.load())
        EXITCODE(6);
    //output student ID

    StudentNode* cur = studentList.Head;

    for (ClassStudentNode* node = classStudentList.Head; node; node = node->Next)
    {
        while (node->studentID != cur->studentID)
            cur = cur->Next;
        cout << "\n\nStudent ID: " << cur->studentID
            << "\nStudent name: " << cur->studentName
            << "\nStudent DOB: (yyyy/mm/dd)" << cur->DOB.y << "/" << cur->DOB.m << "/" << cur->DOB.d
            << "\nClass: " << cur->classID;
        cur = studentList.Head;
    }

    cout << "\nDone view list of class " << classID << "[ENTER]";
    fflush(stdin);
    cin.get();
    fflush(stdin);
    staffStudentMenu();
    delete[]s;
    delete[]p;
    return;
}

bool checkStaff_5_1(string* s, int n) {
    return true;
}

bool checkStaff_5_2(string* s, int n) {
    return true;
}

bool checkStaff_5_3(string* s, int n) {
    return true;
}

bool checkStaff_5_4(string* s, int n) {
    return true;
}

bool checkStaff_5_5(string* s, int n) {
    return true;
}


//=================================================Lecturer===================================

void staff_4_1()
{
    //Import list of students from file

    //input classID


    string* s = new string[1]{ "" };
    fPtr* p = new fPtr[1]{ inputPathLecturerListCSV };
    inputData(s, p, 1, 0, checkStaff_5_1);
    if (s[0].length() == 0)
    {
        staffLecturerMenu();
        delete[]s;
        delete[]p;
        return;
    }
    string
        filepath = s[0];

    ifstream fin;
    fin.open(filepath);

    if (!fin.is_open())
        EXITCODE(4);

    LecturerList lecturerList;

    if (!lecturerList.load())
        EXITCODE(6);


    string temp1, temp2, temp;
    getline(fin, temp2, '\n');

    LecturerNode* newLecturerNode = nullptr;

    bool skipAll = false;
    bool replaceAll = false;

    while (getline(fin, temp1, ','))
    {
        newLecturerNode = new LecturerNode;
        //newClassLecturerNode = new ClassLecturerNode;
        //getline(fin, temp, ',');
        getline(fin, newLecturerNode->lecturerID, ',');
        getline(fin, newLecturerNode->lecturerName, ',');
        getline(fin, newLecturerNode->academicTitle, ',');
        getline(fin, temp);
        if (temp == "0")
            newLecturerNode->gender = false;
        else
            newLecturerNode->gender = true;




        newLecturerNode->active = 1;

        LecturerNode* dupp;
        string pw;
        pw = newLecturerNode->lecturerID;
        newLecturerNode->password = getHashedPassword(pw);

        if (lecturerList.find(newLecturerNode->lecturerID, ALL))
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
                        delete newLecturerNode;
                        break;
                    case '2':
                        choice = REPLACE;
                        dupp = lecturerList.find(newLecturerNode->lecturerID, ALL);
                        dupp->active = 1;
                        dupp->gender = newLecturerNode->gender;
                        dupp->academicTitle = newLecturerNode->academicTitle;
                        //dupp->Next = newLecturerNode->Next;
                        pw = newLecturerNode->lecturerID;
                        dupp->password = getHashedPassword(pw);
                        dupp->lecturerName = newLecturerNode->lecturerName;
                        break;
                    case '3':
                        choice = SKIP_ALL;
                        skipAll = true;
                        delete newLecturerNode;
                        break;
                    case '4':
                        choice = REPLACE_ALL;
                        replaceAll = true;
                        dupp = lecturerList.find(newLecturerNode->lecturerID, ALL);
                        dupp->active = 1;
                        dupp->gender = newLecturerNode->gender;
                        dupp->academicTitle = newLecturerNode->academicTitle;
                        //dupp->Next = newLecturerNode->Next;
                        pw = newLecturerNode->lecturerID;
                        dupp->password = getHashedPassword(pw);
                        dupp->lecturerName = newLecturerNode->lecturerName;
                        break;
                    default:
                        choice = 0;
                    }

                }
                if (skipAll)
                    delete newLecturerNode;
                if (replaceAll)
                {
                    dupp = lecturerList.find(newLecturerNode->lecturerID, ALL);
                    dupp->active = 1;
                    dupp->gender = newLecturerNode->gender;
                    dupp->academicTitle = newLecturerNode->academicTitle;
                    //dupp->Next = newLecturerNode->Next;
                    pw = newLecturerNode->lecturerID;
                    dupp->password = getHashedPassword(pw);
                    dupp->lecturerName = newLecturerNode->lecturerName;
                }
            }

        }
        else
        {
            lecturerList.pushBack(newLecturerNode);
        }

    }
    lecturerList.save();

    cout << "\n\nImport successfully";
    cout << "\nData saved to lecturer.txt  [ENTER]";
    fin.close();

    fflush(stdin);
    cin.get();
    fflush(stdin);
    staffLecturerMenu();
    delete[]s;
    delete[]p;
    return;
}

void staff_4_2() {
    //Create a new lecturer


    /*string classID;

    cout << "\n\nClass ID: ";
    getline(cin, classID, '\n');*/


    LecturerList lecturerList;

    if (!lecturerList.load())
        EXITCODE(6);


    LecturerNode* newLecturerNode = nullptr;

    string temp;

    cout << "Lecturer's ID: ";
    cin.ignore();
    getline(cin, newLecturerNode->lecturerID, '\n');
    cout << "Lecturer's Full Name: ";
    cin.ignore();
    getline(cin, newLecturerNode->lecturerName, '\n');
    cout << "Lecturer's Academic Title: ";
    cin.ignore();
    getline(cin, newLecturerNode->lecturerName, '\n');
    cout << "Lecturer's Gender: (Male=1/Female=0)";
    cin.ignore();
    getline(cin, temp, '\n');
    normalize(temp);
    if (temp == "1")
        newLecturerNode->gender = 1;
    else if (temp == "0")
        newLecturerNode->gender = 0;
    else
    {
        cout << "\nError!!!\nEnter wrong syntax";
        staffLecturerMenu();
        return;
    }

    lecturerList.pushBack(newLecturerNode);

    lecturerList.save();
    cout << "\n\nNew Lecturer created. [ENTER]";
    fflush(stdin);
    cin.get();
    fflush(stdin);
    staffLecturerMenu();
    return;
}
    
    void staff_4_3() {
        //Update a specific lecturer
    
        string* s = new string[1]{"" };
        fPtr* p = new fPtr[1]{ inputLecturer };
        inputData(s, p, 1, 0, checkStaff_4_3);
        if (s[0].length() == 0 )
        {
            staffLecturerMenu();
            delete[]s;
            delete[]p;
            return;
        }
        string
            lecturerID = s[0];
    
    
        /*string classID;
        cout << "Enter class's ID: ";
        getline(cin, classID, '\n');
    
        string oldStudentID;
        cout << "\n\nEnter student's ID: ";
        getline(cin, oldStudentID, '\n');*/
    
        
        LecturerList lecturerList;
        if (!lecturerList.load())
            EXITCODE(6);
    
        if (lecturerList.find(lecturerID, ACTIVE)==nullptr)
            EXITCODE(6);
    
        //update old to new
        LecturerNode* newlecturer = new LecturerNode;
        newlecturer = lecturerList.find(lecturerID, ACTIVE);
    
        newlecturer->active = 1;
    
        string temp;
        cout << "Enter Lecturer's name";
        getline(cin, newlecturer->lecturerName, '\n');
        normalizeFullName(newlecturer->lecturerName);
        cout << "Enter Lecturer's Academic Title: ";
        getline(cin, newlecturer->academicTitle, '\n');
        cout << "Lecturer's Gender: (Male=1/Female=0)";
        cin.ignore();
        getline(cin, temp, '\n');
        normalize(temp);
        if (temp == "1")
            newlecturer->gender = 1;
        else if (temp == "0")
            newlecturer->gender = 0;
        else
        {
            cout << "\nError!!!\nEnter wrong syntax";
            staffLecturerMenu();
            return;
        }
    
        //flag to tell if the class can be changed or not
        lecturerList.save();
    
        cout << "\n\nUpdate Lecturer's information completed [ENTER]";
        fflush(stdin);
        cin.get();
        fflush(stdin);
        staffLecturerMenu();
        delete[]s;
        delete[]p;
        return;
    }
    
    void staff_4_4() {
        //Remove a specific lectuerer
        //input classID
    
        string* s = new string[1]{ "" };
        fPtr* p = new fPtr[1]{ inputLecturer };
        inputData(s, p, 1, 0, checkStaff_4_3);
        if (s[0].length() == 0)
        {
            staffLecturerMenu();
            delete[]s;
            delete[]p;
            return;
        }
        string
            lecturerID = s[0];
    
        //string classID;
        //cout << "\n\nEnter class ID: ";
        //getline(cin, classID, '\n');
        //normalize(classID);
    
        ////input student ID
        //string studentID;
        //cout << "\n\nEnter class ID: ";
        //getline(cin, studentID, '\n');
        //normalize(studentID);
    
        //load and check if the student is in class
    
        LecturerList lecturerList;
        if (!lecturerList.load())
            EXITCODE(6);
        if (lecturerList.find(lecturerID, ACTIVE) == nullptr)
            EXITCODE(6);
        LecturerNode* node = lecturerList.find(lecturerID, ACTIVE);
        //if (node == nullptr)
        //    EXITCODE(6);
        node->active = 0;
        
        lecturerList.save();
    
        cout << endl <<lecturerID << " deleted! [ENTER]";
        fflush(stdin);
        cin.get();
        fflush(stdin);
        staffLecturerMenu();
        delete[]s;
        delete[]p;
        return;
    }
    
    void staff_4_5() {
        //View list of lecturer
       //input classID
    
        LecturerList lecturerList;
        if (!lecturerList.load())
            EXITCODE(6);
        //output student ID
    
        LecturerNode* cur = lecturerList.Head;
    
        while (cur != nullptr)
        {
            cout << cur->lecturerID << endl
                << cur->lecturerName << endl
                << cur->academicTitle << endl;
            cur = cur->Next;
        }

        cout << "\nDone view list of lecturers [ENTER]";
    fflush(stdin);
    cin.get();
    fflush(stdin);
    staffLecturerMenu();
    return;
}

bool checkStaff_4_1(string* s, int n) {
    return true;
}

bool checkStaff_4_2(string* s, int n) {
    return true;
}

bool checkStaff_4_3(string* s, int n) {
    return true;
}

bool checkStaff_4_4(string* s, int n) {
    return true;
}

bool checkStaff_4_5(string* s, int n) {
    return true;
}