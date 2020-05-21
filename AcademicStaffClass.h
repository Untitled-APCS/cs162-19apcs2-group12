#pragma once
#ifndef _ACADEMICSTAFFCLASS_H_
#define _ACADEMICSTAFFCLASS_H_

#include<iostream>
#include<fstream>

using namespace std;

struct stu
{
    int No, ID;
    char lastname[50], firstname[50], gender[6], clas[10], username[10], password[10];
    int  year, month, day;
    stu* pNext;
};


#endif