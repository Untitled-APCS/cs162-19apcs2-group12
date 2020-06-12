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

bool inputPathClassListCSV(string *s, int cnt, int x);

bool inputPathCourseListCSV(string *s, int cnt, int x);

bool inputPathLecturerListCSV(string *s, int cnt, int x);

bool inputPathStudentListCSV(string *s, int cnt, int x);

bool inputPathScoreBoardListCSV(string *s, int cnt, int x);

bool inputPathExportCSV(string *s, int cnt, int x);

bool inputData(string *s, fPtr *p, int cnt, int x, bool (*check)(string*, int));

void refreshPathList(PathList &pathList, string &path, int &page, bool (*checkPath)(string), string *hint, int n);

void refreshFolderList(PathList &pathList, string &path, int &page);

#endif //CS162_19APCS2_GROUP12_INPUTDATA_H
