#include "AcademicStaffCourse.h"

bool checkSample() {
    return true;
}

void sample() {
    //input semester, class, course
//    string *s = new string[3]{"", "", ""};
//    fPtr *p = new fPtr[3]{inputSemester, inputClass, inputCourse};
//    inputData(s, p, 0, 3, checkStaff_1_1);
//
//    string
//    semesterID = s[0],
//    classID = s[1],
//            courseID = s[2];



//    //Syntax
//    SemesterList semesterList;
//    if (!semesterList.load())
//    EXITCODE(6);
//
//    if (semesterList.find(semester, ALL) == nullptr)
//    EXITCODE(6);
//    inputData(.sdfasdfdsf)
//
//    loadStudentListCSV()
}

void staff_1_1() {
    //Create a new semester
    //Input nothing

    //input semesterID not exist in semester list
    //until getting valid data

    //create new node and pushBack --> save
    ofstream foutput;
    SemesterList semesterList;
    ClassList classList;
    if (!semesterList.load()||!classList.load())
    EXITCODE(6);
    cout << "\n\n";
    SemesterNode* semesterNode = new SemesterNode;
    string* s = new string[1]{ "" };
    //fPtr* p = new fPtr[1]{ inputSemester};
    //inputData(s, p, 1, 0, checkStaff_1_1);

    //INPUT:
    cout << "\n\nCreate a new semester. Please enter the semester ID you want.\n";
    cout << "[` + enter] Back to menu.\n\n";

    bool passed = false;

    while (!passed) {
        cout << "New semester ID: ";

        fflush(stdin);
        getline(cin, s[0]);
        fflush(stdin);

        if (s[0].find('`') != string::npos) {
            staffSemesterMenu();
            return;
        }

        if (semesterList.find(s[0], ALL) == nullptr)
            passed = true;
        else {
            cout << "The semester ID that you typed has been existing. Please enter another one.\n";
        }
    }

    semesterNode->current = 0;
    semesterNode->active = 1;
    semesterNode->semesterID = s[0];
    normalize(semesterNode->semesterID);
    semesterList.pushBack(semesterNode);
    semesterList.save();
    string filename = "";
    while (classList.Head != nullptr)
    {
        if (classList.Head->active == 1) {
            filename = getLocation() +"/data/"+ semesterNode->semesterID + "-" + classList.Head->classID + "-course.txt";
            foutput.open(filename);
            foutput << 0;
            foutput.close();
        }
        classList.Head = classList.Head->Next;
    }
    delete[]s;
    //delete[]p;
    cout << "\n\nCreated successfully! [enter]";
    fflush(stdin);
    cin.get();
    fflush(stdin);
    staffSemesterMenu();
    return;
}

void staff_1_2() {
    //Update a specific semester

    //Initialization
    SemesterList semesterList;
    SemesterNode *semesterNode;
    if (!semesterList.load()) EXITCODE(6)

    ClassList classList;
    ClassNode *classNode;
    if (!classList.load()) EXITCODE(6)

    CourseList courseList;
    CourseNode *courseNode;

    CourseStudentList courseStudentList;
    CourseStudentNode courseStudentNode;

    char keyPress;

    //Input oldSemesterID
    //oldSemesterID is not current but is active
    string *s = new string [1];
    fPtr *p = new fPtr [1] {inputSemester};
    if (!inputData(s, p, 1, 0, checkStaff_1_2)) EXITCODE(6);

    if (s[0].length() == 0) {
        staffSemesterMenu();
        return;
    }

    string oldSemesterID = s[0], newSemesterID;

    semesterNode = semesterList.find(oldSemesterID, ACTIVE);
    if (semesterNode == nullptr) EXITCODE(6)

    //Input newSemesterID which does not exist in semester list
    cout << "\n\nRename a specific semester. Please enter the new semester ID.\n";
    cout << "[  enter  ] Skip this step.\n";
    cout << "[` + enter] Back to menu.\n\n";

    bool passed = false;

    while (!passed) {
        cout << "New semester ID: ";

        fflush(stdin);
        getline(cin, newSemesterID);
        fflush(stdin);

        if (newSemesterID.length() == 0) {
            passed = true;
            continue;
        }

        if (newSemesterID.find('`') != string::npos) {
            staffSemesterMenu();
            return;
        }

        if (semesterList.find(newSemesterID, ALL) != nullptr)
            passed = true;
        else {
            cout << "The semester ID that you typed has been existing. Please enter another one.\n";
        }
    }

    if (newSemesterID.length() > 0) {
        //update oldSemesterID to newSemesterID
        semesterNode->semesterID = newSemesterID;

        //copy all files oldSemesterID-[classID]-course.txt to newSemesterID-[classID]-course.txt
        //each file oldSemesterID-[classID]-course.txt, copy all files oldSemesterID-[classID]-[courseID]-student.txt to newSemesterID-[classID]-[courseID]-student.txt
        for (classNode = classList.Head; classNode != nullptr; classNode = classNode->Next) {
            if (!courseList.load(oldSemesterID, classNode->classID)) EXITCODE(6)

            for (courseNode = courseList.Head; courseNode != nullptr; courseNode = courseNode->Next)
                copyFile(getLocation() + "data/" + oldSemesterID + "-" + classNode->classID + "-" + courseNode->courseID + "-student.txt",
                         getLocation() + "data/" + newSemesterID + "-" + classNode->classID + "-" + courseNode->courseID + "-student.txt");

            copyFile(getLocation() + "data/" + oldSemesterID + "-" + classNode->classID + "-course.txt",
                     getLocation() + "data/" + newSemesterID + "-" + classNode->classID + "-course.txt");

            courseList.destroy();
        }

        cout << "The semester '" << oldSemesterID << "' has been renamed to '" << newSemesterID << "' successfully. [enter]\n";

        fflush(stdin);
        keyPress = cin.get();
        fflush(stdin);
    }

    //if newSemesterID is not current and is active,
    //ask user whether he wants to make it currentSemester, type newSemesterID to confirm,
    if (semesterNode->active && semesterNode->current == NEXT) {
        //if (newSemesterID.length() == 0) newSemesterID = oldSemesterID;

        cout << "\n\nSet this semester as the current semester. Would you like to continue?\n";
        cout << "If you agree, the semester '" << SemesterList::currentSemester << "' will be set as a previous semester, "
             << "which means, it CANNOT be set as the current semester anymore. [enter] \n";

        fflush(stdin);
        keyPress = cin.get();
        fflush(stdin);

        cout << "If your intention does not change, please type the confirmation code '" << semesterNode->semesterID
             << "' (without the single quotation marks) and press [enter] to confirm.\n";
        cout << "[` + enter] Back to menu.\n\n";

        string confirmation;
        passed = false;

        while (!passed) {
            cout << "Your confirmation code: ";

            fflush(stdin);
            getline(cin, confirmation);
            fflush(stdin);

            if (confirmation.find('`') != string::npos) {
                staffSemesterMenu();
                return;
            }

            if (confirmation == semesterNode->semesterID)
                passed = true;
            else {
                cout << "Your code is invalid. Please enter one more time.\n";
            }
        }

        //after confirmation, make currentSemester PREVIOUS and make newSemesterID CURRENT
        semesterNode->current = CURRENT;

        semesterNode = semesterList.find(SemesterList::currentSemester, ACTIVE);
        if (semesterNode == nullptr || !semesterNode->active || semesterNode->current != CURRENT) EXITCODE(6)

        semesterNode->current = PREVIOUS;

        cout << "\n\nSet as current semester successfully. [enter]\n";

        fflush(stdin);
        keyPress = cin.get();
        fflush(stdin);
    }

    staffSemesterMenu();
}

