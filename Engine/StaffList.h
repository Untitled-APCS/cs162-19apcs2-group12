//
// Created by Duc An Chu on 5/31/20.
//

#ifndef CS162_19APCS2_GROUP12_STAFFLIST_H
#define CS162_19APCS2_GROUP12_STAFFLIST_H

#include "Optimization.h"
#include "DateTime.h"

#define ACTIVE 0
#define ALL 1

#define CHECKDAMAGED {if (!fin.good()) EXITCODE(5)};

struct StaffNode {
    string staffID, password, staffName;
    bool gender;
    StaffNode *Next;

    StaffNode();
    StaffNode(string staffID_, string password_, string staffName_,
              bool gender_, StaffNode *Next_);
    void print(); //ONLY use for debugging
};

struct StaffList {
    StaffNode *Head;
    int cnt;

    StaffList();
    ~StaffList();
    void load(); //load data from data/staff.txt
    StaffNode* find(string staffID); //mode is either ALL (find both active and inactive) or ACTIVE)

    void print(); //ONLY use for debugging
};

#endif //CS162_19APCS2_GROUP12_STAFFLIST_H