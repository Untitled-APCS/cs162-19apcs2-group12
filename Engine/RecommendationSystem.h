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

bool getRecStudent(string *Rec, string hint);

bool getRecClass(string *Rec, string hint);

bool getRecSemester(string *Rec, string hint);

bool getRecLecturer(string *Rec, string hint);

bool getRecCourse(string semesterID, string classID, string *Rec, string hint);

#endif //CS162_19APCS2_GROUP12_RECOMMENDATIONSYSTEM_H
