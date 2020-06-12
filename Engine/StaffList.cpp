//
// Created by Duc An Chu on 5/31/20.
//

#include "StaffList.h"

StaffNode::StaffNode() {
    Next = nullptr;
}

StaffNode::StaffNode(string staffID_, string password_, string staffName_, bool gender_, StaffNode *Next_) {
    staffID = staffID_;
    password = password_;
    staffName = staffName_;
    gender = gender_;
    Next = Next_;
}

void StaffNode::print() {
    cout << "Staff ID: " << staffID << endl;
    cout << "Password: " << password << endl;
    cout << "Staff Name: " << staffName << endl;
    cout << "Gender: " << gender << endl;
}

StaffList::StaffList() {
    Head = nullptr;
    cnt = 0;
}

StaffList::~StaffList() {
    destroy();
}

void StaffList::destroy() {
    StaffNode *tmp;
    while (Head != nullptr) {
        tmp = Head;
        Head = Head->Next;
        delete tmp;
    }

    cnt = 0;
}

bool StaffList::load() {
    ifstream fin;
    fin.open(getLocation() + "data/staff.txt");

    //check if the file is missing?
    if (!fin.is_open())
        EXITCODE_V(4, false)

    fin >> cnt;
    string tmp;
    getline(fin, tmp);
    StaffNode *Tail = nullptr;

    for (int i = 0; i<cnt; i++) {
        //create a new node
        if (Head == nullptr)
            Head = Tail = new StaffNode;
        else
            Tail = Tail->Next = new StaffNode;

        CHECKDAMAGED
        getline(fin, Tail->staffID);

        CHECKDAMAGED
        getline(fin, Tail->password);

        CHECKDAMAGED
        getline(fin, Tail->staffName);

        CHECKDAMAGED
        fin >> Tail->gender;
        getline(fin, tmp);
    }

    fin.close();
    return true;
}

bool StaffList::save() {
    ofstream fout;
    fout.open(getLocation() + "data/staff.txt");

    //check if the file is missing?
    if (!fout.is_open())
    EXITCODE_V(4, false);

    fout << cnt << endl;
    StaffNode *Tail = nullptr;

    for (int i = 0; i<cnt; i++) {
        //check the actual length of the list < cnt?
        Tail = (i == 0 ? Head : Tail->Next);
        if (Tail == nullptr)
        EXITCODE_V(6, false)

        fout << Tail->staffID << endl;
        fout << Tail->password << endl;
        fout << Tail->staffName << endl;
        fout << Tail->gender << endl;
    }

    //check the actual length of the list > cnt?
    if (cnt > 0 && Tail->Next != nullptr)
    EXITCODE_V(6, false)

    return true;
}

StaffNode *StaffList::find(string staffID) {
    StaffNode* Tail = nullptr;

    for (int i = 0; i<cnt; i++) {
        //check the actual length of the list < cnt?
        Tail = (i == 0 ? Head : Tail->Next);
        if (Tail == nullptr)
        EXITCODE_V(6, nullptr)

        if (Tail->staffID == staffID)
            return Tail;
    }

    if (cnt > 0 && Tail->Next != nullptr)
    EXITCODE_V(6, nullptr)
    else
        return nullptr;
}

void StaffList::print() {
    StaffNode *Tail = nullptr;

    for (int i = 0; i<cnt; i++) {
        //check the actual length of the list < cnt?
        Tail = (i == 0 ? Head : Tail->Next);
        if (Tail == nullptr)
        EXITCODE(6)

        Tail->print();
    }
}
