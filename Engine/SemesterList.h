//
// Created by Duc An Chu on 5/31/20.
//

#ifndef CS162_19APCS2_GROUP12_SEMESTERLIST_H
#define CS162_19APCS2_GROUP12_SEMESTERLIST_H

#include "Optimization.h"
#include "DateTime.h"

#define ACTIVE 0
#define ALL 1

#define PREVIOUS 0
#define CURRENT 1
#define NEXT -1

#define CHECKDAMAGED {if (!fin.good()) EXITCODE_V(5, false)};

struct SemesterNode {
    string semesterID;
    bool active, current;
    SemesterNode *Next;

    SemesterNode();
    SemesterNode(string semesterID_, bool active_, int current_, SemesterNode *Next_ = nullptr);
    void print(); //ONLY use for debugging
};

struct SemesterList {
    SemesterNode *Head;
    int cnt;
    static string currentSemester; //current semester, each semester considered to be current ONE time ONLY in program's life-time
                                   //updated whenever either load() or save() is called

    SemesterList();
    ~SemesterList();
    bool load(); //load data from data/semester.txt
    bool save(); //save data to data/semester.txt
    bool pushBack(SemesterNode *semesterNode); //add the node to the end of the list (not create any new node)
    void destroy();
    SemesterNode* find(string semesterID, bool mode); //mode is either ALL (find both active and inactive) or ACTIVE)

    void print(); //ONLY use for debugging
};

#endif //CS162_19APCS2_GROUP12_SEMESTERLIST_H
