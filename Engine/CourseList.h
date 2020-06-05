//
// Created by Duc An Chu on 5/31/20.
//

#ifndef CS162_19APCS2_GROUP12_COURSELIST_H
#define CS162_19APCS2_GROUP12_COURSELIST_H

#include "Optimization.h"
#include "DateTime.h"

#define ACTIVE 0
#define ALL 1

#define CHECKDAMAGED {if (!fin.good()) EXITCODE_V(5, false)};

struct CourseNode {
    string courseID, courseName, lecturerID;
    Date startingDate;
    Time startingTime, endingTime;
    string room;
    bool active;
    CourseNode *Next;

    CourseNode();
    CourseNode(string courseID_, string courseName_, string lecturerID_,
                Date startingDate_, Time startingTime_, Time endingTime_, string room_, bool active_, CourseNode *Next_ = nullptr);
    void print(); //ONLY use for debugging
};

struct CourseList {
    CourseNode *Head;
    int cnt;

    CourseList();
    ~CourseList();
    bool load(string semesterID, string classID); //load data from data/[semesterID]-[classID]-course.txt, semesterID and classID MUST exist in class.txt and semester.txt respectively
    bool save(string semesterID, string classID); //save data to data/[semesterID]-[classID]-course.txt, semesterID and classID MUST exist and be active in class.txt and semester.txt respectively
    bool pushBack(CourseNode *courseNode); //add the node to the end of the list (not create any new node)
    CourseNode* find(string courseID, bool mode); //mode is either ALL (find both active and inactive) or ACTIVE)

    void print(); //ONLY use for debugging
};

#endif //CS162_19APCS2_GROUP12_COURSELIST_H
