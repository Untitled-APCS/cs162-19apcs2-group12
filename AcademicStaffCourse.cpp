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
}

void staff_1_3() {
    //Remove a specific semester

    //Input semesterID
    //semesterID is not current but is active

    //remove semesterID: active -> 0
}

void staff_1_4() {
    //View list of semester

    //Input nothing

    //View list of active semesters
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

