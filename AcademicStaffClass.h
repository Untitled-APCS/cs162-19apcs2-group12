#pragma once
#ifndef _ACADEMICSTAFFCLASS_H_
#define _ACADEMICSTAFFCLASS_H_

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

struct stu
{
    int No, ID;
    char fullname[100], gender[6], clas[10], username[10], password[10];
    int  year, month, day;
    stu* pNext;
};
stu* importstudent();
void savedata(stu* student, ofstream& f);
void changeclass();
void editstudent();
void Int_to_Char();
void AddAStudent();
void RemoveStudent();
void viewlistofclass();
void viewlistofstudent();

#endif