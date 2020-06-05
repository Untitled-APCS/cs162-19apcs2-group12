#include "AcademicStaffClass.h"

void staff_2_1() {
    //Import list of classes from file

    //import filepath

    //loadCSV
}

void staff_2_2() {
    //Create a new class

    //Input nothing

    //Input classID not exist in class list

    //pushBack --> save to class list
    //create [semesterID]-classID-course.txt with 0 course
}

void staff_2_3() {
    //Update a specific class

    //Input oldClass which is active

    //Input newClassID which does not exist in class list
    //Update oldClassID to newClassID

    //copy all files [semesterID]-newClassID-course.txt to semesterID-newClassID-course.txt
    //each file [semesterID]-newClassID-course.txt, copy all files [semesterID]-newClassID-[courseID]-student.txt to [semesterID]-newClassID-[courseID]-student.txt

    //EX:
//    courseList.load(semesterID, oldClassID);
//    courseList.save(semesterID, newClassID);


}

void staff_2_4() {
    //Remove a specific class

    //Input classID which is active

    //remove classID: active -> 0
}

void staff_2_5() {
    //View list of classes

    //Input nothing

    //View list of active classes
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
