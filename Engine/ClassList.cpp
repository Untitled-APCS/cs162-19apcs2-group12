//
// Created by Duc An Chu on 5/31/20.
//

#include "ClassList.h"

ClassNode::ClassNode() {
    Next = nullptr;
}

ClassNode::ClassNode(string classID_, bool active_, ClassNode *Next_) {
    classID = classID_;
    active = active_;
    Next = Next_;
}

void ClassNode::print() {
    cout << "Class ID: " << classID << endl;
    cout << "Active: " << active << endl;
}

ClassList::ClassList() {
    Head = nullptr;
    cnt = 0;
}

ClassList::~ClassList() {
    ClassNode *tmp;
    while (Head != nullptr) {
        tmp = Head;
        Head = Head->Next;
        delete tmp;
    }
}

void ClassList::load() {
    ifstream fin;
    fin.open(getLocation() + "data/class.txt");

    //check if the file is missing?
    if (!fin.is_open())
    EXITCODE(4);

    fin >> cnt;
    string tmp;
    getline(fin, tmp);
    ClassNode *Tail = nullptr;

    for (int i = 0; i<cnt; i++) {
        //create a new node
        if (Head == nullptr)
            Head = Tail = new ClassNode;
        else
            Tail = Tail->Next = new ClassNode;

        CHECKDAMAGED
        getline(fin, Tail->classID);

        CHECKDAMAGED
        fin >> Tail->active;
        getline(fin, tmp);
    }

    fin.close();
}

void ClassList::save() {
    ofstream fout;
    fout.open(getLocation() + "data/class.txt");

    //check if the file is missing?
    if (!fout.is_open())
    EXITCODE(4);

    fout << cnt << endl;
    ClassNode *Tail = nullptr;

    for (int i = 0; i<cnt; i++) {
        //check the actual length of the list < cnt?
        Tail = (i == 0 ? Head : Tail->Next);
        if (Tail == nullptr)
        EXITCODE(6)

        fout << Tail->classID << endl;
        fout << Tail->active << endl;
    }

    //check the actual length of the list > cnt?
    if (Tail->Next != nullptr)
    EXITCODE(6)
}

void ClassList::pushBack(ClassNode *classNode) {
    ClassNode *Tail = nullptr;

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
        Tail->Next = classNode;
        cnt++;
    }
}

ClassNode *ClassList::find(string classID, bool mode) {
    ClassNode *Tail = nullptr;

    for (int i = 0; i<cnt; i++) {
        //check the actual length of the list < cnt?
        Tail = (i == 0 ? Head : Tail->Next);
        if (Tail == nullptr)
        EXITCODE_V(6, nullptr)

        if (Tail->active || mode == ALL) {
            if (Tail->classID == classID)
                return Tail;
        }
    }

    if (Tail->Next != nullptr)
    EXITCODE_V(6, nullptr)
    else
        return nullptr;
}

void ClassList::print() {
    ClassNode *Tail = nullptr;

    for (int i = 0; i<cnt; i++) {
        //check the actual length of the list < cnt?
        Tail = (i == 0 ? Head : Tail->Next);
        if (Tail == nullptr)
        EXITCODE(6)

        Tail->print();
    }
}