//
// Created by Duc An Chu on 5/31/20.
//

#include "CourseStudentList.h"

Score::Score() {
    midterm = final = bonus = total = -1;
}

CourseStudentNode::CourseStudentNode() {
    attendance = new bool [10];
    for (int i = 0; i<10; i++)
        attendance[i] = false;

    Next = nullptr;
}

CourseStudentNode::CourseStudentNode(string studentID_, Score score_, bool *attendance_, bool active_,
                                     CourseStudentNode *Next_) {
    studentID = studentID_;
    score = score_;
    attendance = attendance_;
    active = active_;
    Next = Next_;
}

void CourseStudentNode::print() {
    cout << "Student ID: " << studentID << endl;
    cout << "Scores: " << score.midterm << " " << score.final << " " << score.bonus << " " << score.total << endl;
    cout << "Attendance: ";
    for (int i = 0; i<10; i++)
        cout << attendance[i] << " ";
    cout << endl;
    cout << "Active: " << active << endl;
}

CourseStudentList::CourseStudentList() {
    Head = nullptr;
    cnt = 0;
}

CourseStudentList::~CourseStudentList() {
    destroy();
}

void CourseStudentList::destroy() {
    CourseStudentNode *tmp;
    while (Head != nullptr) {
        tmp = Head;
        Head = Head->Next;

        delete [] tmp->attendance;
        delete tmp;
    }

    cnt = 0;
}

bool CourseStudentList::load(string semesterID, string classID, string courseID) {
    ifstream fin;
    fin.open(getLocation() + "data/" + semesterID + "-" + classID + "-" + courseID + "-student.txt");

    //check if the file is missing?
    if (!fin.is_open())
    EXITCODE_V(4, false);

    fin >> cnt;
    string tmp;
    getline(fin, tmp);
    CourseStudentNode *Tail = nullptr;

    for (int i = 0; i<cnt; i++) {
        //create a new node
        if (Head == nullptr)
            Head = Tail = new CourseStudentNode;
        else
            Tail = Tail->Next = new CourseStudentNode;

        CHECKDAMAGED
        getline(fin, Tail->studentID);

        CHECKDAMAGED
        fin >> Tail->score.midterm;
        CHECKDAMAGED
        fin >> Tail->score.final;
        CHECKDAMAGED
        fin >> Tail->score.bonus;
        CHECKDAMAGED
        fin >> Tail->score.total;
        getline(fin, tmp);

        CHECKDAMAGED
        for (int i = 0; i<10; i++)
            fin >> Tail->attendance[i];
        getline(fin, tmp);

        CHECKDAMAGED
        fin >> Tail->active;
        getline(fin, tmp);
    }

    fin.close();
    return true;
}

bool CourseStudentList::save(string semesterID, string classID, string courseID) {
    ofstream fout;
    fout.open(getLocation() + "data/" + semesterID + "-" + classID + "-" + courseID + "-student.txt");

    //check if the file is missing?
    if (!fout.is_open())
    EXITCODE_V(4, false);

    fout << cnt << endl;
    CourseStudentNode *Tail = nullptr;

    for (int i = 0; i<cnt; i++) {
        //check the actual length of the list < cnt?
        Tail = (i == 0 ? Head : Tail->Next);
        if (Tail == nullptr)
        EXITCODE_V(6, false)

        fout << Tail->studentID << endl;
        fout << Tail->score.midterm << " " << Tail->score.final << " " << Tail->score.bonus << " " << Tail->score.total << endl;
        for (int i = 0; i<10; i++)
            fout << Tail->attendance[i] << " ";
        fout << endl;
        fout << Tail->active << endl;
    }

    //check the actual length of the list > cnt?
    if (cnt > 0 && Tail->Next != nullptr)
    EXITCODE_V(6, false)

    return true;
}

bool CourseStudentList::pushBack(CourseStudentNode *courseStudentNode) {
    if (Head == nullptr && cnt == 0) {
        Head = courseStudentNode;
        cnt++;
        return true;
    }

    CourseStudentNode *Tail = nullptr;

    for (int i = 0; i<cnt; i++) {
        //check the actual length of the list < cnt?
        Tail = (i == 0 ? Head : Tail->Next);
        if (Tail == nullptr)
        EXITCODE_V(6, false)
    }

    //check the actual length of the list > cnt?
    if (cnt > 0 && Tail->Next != nullptr)
    EXITCODE_V(6, false)
    else {
        Tail->Next = courseStudentNode;
        cnt++;
    }

    return true;
}

CourseStudentNode *CourseStudentList::find(string studentID, bool mode) {
    CourseStudentNode *Tail = nullptr;

    for (int i = 0; i<cnt; i++) {
        //check the actual length of the list < cnt?
        Tail = (i == 0 ? Head : Tail->Next);
        if (Tail == nullptr)
        EXITCODE_V(6, nullptr)

        if (Tail->active || mode == ALL) {
            if (Tail->studentID == studentID)
                return Tail;
        }
    }

    if (cnt > 0 && Tail->Next != nullptr)
    EXITCODE_V(6, nullptr)
    else
        return nullptr;
}

void CourseStudentList::print() {
    CourseStudentNode *Tail = nullptr;

    for (int i = 0; i<cnt; i++) {
        //check the actual length of the list < cnt?
        Tail = (i == 0 ? Head : Tail->Next);
        if (Tail == nullptr)
        EXITCODE(6)

        Tail->print();
    }
}
