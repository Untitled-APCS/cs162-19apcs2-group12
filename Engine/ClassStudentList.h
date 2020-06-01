//
// Created by Duc An Chu on 5/31/20.
//

#ifndef CS162_19APCS2_GROUP12_CLASSSTUDENTLIST_H
#define CS162_19APCS2_GROUP12_CLASSSTUDENTLIST_H

#include "Optimization.h"
#include "DateTime.h"

#define ACTIVE 0
#define ALL 1

#define CHECKDAMAGED {if (!fin.good()) EXITCODE(5)};

struct ClassStudentNode {
    string studentID;
    bool active;
    ClassStudentNode *Next;

    ClassStudentNode();
    ClassStudentNode(string studentID_, bool active_, ClassStudentNode *Next_);
    void print(); //ONLY use for debugging
};

struct ClassStudentList {
    ClassStudentNode *Head;
    int cnt;

    ClassStudentList();
    ~ClassStudentList();
    void load(string classID); //load data from data/[classID]-student.txt, classID MUST exist in class.txt
    void save(string classID); //save data to data/[classID]-student.txt, classID MUST exist and be active in class.txt
    void pushBack(ClassStudentNode *classStudentNode); //add the node to the end of the list (not create any new node)
    ClassStudentNode* find(string studentID, bool mode); //mode is either ALL (find both active and inactive) or ACTIVE)

    void print(); //ONLY use for debugging
};

#endif //CS162_19APCS2_GROUP12_CLASSSTUDENTLIST_H
