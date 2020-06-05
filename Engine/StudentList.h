//
// Created by Duc An Chu on 5/31/20.
//

#ifndef CS162_19APCS2_GROUP12_STUDENTLIST_H
#define CS162_19APCS2_GROUP12_STUDENTLIST_H

#include "Optimization.h"
#include "DateTime.h"

#define ACTIVE 0
#define ALL 1

#define CHECKDAMAGED {if (!fin.good()) EXITCODE_V(5, false)};

struct StudentNode {
    string studentID, password, studentName;
    Date DOB;
    string classID;
    bool active;
    StudentNode *Next;

    StudentNode();
    StudentNode(string studentID_, string password_, string studentName_,
                Date DOB_, string classID_, bool active_, StudentNode *Next_ = nullptr);
    void print(); //ONLY use for debugging
};

struct StudentList {
    StudentNode *Head;
    int cnt;

    StudentList();
    ~StudentList();
    bool load(); //load data from data/student.txt
    bool save(); //save data to data/student.txt
    bool pushBack(StudentNode *studentNode); //add the node to the end of the list (not create any new node)
    StudentNode* find(string studentID, bool mode); //mode is either ALL (find both active and inactive) or ACTIVE)

    void print(); //ONLY use for debugging
};

#endif //CS162_19APCS2_GROUP12_STUDENTLIST_H
