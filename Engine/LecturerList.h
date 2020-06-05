//
// Created by Duc An Chu on 5/31/20.
//

#ifndef CS162_19APCS2_GROUP12_LECTURERLIST_H
#define CS162_19APCS2_GROUP12_LECTURERLIST_H

#include "Optimization.h"

#define ACTIVE 0
#define ALL 1

#define CHECKDAMAGED {if (!fin.good()) EXITCODE_V(5, false)};

struct LecturerNode {
    string lecturerID, password, lecturerName, academicTitle;
    bool gender, active;
    LecturerNode *Next;

    LecturerNode();
    LecturerNode(string lecturerID_, string password_, string lecturerName_,
                 string academicTitle_, bool gender_, bool active_, LecturerNode *Next_ = nullptr);
    void print(); //ONLY use for debugging
};

struct LecturerList {
    LecturerNode *Head;
    int cnt;

    LecturerList();
    ~LecturerList();
    bool load(); //load data from data/lecturer.txt
    bool save(); //save data to data/lecturer.txt
    bool pushBack(LecturerNode *lecturerNode); //add the node to the end of the list (not create any new node)
    LecturerNode* find(string lecturerID, bool mode); //mode is either ALL (find both active and inactive) or ACTIVE)

    void print(); //ONLY use for debugging
};

#endif //CS162_19APCS2_GROUP12_LECTURERLIST_H
