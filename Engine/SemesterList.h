//
// Created by Duc An Chu on 5/31/20.
//

#ifndef CS162_19APCS2_GROUP12_SEMESTERLIST_H
#define CS162_19APCS2_GROUP12_SEMESTERLIST_H

#include "Optimization.h"
#include "DateTime.h"

#define ACTIVE 0
#define ALL 1

#define CHECKDAMAGED {if (!fin.good()) EXITCODE(5)};

struct SemesterNode {
    string semesterID;
    bool active, current;
    SemesterNode *Next;

    SemesterNode();
    SemesterNode(string semesterID_, bool active_, bool current_, SemesterNode *Next_);
    void print(); //ONLY use for debugging
};

struct SemesterList {
    SemesterNode *Head;
    int cnt;

    SemesterList();
    ~SemesterList();
    void load(); //load data from data/semester.txt
    void save(); //save data to data/semester.txt
    void pushBack(SemesterNode *semesterNode); //add the node to the end of the list (not create any new node)
    SemesterNode* find(string semesterID, bool mode); //mode is either ALL (find both active and inactive) or ACTIVE)

    void print(); //ONLY use for debugging
};

#endif //CS162_19APCS2_GROUP12_SEMESTERLIST_H
