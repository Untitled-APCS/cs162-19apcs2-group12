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
    ClassStudentNode *tmp;
    while (Head != nullptr) {
        tmp = Head;
        Head = Head->Next;
        delete tmp;
    }
}

void ClassStudentList::load(string classID) {
    ifstream fin;
    fin.open("data/" + classID + "-student.txt");

    //check if the file is missing?
    if (!fin.is_open())
    EXITCODE(4);

    fin >> cnt;
    string tmp;
    getline(fin, tmp);
    ClassStudentNode *Tail;

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
}

void ClassStudentList::save(string classID) {
    ofstream fout;
    fout.open("data/" + classID + "-student.txt");

    //check if the file is missing?
    if (!fout.is_open())
    EXITCODE(4);

    fout << cnt << endl;
    ClassStudentNode *Tail;

    for (int i = 0; i<cnt; i++) {
        //check the actual length of the list < cnt?
        Tail = (i == 0 ? Head : Tail->Next);
        if (Tail == nullptr)
        EXITCODE(6)

        fout << Tail->studentID << endl;
        fout << Tail->active << endl;
    }

    //check the actual length of the list > cnt?
    if (Tail->Next != nullptr)
    EXITCODE(6)
}

void ClassStudentList::pushBack(ClassStudentNode *classStudentNode) {
    ClassStudentNode *Tail;

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
        Tail->Next = classStudentNode;
        cnt++;
    }
}

ClassStudentNode *ClassStudentList::find(string studentID, bool mode) {
    ClassStudentNode *Tail;

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
    ClassStudentNode *Tail;

    for (int i = 0; i<cnt; i++) {
        //check the actual length of the list < cnt?
        Tail = (i == 0 ? Head : Tail->Next);
        if (Tail == nullptr)
        EXITCODE(6)

        Tail->print();
    }
}
