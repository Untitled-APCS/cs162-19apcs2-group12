//
// Created by Duc An Chu on 5/26/20.
//

#ifndef CS162_19APCS2_GROUP12_STUDENT_H
#define CS162_19APCS2_GROUP12_STUDENT_H

#include "Engine/stdc++.h"
#include "Engine/Optimization.h"
#include "Engine.h"
#include "Menu.h"

using namespace std;

void checkIn(string username);

void viewCheckInResult(string username);

void viewSchedule(string username);

void viewCourseScore(string username);

#endif //CS162_19APCS2_GROUP12_STUDENT_H

void staff_5_1();

void staff_5_2();

void staff_5_3();

void staff_5_4();

void staff_5_5();

bool checkStaff_5_1();

bool checkStaff_5_2();

bool checkStaff_5_3();

bool checkStaff_5_4();

bool checkStaff_5_5();



void student_1();

void student_2();

void student_3();

void student_4();

bool checkStudent_1();

bool checkStudent_2();

bool checkStudent_3();

bool checkStudent_4();



// Activities:

string getDay(Date date);
void printCourse(CourseNode* node);
bool isInRange(CourseNode* node);