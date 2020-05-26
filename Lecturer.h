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
void delete_all(CourseNode*& head);
void input_list_student(StudentNode*& head, ifstream& fin, string& coursename);
void delete_all(StudentNode*& head);
void output_to_txt(StudentNode* head, ofstream& fout, string& coursename);
int  size(StudentNode* head);

// Activities:
void export_to_csv();
void edit_attendance();
void view_attendance_list();
void view_list_courses();
void view_list_student();



#endif