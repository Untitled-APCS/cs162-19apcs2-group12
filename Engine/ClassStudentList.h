//
// Created by Duc An Chu on 5/31/20.
//

#ifndef CS162_19APCS2_GROUP12_CLASSSTUDENTLIST_H
#define CS162_19APCS2_GROUP12_CLASSSTUDENTLIST_H

#include "Optimization.h"
#include "DateTime.h"

#define ACTIVE 0
#define ALL 1

#define CHECKDAMAGED {if (!fin.good()) EXITCODE_V(5, false)};

struct ClassStudentNode {
    string studentID;
    bool active;
    ClassStudentNode *Next;

    ClassStudentNode();
    ClassStudentNode(string studentID_, bool active_, ClassStudentNode *Next_ = nullptr);
    void print(); //ONLY use for debugging
};

struct ClassStudentList {
    ClassStudentNode *Head;
    int cnt;

    ClassStudentList();
    ~ClassStudentList();
    bool load(string classID); //load data from data/[classID]-student.txt, classID MUST exist in class.txt
    bool save(string classID); //save data to data/[classID]-student.txt, classID MUST exist and be active in class.txt
    bool pushBack(ClassStudentNode *classStudentNode); //add the node to the end of the list (not create any new node)
    void destroy();
    ClassStudentNode* find(string studentID, bool mode); //mode is either ALL (find both active and inactive) or ACTIVE)

    void print(); //ONLY use for debugging
};

#endif //CS162_19APCS2_GROUP12_CLASSSTUDENTLIST_H
