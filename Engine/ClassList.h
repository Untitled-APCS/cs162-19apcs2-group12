//
// Created by Duc An Chu on 5/31/20.
//

#ifndef CS162_19APCS2_GROUP12_CLASSLIST_H
#define CS162_19APCS2_GROUP12_CLASSLIST_H

#include "Optimization.h"
#include "DateTime.h"

#define ACTIVE 0
#define ALL 1

#define forNode(NodeType, i, List) for(TypeNode i = List.Head, i, i = i->Next)

#define CHECKDAMAGED {if (!fin.good()) EXITCODE_V(5, false)};

struct ClassNode {
    string classID;
    bool active;
    ClassNode *Next;

    ClassNode();
    ClassNode(string classID_, bool active_, ClassNode *Next_ = nullptr);
    void print(); //ONLY use for debugging
};

struct ClassList {
    ClassNode *Head;
    int cnt;

    ClassList();
    ~ClassList();
    bool load(); //load data from data/class.txt
    bool save(); //save data to data/class.txt
    bool pushBack(ClassNode *classNode); //add the node to the end of the list (not create any new node)
    ClassNode* find(string classID, bool mode); //mode is either ALL (find both active and inactive) or ACTIVE)

    void print(); //ONLY use for debugging
};

#endif //CS162_19APCS2_GROUP12_CLASSLIST_H
