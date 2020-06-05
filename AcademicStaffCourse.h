#pragma once
#ifndef _ACADEMICSTAFFCOURSE_H_
#define _ACADEMICSTAFFCOURSE_H_

#include "Engine.h"

void staff_1_1();

void staff_1_2();

void staff_1_3();

void staff_1_4();

bool checkStaff_1_1();

bool checkStaff_1_2();

bool checkStaff_1_3();

bool checkStaff_1_4();

void lecturer_1();
void lecturer_2();
void lecturer_3();
void lecturer_4();
void lecturer_5();
void lecturer_6();
void lecturer_7();

bool checkLecturer_1();
bool checkLecturer_2();
bool checkLecturer_3();
bool checkLecturer_4();
bool checkLecturer_5();
bool checkLecturer_6();
bool checkLecturer_7();



//
//struct Date
//{
//	int day, month, year;
//};
//
//struct Semester
//{
//	int count;
//	int year;
//	int term;
//	Semester* next=NULL;
//};
//
//struct Course
//{
//	char* ID;
//	char* name;
//	char* className;
//	char* lecturerUsername;
//	char* lecturerName;
//	char* lecturerDegree;
//	char* lecturerGender;
//	Date startDate;
//	Date endDate;
//	int daysOfWeek;
//	int startHour, endHour, startMin, endMin;
//	char* room;
//	Course* next=NULL;
//};
//
//struct Student {
//	int ID;
//	char* password;
//	char* name;
//	Date doB;
//	char* className;
//	int status; 
//	int grade[4]; 
//	int attend[10]; 
//	Student* next = NULL;
//};
//
//void savetxtCourse(ofstream& foutput,Course*& courseHead, int countCourse);
////3.1
//void readSemester(Semester*& semesterHead);
//void createSemester();
//void saveSemester(Semester* semesterHead,int countSe);
//void deleteSemester();
//void viewSemester();
////3.2
//void importSchedule(); //import from csv
////3.3
//Course* inputCourse(); //type to input course
//void addCourse();
////3.4
//void readCourse(ifstream& finput, Course*& courseHead,int &countCourse); //read course txt files
//void editCourse();
////3.5
//void removeCourse();
////3.6
//void readStudentCourse(ifstream& finput, Student*& studentHead,int &countStudentCourse); //read student from course txt files
//void removeStudentCourse();
//void saveStudentCourse(ofstream& foutput, Student* studentHead,int countStudentCourse); //save student to course txt files
////3.7
//void addStudentCourse();
//
//void emptyStudent(Student*& studentHead);
//void emptyCourse(Course*& courseHead);
//void emptySemester(Semester*& semesterHead);
#endif