void staff_1_3() {

    //Remove a specific semester

    //Input semesterID
    //semesterID is not current but is active


    //remove semesterID: active -> 0

    SemesterList semesterList;
    if (!semesterList.load())
    EXITCODE(6);
    cout << "\n\n";
    string* s = new string[1]{ "" };
    fPtr* p = new fPtr[1]{ inputSemester};
    inputData(s, p, 1, 0, checkStaff_1_3);
    semesterList.find(s[0], ACTIVE)->active = 0;
    semesterList.save();
    delete[]s;
    delete[]p;
    cout << "Deleted successfully [enter]";
    fflush(stdin);
    cin.get();
    fflush(stdin);
    staffSemesterMenu();
    return;
}

bool cmpSemesterList(const SemesterNode& a, const SemesterNode& b) { return a.semesterID < b.semesterID; }

void staff_1_4() {
    //View list of semester

    //Input nothing

    //View list of active semesters
    SemesterList semesterList;
    if (!semesterList.load())
    EXITCODE(6);
    cout << "\n\n";
    SemesterNode* cur = semesterList.Head;
    SemesterNode* temp = new SemesterNode[semesterList.cnt];
    int n = 0;
    while (cur != nullptr)
    {
        temp[n].semesterID = cur->semesterID;
        temp[n].active = cur->active;
        ++n;
        cur = cur->Next;
    }
    sort(temp, temp + semesterList.cnt, cmpSemesterList);
    //output:
    for (int i = 0; i < semesterList.cnt; ++i)
    {
        if (temp[i].active == 1)
            cout << temp[i].semesterID;
        if (i != semesterList.cnt - 1)
            cout << endl;
    }
    delete[]temp;

    cout << "\n[enter]";
    fflush(stdin);
    cin.get();
    fflush(stdin);
    staffSemesterMenu();
    return;
}

bool checkStaff_1_1(string* s,int n) {
    return true;
}

bool checkStaff_1_2(string *s, int n) {
    return true;
}

bool checkStaff_1_3(string* s,int n) {
    SemesterList semesterList;
    if (!semesterList.load())
    EXITCODE_V(6, false);
    if (!semesterList.find(s[0], ACTIVE)){
        cout << "Semester does not exist";
        EXITCODE_V(6, false);
    }
    if (semesterList.find(s[0],ACTIVE)->current == 1) {
        cout << "Cannot delete a current semester.";
        return false;
    }
    return true;
}

bool checkStaff_1_4() {
    return false;
}

