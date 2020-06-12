//
// Created by Duc An Chu on 5/31/20.
//

#ifndef CS162_19APCS2_GROUP12_DATETIME_H
#define CS162_19APCS2_GROUP12_DATETIME_H
#define _CRT_SECURE_NO_WARNINGS

#include "Optimization.h"
#include <time.h>

struct Date {
    int y, m, d;
    Date(int year, int month, int day);
    Date(); //default date is Jan 1st, 2000
    void nextWeek(); //move to next week
    void capture();
    bool wrongFormat();
};

struct Time {
    int h, m, s;
    Time(); //Default value is the current time
    Time(int hour, int minute, int second);
    void capture(); //Capture the current time
    void capture_gm(); //Capture the GMT
    bool wrongFormat();
};

bool isLeapYear(int y);

int numDaysInMonth(int y, int m); //return the number of days in month m of year y

bool operator > (const Date &a, const Date &b);

bool operator < (const Date &a, const Date &b);

bool operator == (const Date &a, const Date &b);

bool operator >= (const Date &a, const Date &b);

bool operator <= (const Date &a, const Date &b);

bool operator > (const Time &a, const Time &b);

bool operator < (const Time &a, const Time &b);

bool operator == (const Time &a, const Time &b);

bool operator >= (const Time &a, const Time &b);

bool operator <= (const Time &a, const Time &b);

#endif //CS162_19APCS2_GROUP12_DATETIME_H
