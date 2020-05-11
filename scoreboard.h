#pragma once
#ifndef __scoreboard__
#define __scoreboard__
#include <iostream>
#include <string>
#include <fstream>
#include  "courses.h"

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
void import_from_csv(BoardNode*& head, ifstream& fin,StudentNode* root, ofstream &fout);
void view_scoreboard(BoardNode* head);
void update_grade(BoardNode* head, StudentNode* root);
void delete_all(BoardNode*& head);
void edit_grade(StudentNode* root);

#endif
