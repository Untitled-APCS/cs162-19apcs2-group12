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
    //inputData(s, p, 0, 1, checkStaff_1_1);
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
    cout << "\n\nCreated successfully!";
    fflush(stdin);
    cin.get();
    fflush(stdin);
    staffSemesterMenu();
    return;
}

void staff_1_2() {
    //Update a specific semester

    //Input oldSemesterID
    //oldSemesterID is not current but is active

    //Input newSemesterID which does not exist in semester list

    //update oldSemesterID to newSemesterID

    //copy all files oldSemesterID-[classID]-course.txt to newSemesterID-[classID]-course.txt
    //each file oldSemesterID-[classID]-course.txt, copy all files oldSemesterID-[classID]-[courseID]-student.txt to newSemesterID-[classID]-[courseID]-student.txt

    //if newSemesterID is not current and is active,
    //ask user whether he wants to make it currentSemester, type newSemesterID to confirm,
    //after confirmation, make currentSemester PREV and make newSemesterID CURRENT
    staffSemesterMenu();
    return;
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
    //fPtr* p = new fPtr[1]{ inputSemester};
    //inputData(s, p, 0, 1, checkStaff_1_3);
    semesterList.find(s[0], ACTIVE)->active = 0;
    semesterList.save();
    delete[]s;
    //delete[]p;
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
    staffSemesterMenu();
    cout << "\n[enter]";
    fflush(stdin);
    cin.get();
    fflush(stdin);
    return;
}

bool checkStaff_1_1() {
    return true;
    return false;
}

bool checkStaff_1_2() {
    return false;
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
//    string *s = new string[3]{"", "", ""};
//    fPtr *p = new fPtr[3]{inputSemester, inputClass, filepath};
//    inputData(s, p, 0, 3, checkStaff_3_1);
   
//    semesterID = s[0];
//    classID = s[1];
//    filepath = s[2];
    
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
                lecturerNode->lecturerName = courseNode->lecturerID;
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
   
    if (!semesterList.load()|| !classList.load())
        EXITCODE(6);
    string *s = new string[2]{"", ""};
    //fPtr *p = new fPtr[2]{inputSemester, inputClass};
    //inputData(s, p, 0, 2, checkStaff_1_1);
    
    semesterID = s[0];
    classID = s[1];
    
    if (!courseList.load(semesterID, classID))
        EXITCODE(6);
    //p[0]={inputCourse}
    //s[0] = "";
    //inputData(s,p,0,1,checkStaff_3_2);
    CourseNode *courseNode = new CourseNode;
    //input
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
    cout << "Created successfully[enter]";
    fflush(stdin);
    cin.get();
    fflush(stdin);
    staffSemesterMenu;
    return;
}

void staff_3_3() {
    //Update a specific course
    string semesterID, classID;
    SemesterList semesterList;
    ClassList classList;
    CourseList courseList;
    
    if (!semesterList.load()||!classList.load())
        EXITCODE(6);
    //    string *s = new string[2]{"", ""};
    //    fPtr *p = new fPtr[2]{inputSemester, inputClass};
    //    inputData(s, p, 0, 2, checkStaff_3_3);
    
    //    semesterID = s[0];
    //    classID = s[1];
    
    if (!courseList.load(semesterID,classID))
        EXITCODE(6);
}

void staff_3_4() {
    //Remove a specific course
    string semesterID, classID, courseID;
    SemesterList semesterList;
    ClassList classList;
    CourseList courseList;
    
    if (!semesterList.load()||!classList.load())
        EXITCODE(6);
    //    string *s = new string[3]{"", "",""};
    //    fPtr *p = new fPtr[2]{inputSemester, inputClass,inputCourse};
    //    inputData(s, p, 0, 3, checkStaff_3_4);
    
    //    semesterID = s[0];
    //    classID = s[1];
    //    courseID = s[3];
    
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
//    string *s = new string[2]{"", ""};
//    fPtr *p = new fPtr[2]{inputSemester, inputClass};
//    inputData(s, p, 0, 2, checkStaff_3_5);
    
//    semesterID = s[0];
//    classID = s[1];
    semesterID = "2020-2021hk1";
    classID = "18ctt1";
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
//    string *s = new string[4]{"", "", "", ""};
//    fPtr *p = new fPtr[4]{inputSemester, inputClass,inputCourse, inputStudent};
//    inputData(s, p, 0, 4, checkStaff_3_5);
    
    //    semesterID = s[0];
    //    classID = s[1];
    //    courseID=s[2];
    //    studentID=s[3];
    
    if (!courseList.load(semesterID, classID)||!courseStudentList.load(semesterID,classID,courseID))
        EXITCODE(6);
    courseStudentList.find(studentID, ACTIVE)->active = 0;
    cout << "/n/nSuccessfully deleted student " << studentID;
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
    //    string *s = new string[4]{"", "","",""};
    //    fPtr *p = new fPtr[4]{inputSemester, inputClass, inputStudent, inputCourse};
    //    inputData(s, p, 0, 4, checkStaff_3_7);
    
    //    semesterID = s[0];
    //    classID = s[1];
    //    studentID=s[2];
    //    courseID=s[3];
    
    
    if (!courseList.load(semesterID, classID)|| !courseStudentList.load(semesterID, classID, courseID))
        EXITCODE(6);
    StudentNode* student = new StudentNode;
    //Get information from input.

}

void staff_3_8() {
    //View list of students of a course.
    // inputData : semesterID, classID, courseID
    
   
    StudentList stuList;
    if (!stuList.load()) EXITCODE(6);
    
    string semesterID = "", classID = "", courseID = ""; // Data for testing.
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
	//delete [] s;
	//delete[] p;


}

void staff_3_9() {
    //View a scoreboard
    //inputData: semesterID, classID, courseID

    string semesterID = "", courseID = "", classID = ""; 
    
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

        
        //delete[] s;
        //delete[] p;
}

void staff_3_10() {
    //Export a scoreboard to file.
    // inputData: semesterID, classID, courseID, filePath
    string semesterID = "", courseID = "", classID = "", filePath="";

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
}

void staff_3_11() {
    //View an attendance list
    // inputData: semesterID, classID, courseID

    StudentList stuList;
	if (!stuList.load()) EXITCODE(6);
	
    string semesterID = "", courseID = "", classID = "";

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
   // delete[]s;
    //delete[]p;



}



void staff_3_12() {
    //Export an attendance list to file.
    string semesterID = "", courseID = "", classID = "", filePath = "";

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
}

bool checkStaff_3_1() {
    return false;
}

bool checkStaff_3_2() {
    return false;
}

bool checkStaff_3_3() {
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

bool checkStaff_3_5() {
    return false;
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

bool checkStaff_3_8() {
    return false;
}

bool checkStaff_3_9() {
    return false;
}

bool checkStaff_3_10() {
    return false;
}

bool checkStaff_3_11() {
    return false;
}

bool checkStaff_3_12() {
    return false;
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