void staff_3_1() {
    //Import list of courses from file

    //Input semesterID, classID, filepath

    //load
    //loadCSV
    //save

    string semesterID, classID, filepath;
    SemesterList semesterList;
    ClassList classList;
    CourseList courseList;
    CourseNode* courseNode;
    ClassStudentList classStudentList;
    CourseStudentList courseStudentList;
    LecturerList lecturerList;

    if (!semesterList.load()|| !classList.load()||!lecturerList.load())
    EXITCODE(6);
    string *s = new string[3]{"", "", ""};
    fPtr *p = new fPtr[3]{inputSemester, inputClass, inputPathCourseListCSV};
    inputData(s, p, 3, 0, checkStaff_1_1);

    //DEBUG ONLY!!
    /* fPtr *p = new fPtr[2]{inputSemester, inputClass};
     inputData(s, p, 2, 0, checkStaff_1_1);
     filepath = "E:/University Works/Project/cs162-19apcs2-group12/cmake-build-debug/Semester1/19ctt2_courselist.csv";*/
    //DEBUG END

    semesterID = s[0];
    classID = s[1];
    filepath = s[2];

    //loadCSV
    string temp, temp2;
    ifstream finput;
    finput.open(filepath);
    getline(finput, temp);

    courseList.load(semesterID, classID);
    bool skipAll = false;
    bool replaceAll = false;
    while (finput.good()) {
        courseNode = new CourseNode;
        getline(finput,temp ,',');
        if (temp == "")
        {
            delete courseNode;
            continue;
        }
        getline(finput, courseNode->courseID,',');
        getline(finput, courseNode->courseName, ',');
        getline(finput, courseNode->lecturerID, ',');
        normalize(courseNode->courseID);
        normalizeFullName(courseNode->courseName);
        normalize(courseNode->lecturerID);
        getline(finput, temp, ',');
        courseNode->startingDate.y = 1000 * (temp[0] - '0') +100*(temp[1]-'0')+10*(temp[2]-'0')+(temp[3]-'0');
        courseNode->startingDate.m = 10 * (temp[5] - '0') + (temp[6] - '0');
        courseNode->startingDate.d = 10 * (temp[8] - '0') + (temp[9] - '0');
        getline(finput, temp, ',');
        courseNode->startingTime.h = 10 * (temp[0] - '0') + (temp[1] - '0');
        courseNode->startingTime.m = 10 * (temp[3] - '0') + (temp[4] - '0');
        courseNode->startingTime.s = 10 * (temp[6] - '0') + (temp[7] - '0');
        getline(finput, temp, ',');
        courseNode->endingTime.h = 10 * (temp[0] - '0') + (temp[1] - '0');
        courseNode->endingTime.m = 10 * (temp[3] - '0') + (temp[4] - '0');
        courseNode->endingTime.s = 10 * (temp[6] - '0') + (temp[7] - '0');
        courseNode->active = 1;
        getline(finput, courseNode->room,'\n');
        if(courseList.find(courseNode->courseID,ALL)==nullptr)
            courseList.pushBack(courseNode);
        else if (skipAll) {
            delete courseNode;
            continue;
        }
        else if (replaceAll) {
            courseList.find(courseNode->courseID, ALL)->active = 1;
            courseList.find(courseNode->courseID, ALL)->courseName = courseNode->courseName;
            courseList.find(courseNode->courseID, ALL)->endingTime = courseNode->endingTime;
            courseList.find(courseNode->courseID, ALL)->lecturerID = courseNode->lecturerID;
            courseList.find(courseNode->courseID, ALL)->room = courseNode->room;
            courseList.find(courseNode->courseID, ALL)->startingDate = courseNode->startingDate;
            courseList.find(courseNode->courseID, ALL)->startingTime = courseNode->startingTime;
            delete courseNode;
            continue;
        }
        else {
            int choice = 0;
            char keyPress;

            cout << "\n\nThe course with ID '" << courseNode->courseID << "' has already added.\n";
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
                        delete courseNode;
                        break;
                    case '2':
                        choice = REPLACE;
                        {
                            courseList.find(courseNode->courseID, ALL)->active = 1;
                            courseList.find(courseNode->courseID, ALL)->courseName = courseNode->courseName;
                            courseList.find(courseNode->courseID, ALL)->endingTime = courseNode->endingTime;
                            courseList.find(courseNode->courseID, ALL)->lecturerID = courseNode->lecturerID;
                            courseList.find(courseNode->courseID, ALL)->room = courseNode->room;
                            courseList.find(courseNode->courseID, ALL)->startingDate = courseNode->startingDate;
                            courseList.find(courseNode->courseID, ALL)->startingTime = courseNode->startingTime;
                            delete courseNode;
                        }
                        break;
                    case '3':
                        choice = SKIP_ALL;
                        skipAll = true;
                        break;
                    case '4':
                        choice = REPLACE_ALL;
                        replaceAll = true;
                        break;
                    default:
                        choice = 0;
                }
            }
        }
    }


    courseList.save(semesterID, classID);
    courseNode = courseList.Head;

    //load Student List
    CourseStudentNode* courseStudentNode;
    classStudentList.load(classID);
    while (classStudentList.Head != NULL)
    {
        courseStudentNode = new CourseStudentNode;
        courseStudentNode->studentID = classStudentList.Head->studentID;
        courseStudentNode->active = 1;
        courseStudentList.pushBack(courseStudentNode);
        classStudentList.Head = classStudentList.Head->Next;
    }

    LecturerNode* lecturerNode;
    //save Student Course List
    while (courseNode != nullptr) {
        //courseStudentList.load(semesterID, classID, courseNode->courseID);

        courseStudentList.save(semesterID, classID, courseNode->courseID);
        if (lecturerList.find(courseNode->lecturerID, ACTIVE)==nullptr){
            if (lecturerList.find(courseNode->lecturerID, ALL)==nullptr){
                lecturerNode=new LecturerNode;
                lecturerNode->lecturerID = courseNode->lecturerID;
                lecturerNode->lecturerName = "Waiting to be edited";
                lecturerNode->password = getHashedPassword(courseNode->lecturerID);
                lecturerNode->active = 1;
                lecturerNode->academicTitle = "Waiting to be edited";
                lecturerNode->gender= 1;
                lecturerList.pushBack(lecturerNode);
            }
            else lecturerList.find(courseNode->lecturerID, ALL)->active = 1;
        }
        courseNode = courseNode->Next;
    }
    lecturerList.save();
    //delete[]s;
    //delete[]p;
    cout << "\n\nImport successfully. [enter]\n";
    fflush(stdin);
    cin.get();
    fflush(stdin);
    staffCourseMenu();
    return;
}

