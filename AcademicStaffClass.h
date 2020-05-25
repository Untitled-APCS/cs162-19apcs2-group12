#pragma once
#ifndef _ACADEMICSTAFFCLASS_H_
#define _ACADEMICSTAFFCLASS_H_

#include<iostream>
#include<fstream>

using namespace std;

struct stu
{
    int No, ID;
    char fullname[100], gender[6], clas[10], username[10], password[10];
    int  year, month, day;
    stu* pNext;
};
void importstudent(ifstream& f, stu* student);
void savedata(stu* student, ofstream& f);
void changeclass(stu*& student, ofstream& f, char name[]);
void editstudent(stu* student, ofstream& f, char name[]);
void Int_to_Char(int n, char a[]);
void AddAStudent(stu*& student, ofstream& f);
void RemoveStudent(stu*& student, ofstream& f);
void viewlistofclass();
void viewlistofstudent(stu* student);

#endif