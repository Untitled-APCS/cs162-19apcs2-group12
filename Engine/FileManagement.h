//
// Created by Duc An Chu on 5/31/20.
//

#ifndef CS162_19APCS2_GROUP12_FILEMANAGEMENT_H
#define CS162_19APCS2_GROUP12_FILEMANAGEMENT_H

#include "Optimization.h"

const string ClassListHeader = "No,Class ID";
const int numCommaClassList = 1;

const string CourseListHeader = "No,Course ID,Course Name,Lecturer ID,Starting Date (yyyy/mm/dd),Starting Time (hh:mm:ss),EndingTime (hh:mm:ss),Room";
const int numCommaCourseList = 7;

const string LecturerListHeader = "No,Lecturer ID,Lecturer Name,Academic Title,Gender (1-Male/0-Female)";
const int numCommaLecturerList = 4;

const string StudentListHeader = "No,Student ID,Student Name,DOB (yyyy/mm/dd)";
const int numCommaStudentList = 3;

const string ScoreBoardListHeader = "No,Student ID,Midterm,Final,Bonus,Total,W01,W02,W03,W04,W05,W06,W07,W08,W09,W10";
const int numCommaScoreBoardList = 15;

struct PathNode {
    string path;
    int weight;

    PathNode();
};

struct PathList {
    PathNode *c;
    int cnt;

    PathList();
    ~PathList();

    void getDirectoryList(string path, bool (*checkPath)(string), string *hint, int n);
};

bool cmpPath(const PathNode &a, const PathNode &b);

bool isClassListCSV(string filePath);

bool isCourseListCSV(string filePath);

bool isLecturerListCSV(string filePath);

bool isStudentListCSV(string filePath);

bool isScoreBoardListCSV(string filePath);

int numComma(string s);


#endif //CS162_19APCS2_GROUP12_FILEMANAGEMENT_H