void staff_3_2() {
    //Create a new courses

    //Input semesterID, classID

    //Input courseID, courseName, lecturerID, startingDate, startingTime, endingTime, room
    //courseID not exist, lecturerID must exist

    string semesterID, classID;
    SemesterList semesterList;
    ClassList classList;
    CourseList courseList;
    LecturerList lecturerList;

    if (!semesterList.load()|| !classList.load())
    EXITCODE(6);

    //inputData
    string *s = new string[2]{"", ""};
    fPtr *p = new fPtr[2]{inputSemester, inputClass};

    if (!inputData(s, p, 0, 2, checkStaff_1_1)) EXITCODE(6);

    delete [] s;
    delete [] p;

    if (s[0].length() == 0) {
        staffCourseMenu();
        return;
    }

    semesterID = s[0];
    classID = s[1];

    if (!courseList.load(semesterID, classID))
    EXITCODE(6);
    //p[0]={inputCourse}
    //s[0] = "";
    //inputData(s,p,0,1,checkStaff_3_2);
    CourseNode *courseNode = new CourseNode;

    //input courseID
    cout << "\n\nCreate a new course. Please type in the new course ID.\n";
    cout << "[` + enter] Back to menu.\n\n";

    bool passed = false;

    while (!passed) {
        cout << "New course ID: ";

        fflush(stdin);
        getline(cin, courseNode->courseID);
        fflush(stdin);

        if (courseNode->courseID.find('`') != string::npos) {
            delete courseNode;

            staffCourseMenu();
            return;
        }

        if (courseList.find(courseNode->courseID, ALL) == nullptr)
            passed = true;
        else {
            cout << "The course ID that you typed has been existing in class '" << classID << "'. Please enter another one.\n";
        }
    }

    //input courseName
    cout << "\n\nCreate a new course. Please type in the new course name.\n";
    cout << "[` + enter] Back to menu.\n\n";

    passed = false;

    while (!passed) {
        cout << "New course name: ";

        fflush(stdin);
        getline(cin, courseNode->courseName);
        fflush(stdin);

        if (courseNode->courseName.find('`') != string::npos) {
            delete courseNode;

            staffCourseMenu();
            return;
        }

        if (courseNode->courseName.length() > 0)
            passed = true;
        else {
            cout << "This field must not be empty. Please type again.\n";
        }
    }

    //input lecturerID
    lecturerList.load();

    cout << "\n\nCreate a new course. Please type in the lecturer ID.\n";
    cout << "[` + enter] Back to menu.\n\n";

    passed = false;

    while (!passed) {
        cout << "Lecturer ID: ";

        fflush(stdin);
        getline(cin, courseNode->lecturerID);
        fflush(stdin);

        if (courseNode->lecturerID.find('`') != string::npos) {
            delete courseNode;

            staffCourseMenu();
            return;
        }

        if (lecturerList.find(courseNode->lecturerID, ACTIVE) != nullptr)
            passed = true;
        else {
            cout << "The lecturer with ID '" << courseNode->lecturerID << "' does not exist. Please enter again.\n";
        }
    }

    //input startingDate
    string startingDate;

    cout << "\n\nCreate a new course. Please type in the starting date (yyyy/mm/dd).\n";
    cout << "[` + enter] Back to menu.\n\n";

    passed = false;

    while (!passed) {
        cout << "Course starting date: ";

        fflush(stdin);
        getline(cin, startingDate);
        fflush(stdin);

        if (startingDate.find('`') != string::npos) {
            delete courseNode;

            staffCourseMenu();
            return;
        }

        if (startingDate.length() < 10) {
            cout << "The date you type is invalid or wrong in format. Please type again.\n";
            continue;
        }

        courseNode->startingDate.y = startingDate[0] * 1000 + startingDate[1] * 100 + startingDate[2] * 10 + startingDate[3];
        courseNode->startingDate.m = startingDate[5] * 10 + startingDate[6];
        courseNode->startingDate.d = startingDate[8] * 10 + startingDate[9];

        if (!courseNode->startingDate.wrongFormat())
            passed = true;
        else {
            cout << "The date you type is invalid or wrong in format. Please type again.\n";
        }
    }

    //input startingTime
    string startingTime;

    cout << "\n\nCreate a new course. Please type in the starting time (hh:mm:ss).\n";
    cout << "[` + enter] Back to menu.\n\n";

    passed = false;

    while (!passed) {
        cout << "Course starting time: ";

        fflush(stdin);
        getline(cin, startingTime);
        fflush(stdin);

        if (startingTime.find('`') != string::npos) {
            delete courseNode;

            staffCourseMenu();
            return;
        }

        if (startingTime.length() < 8) {
            cout << "The time you type is invalid or wrong in format. Please re-enter it.\n";
            continue;
        }

        courseNode->startingTime.h = startingTime[0] * 10 + startingTime[1];
        courseNode->startingTime.m = startingTime[3] * 10 + startingTime[4];
        courseNode->startingTime.s = startingTime[6] * 10 + startingTime[7];

        if (!courseNode->startingTime.wrongFormat())
            passed = true;
        else {
            cout << "The time you type is invalid or wrong in format. Please type again.\n";
        }
    }

    //input endingTime
    string endingTime;

    cout << "\n\nCreate a new course. Please type in the ending time (hh:mm:ss).\n";
    cout << "[` + enter] Back to menu.\n\n";

    passed = false;

    while (!passed) {
        cout << "Course ending time: ";

        fflush(stdin);
        getline(cin, endingTime);
        fflush(stdin);

        if (endingTime.find('`') != string::npos) {
            delete courseNode;

            staffCourseMenu();
            return;
        }

        if (endingTime.length() < 8) {
            cout << "The time you type is invalid or wrong in format. Please enter one more time.\n";
            continue;
        }

        courseNode->endingTime.h = endingTime[0] * 10 + endingTime[1];
        courseNode->endingTime.m = endingTime[3] * 10 + endingTime[4];
        courseNode->endingTime.s = endingTime[6] * 10 + endingTime[7];

        if (!courseNode->endingTime.wrongFormat() && courseNode->startingTime <= courseNode->endingTime)
            passed = true;
        else {
            cout << "The time you type is invalid or wrong in format. Please enter one more time.\n";
        }
    }

    //input room
    cout << "\n\nCreate a new course. Please type in the course room.\n";
    cout << "[` + enter] Back to menu.\n\n";

    passed = false;

    while (!passed) {
        cout << "Course room: ";

        fflush(stdin);
        getline(cin, courseNode->room);
        fflush(stdin);

        if (courseNode->room.find('`') != string::npos) {
            delete courseNode;

            staffCourseMenu();
            return;
        }

        if (courseNode->room.length() > 0)
            passed = true;
        else {
            cout << "This field must not be empty. Please type again.\n";
        }
    }

    courseNode->active = true;
    courseNode->Next = nullptr;

    courseList.pushBack(courseNode);
    courseList.save(semesterID,classID);
    //load Student List
    ClassStudentList classStudentList;
    CourseStudentList courseStudentList;
    CourseStudentNode* courseStudentNode;
    classStudentList.load(classID);
    while (classStudentList.Head != NULL)
    {
        courseStudentNode = new CourseStudentNode;
        courseStudentNode->studentID = classStudentList.Head->studentID;
        courseStudentNode->active = 1;
        courseStudentList.pushBack(courseStudentNode);
        classStudentList.Head = classStudentList.Head->Next;
    }
    courseStudentList.save(semesterID, classID, courseNode->courseID);
    cout << "Created successfully! [enter]";
    fflush(stdin);
    cin.get();
    fflush(stdin);

    staffCourseMenu();
}

