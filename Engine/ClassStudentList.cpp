//
// Created by Duc An Chu on 5/31/20.
//

#include "ClassStudentList.h"

ClassStudentNode::ClassStudentNode() {
    Next = nullptr;
}

ClassStudentNode::ClassStudentNode(string studentID_, bool active_, ClassStudentNode *Next_) {
    studentID = studentID_;
    active = active_;
    Next = Next_;
}

void ClassStudentNode::print() {
    cout << "Student ID: " << studentID << endl;
    cout << "Active: " << active << endl;
}

ClassStudentList::ClassStudentList() {
    Head = nullptr;
    cnt = 0;
}

ClassStudentList::~ClassStudentList() {
    destroy();
}

void ClassStudentList::destroy() {
    ClassStudentNode *tmp;
    while (Head != nullptr) {
        tmp = Head;
        Head = Head->Next;
        delete tmp;
    }

    cnt = 0;
}

bool ClassStudentList::load(string classID) {
    ifstream fin;
    fin.open(getLocation() + "data/" + classID + "-student.txt");

    //check if the file is missing?
    if (!fin.is_open())
    EXITCODE_V(4, false);

    fin >> cnt;
    string tmp;
    getline(fin, tmp);
    ClassStudentNode *Tail = nullptr;

    for (int i = 0; i<cnt; i++) {
        //create a new node
        if (Head == nullptr)
            Head = Tail = new ClassStudentNode;
        else
            Tail = Tail->Next = new ClassStudentNode;

        CHECKDAMAGED
        getline(fin, Tail->studentID);

        CHECKDAMAGED
        fin >> Tail->active;
        getline(fin, tmp);
    }

    fin.close();
    return true;
}

bool ClassStudentList::save(string classID) {
    ofstream fout;
    fout.open(getLocation() + "data/" + classID + "-student.txt");

    //check if the file is missing?
    if (!fout.is_open())
    EXITCODE_V(4, false);

    fout << cnt << endl;
    ClassStudentNode *Tail = nullptr;

    for (int i = 0; i<cnt; i++) {
        //check the actual length of the list < cnt?
        Tail = (i == 0 ? Head : Tail->Next);
        if (Tail == nullptr)
        EXITCODE_V(6, false)

        fout << Tail->studentID << endl;
        fout << Tail->active << endl;
    }

    //check the actual length of the list > cnt?
    if (Tail->Next != nullptr)
    EXITCODE_V(6, false)

    return true;
}

bool ClassStudentList::pushBack(ClassStudentNode *classStudentNode) {
    if (Head == nullptr && cnt == 0) {
        Head = classStudentNode;
        cnt++;
        return true;
    }

    ClassStudentNode *Tail = nullptr;

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
        Tail->Next = classStudentNode;
        cnt++;
    }

    return true;
}

ClassStudentNode *ClassStudentList::find(string studentID, bool mode) {
    ClassStudentNode *Tail = nullptr;

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

    if (Tail->Next != nullptr)
    EXITCODE_V(6, nullptr)
    else
        return nullptr;
}

void ClassStudentList::print() {
    ClassStudentNode *Tail = nullptr;

    for (int i = 0; i<cnt; i++) {
        //check the actual length of the list < cnt?
        Tail = (i == 0 ? Head : Tail->Next);
        if (Tail == nullptr)
        EXITCODE(6)

        Tail->print();
    }
}
