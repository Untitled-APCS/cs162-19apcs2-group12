#pragma once
#ifndef _ACADEMICSTAFFCOURSE_H_
#define _ACADEMICSTAFFCOURSE_H_

#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;

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

struct Student {
	int ID;
	char* password;
	char* name;
	Date doB;
	char* className;
	int status; 
	int grade[4]; 
	int attend[10]; 
	Student* next = NULL;
};

void savetxtCourse(ofstream& foutput,Course*& courseHead);
//3.1
void createSemester(Semester*& semesterHead);
void saveSemester(Semester* semesterHead, ofstream& foutput);
void deleteSemester(Semester*& semesterHead);
void viewSemester(Semester* semesterHead);
//3.2
void importSchedule(ifstream& finput, ofstream& foutput, Course*& courseHead, Semester* semesterHead); //import from csv
//3.3
Course* inputCourse(); //type to input course
void addCourse(ofstream& foutput, Semester* semesterHead);
//3.4
void readCourse(ifstream& finput, Course*& courseHead); //read course txt files
void editCourse(ifstream& finput, ofstream& foutput, Semester* semesterHead, Course*& courseHead);
//3.5
void removeCourse(Course*& courseHead);
//3.6
void readStudentCourse(ifstream& finput, Student*& studentHead); //read student from course txt files
void removeStudentCourse(ifstream& finput, ofstream& foutput, Course*& courseHead, Semester* semesterHead, Student*& studentHead);
void saveStudentCourse(ofstream& foutput, Student* studentHead); //save student to course txt files
//3.7
void addStudentCourse(ifstream& finput, ofstream& foutput, Student*& studentHead, Semester* semesterHead);

void emptyStudent(Student*& studentHead);
void emptyCourse(Course*& courseHead);
void emptySemester(Semester*& semesterHead);
#endif