void staff_3_3() {
    //Update a specific course
    string semesterID, classID, courseID;
    SemesterList semesterList;
    ClassList classList;
    CourseList courseList;
    LecturerList lecturerList;

    if (!semesterList.load()||!classList.load())
    EXITCODE(6);
    string *s = new string[3]{"", "",""};
    fPtr *p = new fPtr[3]{inputSemester, inputClass, inputCourse};
    inputData(s, p, 3, 0, checkStaff_1_1);

    semesterID = s[0];
    classID = s[1];
    courseID = s[2];

    if (!courseList.load(semesterID,classID))
    EXITCODE(6);

    //INPUT:
    // courseID, courseName, lecturerID, startingDate, startingTime, endingTime, room, active
    CourseNode *courseNode = new CourseNode;

    //input courseID
    cout << "\n\nCreate a new course. Please type in the new course ID.\n";
    cout << "[` + enter] Back to menu.\n\n";

    bool passed = false;

    while (!passed) {
        cout << "New course ID: ";

        fflush(stdin);
        getline(cin, courseNode->courseID);
        fflush(stdin);

        if (courseNode->courseID.find('`') != string::npos) {
            delete courseNode;

            staffCourseMenu();
            return;
        }

        if (courseList.find(courseNode->courseID, ALL) == nullptr)
            passed = true;
        else {
            cout << "The course ID that you typed has been existing in class '" << classID << "'. Please enter another one.\n";
        }
    }

    //input courseName
    cout << "\n\nCreate a new course. Please type in the new course name.\n";
    cout << "[` + enter] Back to menu.\n\n";

    passed = false;

    while (!passed) {
        cout << "New course name: ";

        fflush(stdin);
        getline(cin, courseNode->courseName);
        fflush(stdin);

        if (courseNode->courseName.find('`') != string::npos) {
            delete courseNode;

            staffCourseMenu();
            return;
        }

        if (courseNode->courseName.length() > 0)
            passed = true;
        else {
            cout << "This field must not be empty. Please type again.\n";
        }
    }

    //input lecturerID
    lecturerList.load();

    cout << "\n\nCreate a new course. Please type in the lecturer ID.\n";
    cout << "[` + enter] Back to menu.\n\n";

    passed = false;

    while (!passed) {
        cout << "Lecturer ID: ";

        fflush(stdin);
        getline(cin, courseNode->lecturerID);
        fflush(stdin);

        if (courseNode->lecturerID.find('`') != string::npos) {
            delete courseNode;

            staffCourseMenu();
            return;
        }

        if (lecturerList.find(courseNode->lecturerID, ACTIVE) != nullptr)
            passed = true;
        else {
            cout << "The lecturer with ID '" << courseNode->lecturerID << "' does not exist. Please enter again.\n";
        }
    }

    //input startingDate
    string startingDate;

    cout << "\n\nCreate a new course. Please type in the starting date (yyyy/mm/dd).\n";
    cout << "[` + enter] Back to menu.\n\n";

    passed = false;

    while (!passed) {
        cout << "Course starting date: ";

        fflush(stdin);
        getline(cin, startingDate);
        fflush(stdin);

        if (startingDate.find('`') != string::npos) {
            delete courseNode;

            staffCourseMenu();
            return;
        }

        if (startingDate.length() < 10) {
            cout << "The date you type is invalid or wrong in format. Please type again.\n";
            continue;
        }

        courseNode->startingDate.y = startingDate[0] * 1000 + startingDate[1] * 100 + startingDate[2] * 10 + startingDate[3];
        courseNode->startingDate.m = startingDate[5] * 10 + startingDate[6];
        courseNode->startingDate.d = startingDate[8] * 10 + startingDate[9];

        if (!courseNode->startingDate.wrongFormat())
            passed = true;
        else {
            cout << "The date you type is invalid or wrong in format. Please type again.\n";
        }
    }


    //input startingTime
    string startingTime;

    cout << "\n\nCreate a new course. Please type in the starting time (hh:mm:ss).\n";
    cout << "[` + enter] Back to menu.\n\n";

    passed = false;

    while (!passed) {
        cout << "Course starting time: ";

        fflush(stdin);
        getline(cin, startingTime);
        fflush(stdin);

        if (startingTime.find('`') != string::npos) {
            delete courseNode;

            staffCourseMenu();
            return;
        }

        if (startingTime.length() < 8) {
            cout << "The time you type is invalid or wrong in format. Please re-enter it.\n";
            continue;
        }

        courseNode->startingTime.h = startingTime[0] * 10 + startingTime[1];
        courseNode->startingTime.m = startingTime[3] * 10 + startingTime[4];
        courseNode->startingTime.s = startingTime[6] * 10 + startingTime[7];

        if (!courseNode->startingTime.wrongFormat())
            passed = true;
        else {
            cout << "The time you type is invalid or wrong in format. Please type again.\n";
        }
    }

    //input endingTime
    string endingTime;

    cout << "\n\nCreate a new course. Please type in the ending time (hh:mm:ss).\n";
    cout << "[` + enter] Back to menu.\n\n";

    passed = false;

    while (!passed) {
        cout << "Course ending time: ";

        fflush(stdin);
        getline(cin, endingTime);
        fflush(stdin);

        if (endingTime.find('`') != string::npos) {
            delete courseNode;

            staffCourseMenu();
            return;
        }

        if (endingTime.length() < 8) {
            cout << "The time you type is invalid or wrong in format. Please enter one more time.\n";
            continue;
        }

        courseNode->endingTime.h = endingTime[0] * 10 + endingTime[1];
        courseNode->endingTime.m = endingTime[3] * 10 + endingTime[4];
        courseNode->endingTime.s = endingTime[6] * 10 + endingTime[7];

        if (!courseNode->endingTime.wrongFormat() && courseNode->startingTime <= courseNode->endingTime)
            passed = true;
        else {
            cout << "The time you type is invalid or wrong in format. Please enter one more time.\n";
        }
    }

    //input room
    cout << "\n\nCreate a new course. Please type in the course room.\n";
    cout << "[` + enter] Back to menu.\n\n";

    passed = false;

    while (!passed) {
        cout << "Course room: ";

        fflush(stdin);
        getline(cin, courseNode->room);
        fflush(stdin);

        if (courseNode->room.find('`') != string::npos) {
            delete courseNode;

            staffCourseMenu();
            return;
        }

        if (courseNode->room.length() > 0)
            passed = true;
        else {
            cout << "This field must not be empty. Please type again.\n";
        }
    }

    courseNode->active = true;
    courseNode->Next = nullptr;
}

