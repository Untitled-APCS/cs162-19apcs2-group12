//
// Created by Duc An Chu on 5/31/20.
//

#ifndef CS162_19APCS2_GROUP12_INPUTDATA_H
#define CS162_19APCS2_GROUP12_INPUTDATA_H

#include "Optimization.h"
#include "FileManagement.h"
#include "RecommendationSystem.h"

typedef bool (*fPtr)(string*, int, int);

bool inputStudent(string *s, int cnt, int x);

bool inputClass(string *s, int cnt, int x);

bool inputSemester(string *s, int cnt, int x);

bool inputCourse(string *s, int cnt, int x);

bool inputLecturer(string *s, int cnt, int x);

bool inputFilePath(string *s, int cnt, int x);

bool inputData(string *s, fPtr *p, int cnt, int x, bool (*check)(string*, int));

#endif //CS162_19APCS2_GROUP12_INPUTDATA_H
