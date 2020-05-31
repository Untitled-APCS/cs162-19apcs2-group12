//
// Created by Duc An Chu on 5/31/20.
//

#include "Engine.h"

Date::Date(int year, int month, int day) {
    y = year;
    m = month;
    d = day;
}

void Date::nextWeek() {
    d += 7;

    if (d > numDaysInMonth(y, m)) {
        d -= numDaysInMonth(y, m);
        m++;

        if (m > 12) {
            m = 1;
            y++;
        }
    }

    if (wrongFormat()) EXITCODE(2)
}

bool Date::wrongFormat() {
    return (Date::m < 1 || Date::m > 12 || Date::d < 1 ||
            Date::d > numDaysInMonth(Date::y, Date::m));
}


Time::Time() {
    capture();
}

void Time::capture() {
    time_t cur;
    time(&cur);
    tm *localTime = localtime(&cur);

    h = localTime->tm_hour;
    m = localTime->tm_min;
    s = localTime->tm_sec;
}

Time::Time(int hour, int minute, int second) {
    h = hour;
    m = minute;
    s = second;

    if (wrongFormat())
        exitProgram(1);
}

bool Time::wrongFormat() {
    return h < 0 || h > 23 ||
           m < 0 || m > 59 ||
           s < 0 || s > 59;
}

bool isLeapYear(int y) {
    return (y % 4 == 0 && y % 100 != 0 || y % 400 == 0);
}

int numDaysInMonth(int y, int m) {
    switch (m) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        case 2:
            return (isLeapYear(y) ? 29 : 28);
        default:
            EXITCODE_V(1, 0)
    }
}