void staff_3_4() {
    //Remove a specific course
    string semesterID, classID, courseID;
    SemesterList semesterList;
    ClassList classList;
    CourseList courseList;

    if (!semesterList.load()||!classList.load())
    EXITCODE(6);
    string *s = new string[3]{"", "",""};
    fPtr *p = new fPtr[3]{inputSemester, inputClass,inputCourse};
    inputData(s, p, 3, 0, checkStaff_1_1);

    semesterID = s[0];
    classID = s[1];
    courseID = s[2];

    if (!courseList.load(semesterID, classID))
    EXITCODE(6);
    courseList.find(courseID, ACTIVE)->active = 0;
    courseList.save(semesterID, classID);
    cout << "Successfully deleted course [enter]";
    fflush(stdin);
    cin.get();
    fflush(stdin);
    staffCourseMenu();
    return;
}

void staff_3_5() {
    //View list of courses
    string semesterID, classID;
    SemesterList semesterList;
    ClassList classList;

    if (!semesterList.load()|| !classList.load())
    EXITCODE(6);
    string *s = new string[2]{"", ""};
    fPtr *p = new fPtr[2]{inputSemester, inputClass};
    inputData(s, p, 2, 0, checkStaff_3_5);

    semesterID = s[0];
    classID = s[1];
    CourseList courseList;
    if (!courseList.load(semesterID, classID))
    EXITCODE(6);
    //output: PENDING!
    cout << endl << endl;
    while (courseList.Head != nullptr&&courseList.Head->active==1) {
        cout << courseList.Head->courseID << endl;
        cout << courseList.Head->courseName << endl;
        cout << courseList.Head->lecturerID << endl;
        cout << courseList.Head->room << endl;
        cout << courseList.Head->startingDate.y <<" "<< courseList.Head->startingDate.m <<" "<< courseList.Head->startingDate.y << endl;
        cout << courseList.Head->startingTime.h << " " << courseList.Head->startingTime.m << " " << courseList.Head->startingTime.s;
        cout << courseList.Head->endingTime.h << " " << courseList.Head->endingTime.m << " " << courseList.Head->endingTime.s;
        cout << endl << endl;
        courseList.Head = courseList.Head->Next;
    }
    cout << "\n\n[enter]";
    staffCourseMenu();
    return;
}

void staff_3_6() {
    //Remove a specific student from a course.
    string semesterID, classID, courseID, studentID;
    SemesterList semesterList;
    ClassList classList;
    CourseList courseList;
    CourseStudentList courseStudentList;

    if (!semesterList.load()|| !classList.load())
    EXITCODE(6);
    string *s = new string[4]{"", "", "", ""};
    fPtr *p = new fPtr[4]{inputSemester, inputClass,inputCourse, inputStudent};
    inputData(s, p, 4, 0, checkStaff_3_5);

    semesterID = s[0];
    classID = s[1];
    courseID=s[2];
    studentID=s[3];

    if (!courseList.load(semesterID, classID)||!courseStudentList.load(semesterID,classID,courseID))
    EXITCODE(6);
    courseStudentList.find(studentID, ACTIVE)->active = 0;
    courseStudentList.save(semesterID, classID, courseID);
    cout << "\n\nSuccessfully deleted student " << studentID<<"  [enter]";
    fflush(stdin);
    cin.get();
    fflush(stdin);
    staffCourseMenu();
    return;
}

void staff_3_7() {
    //Add a specific student to a course.
    string semesterID, classID, studentID, courseID;
    SemesterList semesterList;
    ClassList classList;
    CourseList courseList;
    CourseStudentList courseStudentList;
    StudentList studentList;

    if (!semesterList.load()|| !classList.load())
    EXITCODE(6);

    cout <<"Choose student to add:";
    string *s = new string[3]{"","",""};
    fPtr *p = new fPtr[3]{inputStudent};
    inputData(s, p, 1, 0, checkStaff_1_1);

    studentID=s[0];

    p[0] = inputSemester;
    p[1] = inputClass;
    p[2] = inputCourse;
    s[0] = s[1] = s[2] = "";
    inputData(s, p, 3, 0, checkStaff_1_1);
    semesterID = s[0];
    classID = s[1];
    courseID=s[2];

    if (!courseList.load(semesterID, classID) || !courseStudentList.load(semesterID, classID, courseID))
    EXITCODE(6);
    if(courseStudentList.find(studentID,ACTIVE)==nullptr)
        if (courseStudentList.find(studentID, ALL) == nullptr)
        {
            CourseStudentNode* courseStudentNode = new CourseStudentNode;
            courseStudentNode->active = 1;
            courseStudentNode->studentID = studentID;
            courseStudentList.pushBack(courseStudentNode);
            cout << "Successfully added " << studentID << "   [enter]";
        }
        else {
            courseStudentList.find(studentID, ALL)->active = 1;
            cout << "Successfully added " << studentID << "   [enter]";
        }
    else {
        cout << "Student already existed";
    }
    courseStudentList.save(semesterID, classID, courseID);

    fflush(stdin);
    cin.get();
    fflush(stdin);
    staffCourseMenu();
    return;
}

