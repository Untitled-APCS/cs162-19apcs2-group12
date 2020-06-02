//
// Created by Duc An Chu on 5/31/20.
//

#ifndef CS162_19APCS2_GROUP12_RECOMMENDATIONSYSTEM_H
#define CS162_19APCS2_GROUP12_RECOMMENDATIONSYSTEM_H

#include "Optimization.h"
#include "StudentList.h"
#include "ClassList.h"
#include "SemesterList.h"
#include "LecturerList.h"
#include "CourseList.h"

struct StringNode {
    string s;
    double weight;

    StringNode();
};

bool cmpStringNode(const StringNode &a, const StringNode &b);

int getMin(StringNode *stringList, double weight);

void getRecStudent(string *Rec, string hint);

void getRecClass(string *Rec, string hint);

void getRecSemester(string *Rec, string hint);

void getRecLecturer(string *Rec, string hint);

void getRecCourse(string semesterID, string classID, string *Rec, string hint);

#endif //CS162_19APCS2_GROUP12_RECOMMENDATIONSYSTEM_H
