//
// Created by Duc An Chu on 5/31/20.
//

#include "LecturerList.h"

LecturerNode::LecturerNode() {
    Next = nullptr;
}

LecturerNode::LecturerNode(string lecturerID_, string password_, string lecturerName_, string academicTitle_,
                           bool gender_, bool active_, LecturerNode *Next_) {
    lecturerID = lecturerID_;
    password = password_;
    lecturerName = lecturerName_;
    academicTitle = academicTitle_;
    gender = gender_;
    active = active_;
    Next = Next_;
}

void LecturerNode::print() {
    cout << "Lecturer ID: " << lecturerID << endl;
    cout << "Password: " << password << endl;
    cout << "Lecturer Name: " << lecturerName << endl;
    cout << "Academic Title: " << academicTitle << endl;
    cout << "Gender: " << gender << endl;
    cout << "Active: " << active << endl;
}

LecturerList::LecturerList() {
    Head = nullptr;
    cnt = 0;
}

LecturerList::~LecturerList() {
    LecturerNode *tmp;
    while (Head != nullptr) {
        tmp = Head;
        Head = Head->Next;
        delete tmp;
    }
}

bool LecturerList::load() {
    ifstream fin;
    fin.open(getLocation() + "data/lecturer.txt");

    //check if the file is missing?
    if (!fin.is_open())
    EXITCODE_V(4, false);

    fin >> cnt;
    string tmp;
    getline(fin, tmp);
    LecturerNode *Tail = nullptr;

    for (int i = 0; i<cnt; i++) {
        //create a new node
        if (Head == nullptr)
            Head = Tail = new LecturerNode;
        else
            Tail = Tail->Next = new LecturerNode;

        CHECKDAMAGED
        getline(fin, Tail->lecturerID);

        CHECKDAMAGED
        getline(fin, Tail->password);

        CHECKDAMAGED
        getline(fin, Tail->lecturerName);

        CHECKDAMAGED
        getline(fin, Tail->academicTitle);

        CHECKDAMAGED
        fin >> Tail->gender;
        getline(fin, tmp);

        CHECKDAMAGED
        fin >> Tail->active;
        getline(fin, tmp);
    }

    fin.close();
    return true;
}

bool LecturerList::save() {
    ofstream fout;
    fout.open(getLocation() + "data/lecturer.txt");

    //check if the file is missing?
    if (!fout.is_open())
    EXITCODE_V(4, false);

    fout << cnt << endl;
    LecturerNode *Tail = nullptr;

    for (int i = 0; i<cnt; i++) {
        //check the actual length of the list < cnt?
        Tail = (i == 0 ? Head : Tail->Next);
        if (Tail == nullptr)
        EXITCODE_V(6, false)

        fout << Tail->lecturerID << endl;
        fout << Tail->password << endl;
        fout << Tail->lecturerName << endl;
        fout << Tail->academicTitle << endl;
        fout << Tail->gender << endl;
        fout << Tail->active << endl;
    }

    //check the actual length of the list > cnt?
    if (Tail->Next != nullptr)
    EXITCODE_V(6, false)

    return true;
}

bool LecturerList::pushBack(LecturerNode *lecturerNode) {
    if (Head == nullptr && cnt == 0) {
        Head = lecturerNode;
        cnt++;
        return true;
    }

    LecturerNode *Tail = nullptr;

    for (int i = 0; i<cnt; i++) {
        //check the actual length of the list < cnt?
        Tail = (i == 0 ? Head : Tail->Next);
        if (Tail == nullptr)
        EXITCODE_V(6, false)
    }

    //check the actual length of the list > cnt?
    if (Tail->Next != nullptr)
    EXITCODE_V(6, false)
    else {
        Tail->Next = lecturerNode;
        cnt++;
    }

    return true;
}

LecturerNode *LecturerList::find(string lecturerID, bool mode) {
    LecturerNode *Tail = nullptr;

    for (int i = 0; i<cnt; i++) {
        //check the actual length of the list < cnt?
        Tail = (i == 0 ? Head : Tail->Next);
        if (Tail == nullptr)
        EXITCODE_V(6, nullptr)

        if (Tail->active || mode == ALL) {
            if (Tail->lecturerID == lecturerID)
                return Tail;
        }
    }

    if (Tail->Next != nullptr)
    EXITCODE_V(6, nullptr)
    else
        return nullptr;
}

void LecturerList::print() {
    LecturerNode *Tail = nullptr;

    for (int i = 0; i<cnt; i++) {
        //check the actual length of the list < cnt?
        Tail = (i == 0 ? Head : Tail->Next);
        if (Tail == nullptr)
        EXITCODE(6)

        Tail->print();
    }
}
