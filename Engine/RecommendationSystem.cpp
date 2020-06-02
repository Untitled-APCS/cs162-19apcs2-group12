//
// Created by Duc An Chu on 5/31/20.
//

#include "RecommendationSystem.h"


StringNode::StringNode() {

}

bool cmpStringNode(const StringNode &a, const StringNode &b) {
    return false;
}

int getMin(StringNode *stringList, double weight) {
    int ans = -1;
    double minc = weight;

    for (int i = 0; i<=10; i++)
        if (stringList[i].s == "")
            return i;
        else if (stringList[i].weight < minc) {
            minc = stringList[i].weight;
            ans = i;
        }

    return ans;
}

void getRecStudent(string *Rec, string hint) {
    StringNode *stringList = new StringNode [11];

    StudentList studentList;
    studentList.load();
    StudentNode *Tail = nullptr;
    int tmp;
    double weight;

    for (int i = 0; i<studentList.cnt; i++) {
        //check the actual length of the list < cnt?
        Tail = (i == 0 ? studentList.Head : Tail->Next);
        if (Tail == nullptr)
        EXITCODE(6)

        weight = max(similarity(hint, Tail->studentID),
                 max(similarity(hint, Tail->studentName),
                 max(similarity(hint, Tail->studentID + Tail->studentName),
                     similarity(hint, Tail->studentName + Tail->studentID))));
        tmp = getMin(stringList, weight);

        if (tmp == -1) continue;

        stringList[tmp].weight = weight;
        //stringList[tmp].s =
    }
}

void getRecClass(string *Rec, string hint) {

}

void getRecSemester(string *Rec, string hint) {

}

void getRecLecturer(string *Rec, string hint) {

}

void getRecCourse(string semesterID, string classID, string *Rec, string hint) {

}
