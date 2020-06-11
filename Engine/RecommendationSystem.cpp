//
// Created by Duc An Chu on 5/31/20.
//

#include "RecommendationSystem.h"


StringNode::StringNode() {
    s = "";
    weight = -1;
}

bool cmpStringNode(const StringNode &a, const StringNode &b) {
    //if (b.s == "") return true;
    //if (a.s == "") return b.s == "";

    if (a.weight != b.weight) return a.weight > b.weight;
    return a.s < b.s;
}

int getMin(StringNode *stringList, double weight) {
    int ans = -1;
    double minc = weight;

    for (int i = 1; i<=10; i++)
        if (stringList[i].s == "")
            return i;
        else if (stringList[i].weight < minc) {
            minc = stringList[i].weight;
            ans = i;
        }

    return ans;
}

bool getRecStudent(string *Rec, string hint) {
    StringNode *stringList = new StringNode [11];

    StudentList studentList;
    if (!studentList.load())
        EXITCODE_V(6, false);

    StudentNode *Tail = nullptr;
    int tmp;
    double weight;

    StudentNode *exactNode = studentList.find(hint, ACTIVE);
    if (exactNode != nullptr) {
        stringList[0].s = hint;
        stringList[0].weight = 1;
    }

    for (int i = 0; i<studentList.cnt; i++) {
        //check the actual length of the list < cnt?
        Tail = (i == 0 ? studentList.Head : Tail->Next);
        if (Tail == nullptr)
            EXITCODE_V(6, false)

        if (Tail == exactNode || !Tail->active)
            continue;

        weight = max(similarity(hint, Tail->studentID),
                    max(similarity(hint, Tail->studentName),
                        max(similarity(hint, Tail->studentID + Tail->studentName),
                            similarity(hint, Tail->studentName + Tail->studentID))));

        tmp = getMin(stringList, weight);
        if (tmp == -1) continue;

        stringList[tmp].weight = weight;
        stringList[tmp].s = Tail->studentID;
        //cout << stringList[tmp].s << " " << stringList[tmp].weight << endl;
    }

    //check the actual length of the list > cnt?
    if (studentList.cnt > 0 && Tail->Next != nullptr)
        EXITCODE_V(6, false)

    sort(stringList+1, stringList+11, cmpStringNode);

    for (int i = 0; i<=10; i++)
        Rec[i] = stringList[i].s;

    return true;
}

bool getRecClass(string *Rec, string hint) {
    StringNode *stringList = new StringNode [11];

    ClassList classList;
    if (!classList.load())
    EXITCODE_V(6, false);

    ClassNode *Tail = nullptr;
    int tmp;
    double weight;

    ClassNode *exactNode = classList.find(hint, ACTIVE);
    if (exactNode != nullptr) {
        stringList[0].s = hint;
        stringList[0].weight = 1;
    }

    for (int i = 0; i<classList.cnt; i++) {
        //check the actual length of the list < cnt?
        Tail = (i == 0 ? classList.Head : Tail->Next);
        if (Tail == nullptr)
        EXITCODE_V(6, false)

        if (Tail == exactNode || !Tail->active)
            continue;

        weight = similarity(hint, Tail->classID);

        tmp = getMin(stringList, weight);
        if (tmp == -1) continue;

        stringList[tmp].weight = weight;
        stringList[tmp].s = Tail->classID;
        //cout << stringList[tmp].s << " " << stringList[tmp].weight << endl;
    }

    //check the actual length of the list > cnt?
    if (classList.cnt > 0 && Tail->Next != nullptr)
    EXITCODE_V(6, false)

    sort(stringList+1, stringList+11, cmpStringNode);

    for (int i = 0; i<=10; i++)
        Rec[i] = stringList[i].s;

    return true;
}

