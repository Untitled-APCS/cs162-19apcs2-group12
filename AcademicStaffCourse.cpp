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
    
    SemesterList semesterList;
    if (!semesterList.load())
        EXITCODE(6);
    cout << "\n\n";
    SemesterNode* semesterNode = new SemesterNode;
    string* s = new string[1]{ "" };
    //fPtr* p = new fPtr[1]{ inputSemester};
    //inputData(s, p, 0, 1, checkStaff_1_1);
    semesterNode->active = 1;
    semesterNode->semesterID = s[0];
    semesterList.pushBack(semesterNode);
    semesterList.save();
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
    semesterList.find(s[0], ALL)->active = 0;
    staffSemesterMenu();
    return;
}

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
        temp[0].semesterID = cur->semesterID;
        ++n;
        cur = cur->Next;
    }
    sort(sizeof(temp), sizeof(temp[0]));
    //output: PENDING!
    delete[]temp;
    staffSemesterMenu();
    return;
}

bool checkStaff_1_1() {
    return false;
}

bool checkStaff_1_2() {
    return false;
}

bool checkStaff_1_3() {
    
    return false;
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
}

void staff_3_2() {
    //Create a new courses

    //Input semesterID, classID

    //Input courseID, courseName, lecturerID, startingDate, startingTime, endingTime, room
    //courseID not exist, lecturerID must exist

    
}

void staff_3_3() {

}

void staff_3_4() {

}

void staff_3_5() {

}

void staff_3_6() {

}

void staff_3_7() {

}

void staff_3_8() {

}

void staff_3_9() {

}

void staff_3_10() {

}

void staff_3_11() {

}

void staff_3_12() {

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

bool checkStaff_3_4() {
    return false;
}

bool checkStaff_3_5() {
    return false;
}

bool checkStaff_3_6() {
    return false;
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

