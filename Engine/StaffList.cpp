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
    StaffNode *tmp;
    while (Head != nullptr) {
        tmp = Head;
        Head = Head->Next;
        delete tmp;
    }
}

void StaffList::load() {
    ifstream fin;
    fin.open(getLocation() + "data/staff.txt");

    //check if the file is missing?
    if (!fin.is_open())
        EXITCODE(4)

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

    if (Tail->Next != nullptr)
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
