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
    destroy();
}

void ClassList::destroy() {
    ClassNode *tmp;
    while (Head != nullptr) {
        tmp = Head;
        Head = Head->Next;
        delete tmp;
    }

    cnt = 0;
}

bool ClassList::load() {
    ifstream fin;
    fin.open(getLocation() + "data/class.txt");

    //check if the file is missing?
    if (!fin.is_open())
    EXITCODE_V(4, false);

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
    return true;
}

bool ClassList::save() {
    ofstream fout;
    fout.open(getLocation() + "data/class.txt");

    //check if the file is missing?
    if (!fout.is_open())
    EXITCODE_V(4, false);

    fout << cnt << endl;
    ClassNode *Tail = nullptr;

    for (int i = 0; i<cnt; i++) {
        //check the actual length of the list < cnt?
        Tail = (i == 0 ? Head : Tail->Next);
        if (Tail == nullptr)
        EXITCODE_V(6, false)

        fout << Tail->classID << endl;
        fout << Tail->active << endl;
    }

    //check the actual length of the list > cnt?
    if (Tail->Next != nullptr)
    EXITCODE_V(6, false)

    return true;
}

bool ClassList::pushBack(ClassNode *classNode) {
    if (Head == nullptr && cnt == 0) {
        Head = classNode;
        cnt++;
        return true;
    }


    ClassNode *Tail = nullptr;

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
        Tail->Next = classNode;
        cnt++;
    }

    return true;
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
