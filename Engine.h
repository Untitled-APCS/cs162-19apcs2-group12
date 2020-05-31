//
// Created by Duc An Chu on 5/31/20.
//

#ifndef CS162_19APCS2_GROUP12_ENGINE_H
#define CS162_19APCS2_GROUP12_ENGINE_H

#include "Optimization.h"
#include "StudentList.h"
#include "LecturerList.h"
#include "StaffList.h"
#include "ClassList.h"
#include "SemesterList.h"
#include "ClassStudentList.h"
#include "CourseList.h"
#include "CourseStudentList.h"
#include <time.h>

struct Date {
    int y, m, d;
    Date(int year, int month, int day);
    void nextWeek(); //move to next week
    bool wrongFormat();
};

struct Time {
    int h, m, s;
    Time(); //Default value is the current time
    Time(int hour, int minute, int second);
    void capture(); //Capture the current time
    bool wrongFormat();
};

bool isLeapYear(int y);

int numDaysInMonth(int y, int m); //return the number of days in month m of year y

#endif //CS162_19APCS2_GROUP12_ENGINE_H
