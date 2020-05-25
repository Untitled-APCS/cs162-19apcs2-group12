#pragma once
#ifndef __Lecturer__
#define __Lecturer__
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


struct CourseNode {
	string id;
	string name;
	
	string lecturer_name;
	string lecturer_username;
	string degree;
	string gender;
	string starting_date;
	string ending_date;
	string day_of_week;
	string starting_hour;
	string ending_hour;
	string room;
	CourseNode* next=nullptr;
};

struct StudentNode {
	string id;
	string password;
	string name;
	string doB;
	string class_;
	string status; // 0:inactive 1:active
	string grade[4]; // midterm->final->bonus->total
	string al[10]; // ten weeks 
	StudentNode* next = nullptr;
};

void input_list_courses(CourseNode*& head, ifstream& fin);
void view_list_courses(CourseNode* head);
void delete_all(CourseNode*& head);
void input_list_student(StudentNode*& head, ifstream& fin);
void view_list_student(StudentNode* head);
void delete_all(StudentNode*& head);
void view_attendance_list(StudentNode* head);
void edit_attendance(StudentNode* head);
void output_to_txt(StudentNode* head, ofstream& fout);
void export_to_csv(StudentNode* head, ofstream& fout);
int  size(StudentNode* head);

#endif