bool getRecSemester(string *Rec, string hint) {
    StringNode *stringList = new StringNode [11];

    SemesterList semesterList;
    if (!semesterList.load())
    EXITCODE_V(6, false);

    SemesterNode *Tail = nullptr;
    int tmp;
    double weight;

    SemesterNode *exactNode = semesterList.find(hint, ACTIVE);
    if (exactNode != nullptr) {
        stringList[0].s = hint;
        stringList[0].weight = 1;
    }

    for (int i = 0; i<semesterList.cnt; i++) {
        //check the actual length of the list < cnt?
        Tail = (i == 0 ? semesterList.Head : Tail->Next);
        if (Tail == nullptr)
        EXITCODE_V(6, false)

        if (Tail == exactNode || !Tail->active)
            continue;

        weight = similarity(hint, Tail->semesterID);

        tmp = getMin(stringList, weight);
        if (tmp == -1) continue;

        stringList[tmp].weight = weight;
        stringList[tmp].s = Tail->semesterID;
        //cout << stringList[tmp].s << " " << stringList[tmp].weight << endl;
    }

    //check the actual length of the list > cnt?
    if (semesterList.cnt > 0 && Tail->Next != nullptr)
    EXITCODE_V(6, false)

    sort(stringList+1, stringList+11, cmpStringNode);

    for (int i = 0; i<=10; i++)
        Rec[i] = stringList[i].s;

    return true;
}

bool getRecLecturer(string *Rec, string hint) {
    StringNode *stringList = new StringNode [11];

    LecturerList lecturerList;
    if (!lecturerList.load())
    EXITCODE_V(6, false);

    LecturerNode *Tail = nullptr;
    int tmp;
    double weight;

    LecturerNode *exactNode = lecturerList.find(hint, ACTIVE);
    if (exactNode != nullptr) {
        stringList[0].s = hint;
        stringList[0].weight = 1;
    }

    for (int i = 0; i<lecturerList.cnt; i++) {
        //check the actual length of the list < cnt?
        Tail = (i == 0 ? lecturerList.Head : Tail->Next);
        if (Tail == nullptr)
        EXITCODE_V(6, false)

        if (Tail == exactNode || !Tail->active)
            continue;

        weight = max(similarity(hint, Tail->lecturerID),
                     max(similarity(hint, Tail->lecturerName),
                         max(similarity(hint, Tail->lecturerID + Tail->lecturerName),
                             similarity(hint, Tail->lecturerName + Tail->lecturerID))));

        tmp = getMin(stringList, weight);
        if (tmp == -1) continue;

        stringList[tmp].weight = weight;
        stringList[tmp].s = Tail->lecturerID;
        //cout << stringList[tmp].s << " " << stringList[tmp].weight << endl;
    }

    //check the actual length of the list > cnt?
    if (lecturerList.cnt > 0 && Tail->Next != nullptr)
    EXITCODE_V(6, false)

    sort(stringList+1, stringList+11, cmpStringNode);

    for (int i = 0; i<=10; i++)
        Rec[i] = stringList[i].s;

    return true;
}

bool getRecCourse(string semesterID, string classID, string *Rec, string hint) {
    StringNode *stringList = new StringNode [11];

    CourseList courseList;
    if (!courseList.load(semesterID, classID))
    EXITCODE_V(6, false);

    CourseNode *Tail = nullptr;
    int tmp;
    double weight;

    CourseNode *exactNode = courseList.find(hint, ACTIVE);
    if (exactNode != nullptr) {
        stringList[0].s = hint;
        stringList[0].weight = 1;
    }

    for (int i = 0; i<courseList.cnt; i++) {
        //check the actual length of the list < cnt?
        Tail = (i == 0 ? courseList.Head : Tail->Next);
        if (Tail == nullptr)
        EXITCODE_V(6, false)

        if (Tail == exactNode || !Tail->active)
            continue;

        weight = max(similarity(hint, Tail->courseID),
                     max(similarity(hint, Tail->courseName),
                         max(similarity(hint, Tail->courseID + Tail->courseName),
                             similarity(hint, Tail->courseName + Tail->courseID))));

        tmp = getMin(stringList, weight);
        if (tmp == -1) continue;

        stringList[tmp].weight = weight;
        stringList[tmp].s = Tail->courseID;
        //cout << stringList[tmp].s << " " << stringList[tmp].weight << endl;
    }

    //check the actual length of the list > cnt?
    if (courseList.cnt > 0 && Tail->Next != nullptr)
    EXITCODE_V(6, false)

    sort(stringList+1, stringList+11, cmpStringNode);

    for (int i = 0; i<=10; i++)
        Rec[i] = stringList[i].s;

    return true;
}

