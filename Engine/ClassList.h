//
// Created by Duc An Chu on 5/31/20.
//

#ifndef CS162_19APCS2_GROUP12_CLASSLIST_H
#define CS162_19APCS2_GROUP12_CLASSLIST_H

#include "Optimization.h"
#include "DateTime.h"

#define ACTIVE 0
#define ALL 1

#define CHECKDAMAGED {if (!fin.good()) EXITCODE(5)};

struct ClassNode {
    string classID;
    bool active;
    ClassNode *Next;

    ClassNode();
    ClassNode(string classID_, bool active_, ClassNode *Next_);
    void print(); //ONLY use for debugging
};

struct ClassList {
    ClassNode *Head;
    int cnt;

    ClassList();
    ~ClassList();
    void load(); //load data from data/class.txt
    void save(); //save data to data/class.txt
    void pushBack(ClassNode *classNode); //add the node to the end of the list (not create any new node)
    ClassNode* find(string classID, bool mode); //mode is either ALL (find both active and inactive) or ACTIVE)

    void print(); //ONLY use for debugging
};

#endif //CS162_19APCS2_GROUP12_CLASSLIST_H