void staff_3_8() {
    //View list of students of a course.
    // inputData : semesterID, classID, courseID
    string* s = new string[3]{ "","","" };
    fPtr* p = new fPtr[3]{ inputSemester, inputClass, inputCourse };
    inputData(s, p, 3, 0, checkStaff_3_8);
    StudentList stuList;
    if (!stuList.load()) EXITCODE(6);

    string semesterID = s[0], classID = s[1], courseID = s[2]; // Data for testing.
    SemesterList sems; ClassList classes; CourseList courses;

    if (!sems.load()|| !classes.load()) EXITCODE(6);

    if (sems.find(semesterID, ACTIVE)==nullptr || classes.find(classID, ACTIVE)==nullptr) EXITCODE(6);

    if (!courses.load(semesterID, classID)) EXITCODE(6);
    CourseNode* node = courses.find(courseID, ACTIVE);
    if (node == nullptr) EXITCODE(6);
    int index=1;
    CourseStudentList llist;
    if (!llist.load(semesterID, classID, courseID)) EXITCODE(6);

    for(CourseStudentNode* node= llist.Head; node; node = node->Next){
        StudentNode* stuNode = stuList.find(node->studentID, ACTIVE);
        printStudent(stuNode, index);
    }

    // Remember to de allocate s and p
    staffCourseMenu();
    delete [] s;
    delete[] p;


}

void staff_3_9() {
    //View a scoreboard
    //inputData: semesterID, classID, courseID
    string* s = new string[3]{ "","","" };
    fPtr* p = new fPtr[3]{ inputSemester, inputClass, inputCourse };
    inputData(s, p, 3, 0, checkStaff_3_9);

    string semesterID = s[0], courseID = s[2], classID = s[1];

    SemesterList sems; ClassList classes; CourseList courses;
    if (!sems.load() || !classes.load()) EXITCODE(6);


    if (sems.find(semesterID, ACTIVE) == nullptr || classes.find(classID, ACTIVE) == nullptr) EXITCODE(6);

    if (!courses.load(semesterID, classID)) EXITCODE(6);

    CourseNode* node = courses.find(courseID, ACTIVE);
    if (node == nullptr) EXITCODE(6);

    CourseStudentList llist;
    if (!llist.load(semesterID, classID, courseID)) EXITCODE(6);


    StudentList stuList;
    if (!stuList.load()) EXITCODE(6);
    cout << "\n\nNo\t" << "Student Name\t" << "Student ID\t" << "Midterm\t" << "Final\t" << "Bonus\t" << "Total" << endl;
    int index = 1;
    for (CourseStudentNode* node = llist.Head; node; node = node->Next) {
        StudentNode* tmp = stuList.find(node->studentID, ACTIVE);
        if (tmp) {
            cout << index << "\t" << tmp->studentName << "\t" << tmp->studentID << "\t" << node->score.midterm
                 << "\t" << node->score.final << "\t" << node->score.bonus << "\t" << node->score.total << endl;
            index++;
        }
    }

    staffCourseMenu();
    delete[] s;
    delete[] p;
}

void staff_3_10() {
    //Export a scoreboard to file.
    // inputData: semesterID, classID, courseID, filePath
    string* s = new string[4]{ "","","","" };
    fPtr* p = new fPtr[4]{ inputSemester, inputClass, inputCourse , inputPathExportCSV};
    inputData(s, p, 4, 0, checkStaff_3_10);
    string semesterID = s[0], courseID = s[2], classID = s[1], filePath=s[3];

    SemesterList sems; ClassList classes; CourseList courses;
    if (!sems.load() || !classes.load()) EXITCODE(6);


    if (sems.find(semesterID, ALL) == nullptr || classes.find(classID, ALL) == nullptr) EXITCODE(6);

    if (!courses.load(semesterID, classID)) EXITCODE(6);

    CourseNode* node = courses.find(courseID, ACTIVE);
    if (node == nullptr) EXITCODE(6);
    int index = 1;
    CourseStudentList llist;
    if (!llist.load(semesterID, classID, courseID)) EXITCODE(6);

    saveCSV(llist, filePath, ScoreBoard);
    delete[]s;
    delete[]p;
}

void staff_3_11() {
    //View an attendance list
    // inputData: semesterID, classID, courseID
    string* s = new string[3]{ "","","" };
    fPtr* p = new fPtr[3]{ inputSemester, inputClass, inputCourse };
    inputData(s, p, 3, 0, checkStaff_3_11);

    StudentList stuList;
    if (!stuList.load()) EXITCODE(6);

    string semesterID = s[0], courseID = s[2], classID = s[1];

    SemesterList sems; ClassList classes; CourseList courses;
    if (!sems.load()|| !classes.load()) EXITCODE(6);

    if (sems.find(semesterID, ACTIVE)==nullptr || classes.find(classID, ACTIVE)==nullptr) EXITCODE(6);

    if (!courses.load(semesterID, classID)) EXITCODE(6);
    CourseNode* node = courses.find(courseID, ACTIVE);
    if (node == nullptr) EXITCODE(6);

    CourseStudentList llist;
    if (!llist.load(semesterID, classID, courseID)) EXITCODE(6);



    CourseStudentNode* stuNode = llist.Head;
    cout << "\n\n" << "No\t" <<"Student Name\t" << "Student ID\t" << "W01\t" << "W02\t" << "W03\t" << "W04\t"
         << "W05\t" << "W06\t"<< "W07\t" << "W08\t" << "W09\t" << "W10" << endl;
    int index = 1;
    while (stuNode) {
        StudentNode* node = stuList.find(stuNode->studentID, ACTIVE);
        if (node) {
            cout << index << "\t" << node->studentName << "\t" << node->studentID << "\t";
            for (int i = 0; i < 10; i++) {
                if (i == 9) cout << stuNode->attendance[i] << endl;
                else cout << stuNode->attendance[i] << ",";
            }
            index++;
        }
        stuNode = stuNode->Next;


    }
    // Remember to de allocate:
    staffCourseMenu();
    delete[]s;
    delete[]p;



}



