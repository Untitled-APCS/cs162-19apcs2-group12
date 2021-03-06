//
// Created by Duc An Chu on 5/31/20.
//

#include "SemesterList.h"

string SemesterList::currentSemester = "";

SemesterNode::SemesterNode() {
    Next = nullptr;
}

SemesterNode::SemesterNode(string semesterID_, bool active_, int current_, SemesterNode *Next_) {
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
    destroy();
}

void SemesterList::destroy() {
    SemesterNode *tmp;
    while (Head != nullptr) {
        tmp = Head;
        Head = Head->Next;
        delete tmp;
    }

    cnt = 0;
}

bool SemesterList::load() {
    ifstream fin;
    fin.open(getLocation() + "data/semester.txt");

    //check if the file is missing?
    if (!fin.is_open())
    EXITCODE_V(4, false);

    fin >> cnt;
    string tmp;
    getline(fin, tmp);
    SemesterList::currentSemester = "";

    SemesterNode *Tail = nullptr;

    for (int i = 0; i<cnt; i++) {
        //create a new node
        if (Head == nullptr)
            Head = Tail = new SemesterNode;
        else
            Tail = Tail->Next = new SemesterNode;

        CHECKDAMAGED
        getline(fin, Tail->semesterID); //cout << Tail->semesterID << endl;

        CHECKDAMAGED
        fin >> Tail->active;
        getline(fin, tmp); //cout << Tail->active << endl;

        CHECKDAMAGED
        fin >> Tail->current;
        getline(fin, tmp); //cout << Tail->current << endl;

        if (Tail->current == CURRENT)
            currentSemester = Tail->semesterID;
    }

    fin.close();
    return true;
}

bool SemesterList::save() {
    ofstream fout;
    fout.open(getLocation() + "data/semester.txt");

    //check if the file is missing?
    if (!fout.is_open())
    EXITCODE_V(4, false);

    fout << cnt << endl;
    SemesterList::currentSemester = "";
    SemesterNode *Tail = nullptr;

    for (int i = 0; i<cnt; i++) {
        //check the actual length of the list < cnt?
        Tail = (i == 0 ? Head : Tail->Next);
        if (Tail == nullptr)
        EXITCODE_V(6, false)

        fout << Tail->semesterID << endl;
        fout << Tail->active << endl;
        fout << Tail->current << endl;

        if (Tail->current == CURRENT)
            currentSemester = Tail->semesterID;
    }

    //check the actual length of the list > cnt?
    if (cnt > 0 && Tail->Next != nullptr)
    EXITCODE_V(6, false)

    return true;
}

bool SemesterList::pushBack(SemesterNode *semesterNode) {
    if (Head == nullptr && cnt == 0) {
        Head = semesterNode;
        cnt++;
        return true;
    }

    SemesterNode *Tail = nullptr;

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
        Tail->Next = semesterNode;
        cnt++;
    }

    return true;
}

SemesterNode *SemesterList::find(string semesterID, bool mode) {
    SemesterNode *Tail = nullptr;

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

    if (cnt > 0 && Tail->Next != nullptr)
    EXITCODE_V(6, nullptr)
    else
        return nullptr;
}

void SemesterList::print() {
    SemesterNode *Tail = nullptr;

    for (int i = 0; i<cnt; i++) {
        //check the actual length of the list < cnt?
        Tail = (i == 0 ? Head : Tail->Next);
        if (Tail == nullptr)
        EXITCODE(6)

        Tail->print();
    }
}
