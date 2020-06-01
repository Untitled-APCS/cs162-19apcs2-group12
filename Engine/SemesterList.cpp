//
// Created by Duc An Chu on 5/31/20.
//

#include "SemesterList.h"

SemesterNode::SemesterNode() {
    Next = nullptr;
}

SemesterNode::SemesterNode(string semesterID_, bool active_, bool current_, SemesterNode *Next_) {
    semesterID = semesterID_;
    active = active_;
    current = current_;
}

void SemesterNode::print() {
    cout << "Semester ID: " << semesterID << endl;
    cout << "Active: " << active << endl;
    cout << "Current: " << current << endl;
}

SemesterList::SemesterList() {
    Head = nullptr;
    cnt = 0;
}

SemesterList::~SemesterList() {
    SemesterNode *tmp;
    while (Head != nullptr) {
        tmp = Head;
        Head = Head->Next;
        delete tmp;
    }
}

void SemesterList::load() {
    ifstream fin;
    fin.open("data/semester.txt");

    //check if the file is missing?
    if (!fin.is_open())
    EXITCODE(4);

    fin >> cnt;
    string tmp;
    getline(fin, tmp);
    SemesterNode *Tail;

    for (int i = 0; i<cnt; i++) {
        //create a new node
        if (Head == nullptr)
            Head = Tail = new SemesterNode;
        else
            Tail = Tail->Next = new SemesterNode;

        CHECKDAMAGED
        getline(fin, Tail->semesterID);

        CHECKDAMAGED
        fin >> Tail->active;
        getline(fin, tmp);

        CHECKDAMAGED
        fin >> Tail->current;
        getline(fin, tmp);
    }

    fin.close();
}

void SemesterList::save() {
    ofstream fout;
    fout.open("data/student.txt");

    //check if the file is missing?
    if (!fout.is_open())
    EXITCODE(4);

    fout << cnt << endl;
    SemesterNode *Tail;

    for (int i = 0; i<cnt; i++) {
        //check the actual length of the list < cnt?
        Tail = (i == 0 ? Head : Tail->Next);
        if (Tail == nullptr)
        EXITCODE(6)

        fout << Tail->semesterID << endl;
        fout << Tail->active << endl;
        fout << Tail->current << endl;
    }

    //check the actual length of the list > cnt?
    if (Tail->Next != nullptr)
    EXITCODE(6)
}

void SemesterList::pushBack(SemesterNode *semesterNode) {
    SemesterNode *Tail;

    for (int i = 0; i<cnt; i++) {
        //check the actual length of the list < cnt?
        Tail = (i == 0 ? Head : Tail->Next);
        if (Tail == nullptr)
        EXITCODE(6)
    }

    //check the actual length of the list > cnt?
    if (Tail->Next != nullptr)
    EXITCODE(6)
    else {
        Tail->Next = semesterNode;
        cnt++;
    }
}

SemesterNode *SemesterList::find(string semesterID, bool mode) {
    SemesterNode *Tail;

    for (int i = 0; i<cnt; i++) {
        //check the actual length of the list < cnt?
        Tail = (i == 0 ? Head : Tail->Next);
        if (Tail == nullptr)
        EXITCODE_V(6, nullptr)

        if (Tail->active || mode == ALL) {
            if (Tail->semesterID == semesterID)
                return Tail;
        }
    }

    if (Tail->Next != nullptr)
    EXITCODE_V(6, nullptr)
    else
        return nullptr;
}

void SemesterList::print() {
    SemesterNode *Tail;

    for (int i = 0; i<cnt; i++) {
        //check the actual length of the list < cnt?
        Tail = (i == 0 ? Head : Tail->Next);
        if (Tail == nullptr)
        EXITCODE(6)

        Tail->print();
    }
}
