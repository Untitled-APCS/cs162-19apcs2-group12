#pragma once
#ifndef _ACADEMICSTAFFCOURSE_H_
#define _ACADEMICSTAFFCOURSE_H_

#include "Engine.h"
#include "Menu.h"
#include "Lecturer.h"

#define ScoreBoard 1
#define AttendanceList 0

void staff_1_1();

void staff_1_2();

void staff_1_3();

void staff_1_4();

void staff_3_1();

void staff_3_2();

void staff_3_3();

void staff_3_4();

void staff_3_5();

void staff_3_6();

void staff_3_7();

void staff_3_8();

void staff_3_9();

void staff_3_10();

void staff_3_11();

void staff_3_12();

bool checkStaff_3_1();

bool checkStaff_3_2();

bool checkStaff_3_3();

bool checkStaff_3_4(string* s,int n);

bool checkStaff_3_5(string* s, int n);

bool checkStaff_3_6();

bool checkStaff_3_7();

bool checkStaff_3_8();

bool checkStaff_3_9();

bool checkStaff_3_10();

bool checkStaff_3_11();

bool checkStaff_3_12();

bool checkStaff_1_1(string* s,int n);

bool checkStaff_1_2();

bool checkStaff_1_3(string* s, int n);

bool checkStaff_1_4();


void ScoreBoardFormat(CourseStudentList llist, ofstream& fout);
void AttendanceListFormat(CourseStudentList llist, ofstream& fout);
void saveCSV(CourseStudentList llist, string filePath, bool mode);


#endif