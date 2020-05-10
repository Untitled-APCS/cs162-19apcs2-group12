#pragma once
#ifndef _ACADEMICSTAFFCOURSE_H_
#define _ACADEMICSTAFFCOURSE_H_

struct Date
{
	int day, month, year;
};

struct stu
{
	int No, ID;
	char lastname[50], firstname[50], gender[6];
	int  year, month, day;
	stu* pNext;
};

struct Semester
{
	int count;
	int year;
	int term;
	Semester* next=NULL;
};

struct Course
{
	char* ID;
	char* name;
	char* className;
	char* lecturerUsername;
	char* lecturerName;
	char* lecturerDegree;
	char* lecturerGender;
	Date startDate;
	Date endDate;
	int daysOfWeek;
	int startHour, endHour, startMin, endMin;
	char* room;
	Course* next=NULL;
};

//3.1
void createSemester(Semester*& semesterHead);
void saveSemester(Semester* semesterHead, ofstream& foutput);
void deleteSemester(Semester*& semesterHead);
void viewSemester(Semester* semesterHead);
//3.2
void importSchedule(ifstream& finput, ofstream& foutput, Course*& courseHead, Semester* semesterHead);
//3.3
Course* inputCourse();
void addCourse(ofstream& foutput, Semester* semesterHead);
//3.4
void readCourse(ifstream& finput, Course*& courseHead);
void editCourse(ifstream& finput, ofstream& foutput, Semester* semesterHead, Course*& courseHead);
#endif
