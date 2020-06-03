//
// Created by Duc An Chu on 5/31/20.
//

#ifndef CS162_19APCS2_GROUP12_COURSESTUDENTLIST_H
#define CS162_19APCS2_GROUP12_COURSESTUDENTLIST_H

#include "Optimization.h"
#include "DateTime.h"

#define ACTIVE 0
#define ALL 1

#define CHECKDAMAGED {if (!fin.good()) EXITCODE(5)};

struct Score {
    double midterm, final, bonus, total;

    Score();
};

struct CourseStudentNode {
    string studentID;
    Score score;
    int *attendance;
    bool active;
    CourseStudentNode *Next;

    CourseStudentNode();
    CourseStudentNode(string studentID_, Score score_, int *attendance_, bool active_, CourseStudentNode *Next_ = nullptr);
    void print(); //ONLY use for debugging
};

struct CourseStudentList {
    CourseStudentNode *Head;
    int cnt;

    CourseStudentList();
    ~CourseStudentList();
    void load(string semesterID, string classID, string courseID); //load data from data/[semesterID]-[classID]-[courseID]-student.txt,
                                                                   //semesterID, classID and courseID MUST exist in semester.txt, class.txt and [semesterID]-[classID]-course.txt respectively
    void save(string semesterID, string classID, string courseID); //save data to data/[semesterID]-[classID]-[courseID]-student.txt,
                 //semesterID, classID and courseID MUST exist and be active in semester.txt, class.txt and [semesterID]-[classID]-course.txt respectively and
                 //semesterID MUST be the currentSemester
    void pushBack(CourseStudentNode *courseStudentNode); //add the node to the end of the list (not create any new node)
    CourseStudentNode* find(string studentID, bool mode); //mode is either ALL (find both active and inactive) or ACTIVE)

    void print(); //ONLY use for debugging
};

#endif //CS162_19APCS2_GROUP12_COURSESTUDENTLIST_H