void staff_3_12() {
    //Export an attendance list to file.
    string* s = new string[4]{ "","","","" };
    fPtr* p = new fPtr[4]{ inputSemester, inputClass, inputCourse, inputPathExportCSV};
    inputData(s, p, 4, 0, checkStaff_3_12);
    string semesterID = s[0], courseID = s[2], classID = s[1], filePath = s[3];

    SemesterList sems; ClassList classes; CourseList courses;
    if (!sems.load() || !classes.load()) EXITCODE(6);


    if (sems.find(semesterID, ALL) == nullptr || classes.find(classID, ALL) == nullptr) EXITCODE(6);

    if (!courses.load(semesterID, classID)) EXITCODE(6);

    CourseNode* node = courses.find(courseID, ACTIVE);
    if (node == nullptr) EXITCODE(6);
    int index = 1;
    CourseStudentList llist;
    if (!llist.load(semesterID, classID, courseID)) EXITCODE(6);

    saveCSV(llist, filePath, AttendanceList);
    delete[]s;
    delete[]p;
}

bool checkStaff_3_1() {
    return false;
}

bool checkStaff_3_2() {
    return false;
}

bool checkStaff_3_3(string* s,int n) {
    return false;
}

bool checkStaff_3_4(string* s,int n) {
    string semesterID, classID, courseID;
    //    semesterID = s[0];
    //    classID = s[1];
    //    courseID = s[3];
    CourseList courseList;
    if (!courseList.load(semesterID, classID)) {
        EXITCODE_V(6, false);
    }
    if (courseList.find(courseID, ACTIVE) == nullptr) {
        cout << "Course not found.";
        return false;
    }
    else return true;
    return false;
}

bool checkStaff_3_5(string* s, int n) {
    return true;
}

bool checkStaff_3_6(string* s,int n) {
    string semesterID, classID, courseID, studentID;
    semesterID = s[0];
    classID = s[1];
    courseID=s[2];
    studentID=s[3];
    SemesterList semesterList;
    ClassList classList;
    CourseStudentList courseStudentList;
    if (!courseStudentList.load(semesterID,classID,courseID))
    EXITCODE_V(6,false);
    if (courseStudentList.find(studentID, ACTIVE)==nullptr) {
        cout << "Student not found";
        return false;
    }
    return true;
}

bool checkStaff_3_7() {
    return false;
}

bool checkStaff_3_8(string*s, int n) {
    return true;
}

bool checkStaff_3_9(string* s, int n) {
    return true;
}

bool checkStaff_3_10(string* s, int n) {
    return true;
}

bool checkStaff_3_11(string* s, int n) {
    return true;
}

bool checkStaff_3_12(string* s, int n) {
    return true;
}

void lecturer_1() {

}

void lecturer_2() {

}

void lecturer_3() {

}

void lecturer_4() {

}

void lecturer_5() {

}

void lecturer_6() {

}

void lecturer_7() {

}

bool checkLecturer_1() {
    return false;
}

bool checkLecturer_2() {
    return false;
}

bool checkLecturer_3() {
    return false;
}

bool checkLecturer_4() {
    return false;
}

bool checkLecturer_5() {
    return false;
}

bool checkLecturer_6() {
    return false;
}

bool checkLecturer_7() {
    return false;
}

//---------------------------

void ScoreBoardFormat(CourseStudentList llist, ofstream &fout) {
    StudentList stuList;
    if (!stuList.load()) EXITCODE(6);
    fout << "\n\nNo," <<  "Student Name," << "Student ID," << "Midterm," << "Final," << "Bonus," << "Total" << endl;
    int index = 1;
    for (CourseStudentNode* node = llist.Head; node; node = node->Next) {
        StudentNode* tmp = stuList.find(node->studentID, ACTIVE);
        fout << index << "," << tmp->studentName << "," << tmp->studentID << "," << node->score.midterm
             << "," << node->score.final << "," << node->score.bonus << "," << node->score.total << endl;
        index++;
    }
}

void AttendanceListFormat(CourseStudentList llist, ofstream& fout) {
    StudentList stuList;
    if (!stuList.load()) EXITCODE(6);
    fout << "No, Student Name, Student ID, W01, W02, W03, W04, W05, W06, W07, W08, W09, W10" << endl;
    int index = 1;
    for (CourseStudentNode* node = llist.Head; node; node = node->Next) {
        StudentNode* tmp = stuList.find(node->studentID, ACTIVE);
        fout << index << "," << tmp->studentName << "," << tmp->studentID << ",";
        for (int i = 0; i < 10; i++) {
            if (i == 9) fout << node->attendance[i] << endl;
            else fout << node->attendance[i] << ",";
        }
        index++;
    }

}

void saveCSV(CourseStudentList llist, string filePath, bool mode) {
    ofstream fout;
    fout.open(filePath);
    if (!fout.is_open()) {
        cout << "\n\nCannot open this file" << endl;
        return;
    }
    if (mode == ScoreBoard) ScoreBoardFormat(llist, fout);
    else if (mode == AttendanceList) AttendanceListFormat(llist, fout);
    fout.close();
}
