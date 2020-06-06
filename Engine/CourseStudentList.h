//
// Created by Duc An Chu on 5/31/20.
//

#ifndef CS162_19APCS2_GROUP12_COURSESTUDENTLIST_H
#define CS162_19APCS2_GROUP12_COURSESTUDENTLIST_H

#include "Optimization.h"
#include "DateTime.h"

#define ACTIVE 0
#define ALL 1

#define CHECKDAMAGED {if (!fin.good()) EXITCODE_V(5, false)};

struct Score {
    double midterm, final, bonus, total;

    Score();
};

struct CourseStudentNode {
    string studentID;
    Score score;
    bool *attendance;
    bool active;
    CourseStudentNode *Next;

    CourseStudentNode();
    CourseStudentNode(string studentID_, Score score_, bool *attendance_, bool active_, CourseStudentNode *Next_ = nullptr);
    void print(); //ONLY use for debugging
};

struct CourseStudentList {
    CourseStudentNode *Head;
    int cnt;

    CourseStudentList();
    ~CourseStudentList();
    bool load(string semesterID, string classID, string courseID); //load data from data/[semesterID]-[classID]-[courseID]-student.txt,
                                                                   //semesterID, classID and courseID MUST exist in semester.txt, class.txt and [semesterID]-[classID]-course.txt respectively
    bool save(string semesterID, string classID, string courseID); //save data to data/[semesterID]-[classID]-[courseID]-student.txt,
                 //semesterID, classID and courseID MUST exist and be active in semester.txt, class.txt and [semesterID]-[classID]-course.txt respectively and
                 //semesterID MUST be the currentSemester
    bool pushBack(CourseStudentNode *courseStudentNode); //add the node to the end of the list (not create any new node)
    void destroy();
    CourseStudentNode* find(string studentID, bool mode); //mode is either ALL (find both active and inactive) or ACTIVE)

    void print(); //ONLY use for debugging
};

#endif //CS162_19APCS2_GROUP12_COURSESTUDENTLIST_H
