#pragma once
#ifndef __AcademicStaffScoreBoard__
#define __AcademicStaffScoreBoard__
#include <iostream>
#include <string>
#include <fstream>
#include "Lecturer.h"

using namespace std;
struct BoardNode {
	string no;
	string student_id;
	string id;
	string fullname;
	string class_;
	string grade[4];// midterm->final->bonus->total
	BoardNode* next = nullptr;
};
// Khang's part:
void import_from_csv(BoardNode*& head, ifstream& fin,StudentNode* root, ofstream &fout, string& coursename);
void update_grade(BoardNode* head, StudentNode* root);
void delete_all(BoardNode*& head);
// Activities:
void view_scoreboard();
void edit_grade();
void import_scoreboard();


//Kiet's part
void outputScoreboard(BoardNode* pHead);
void exportscoreboard(BoardNode* pHead, ofstream& f);

#endif
