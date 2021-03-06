//
// Created by Duc An Chu on 5/31/20.
//

#include "StudentList.h"

StudentNode::StudentNode() {
    Next = nullptr;
}

StudentNode::StudentNode(string studentID_, string password_, string studentName_, Date DOB_,
                         string classID_, bool active_, StudentNode *Next_) {
    studentID = studentID_;
    password = password_;
    studentName = studentName_;
    DOB = DOB_;
    classID = classID_;
    active = active_;
    Next = Next_;
}

void StudentNode::print() {
    cout << "Student ID: " << studentID << endl;
    cout << "Password: " << password << endl;
    cout << "Student Name: " << studentName << endl;
    cout << "Date of Birth: " << DOB.y << " " << DOB.m << " " << DOB.d << endl;
    cout << "Class: " << classID << endl;
    cout << "Active: " << active << endl;
}

StudentList::StudentList() {
    Head = nullptr;
    cnt = 0;
}

StudentList::~StudentList() {
    destroy();
}

void StudentList::destroy() {
    StudentNode *tmp;
    while (Head != nullptr) {
        tmp = Head;
        Head = Head->Next;
        delete tmp;
    }

    cnt = 0;
}

bool StudentList::load() {
    ifstream fin;
    fin.open(getLocation() + "data/student.txt");

    //check if the file is missing?
    if (!fin.is_open())
        EXITCODE_V(4, false);

    fin >> cnt;
    string tmp;
    getline(fin, tmp);
    StudentNode *Tail = nullptr;

    for (int i = 0; i<cnt; i++) {
        //create a new node
        if (Head == nullptr)
            Head = Tail = new StudentNode;
        else
            Tail = Tail->Next = new StudentNode;

        CHECKDAMAGED
        getline(fin, Tail->studentID);

        CHECKDAMAGED
        getline(fin, Tail->password);

        CHECKDAMAGED
        getline(fin, Tail->studentName);

        CHECKDAMAGED
        fin >> Tail->DOB.y;
        CHECKDAMAGED
        fin >> Tail->DOB.m;
        CHECKDAMAGED
        fin >> Tail->DOB.d;
        if (Tail->DOB.wrongFormat())
            EXITCODE_V(5, false)
        getline(fin, tmp);

        CHECKDAMAGED
        getline(fin, Tail->classID);

        CHECKDAMAGED
        fin >> Tail->active;
        getline(fin, tmp);
    }

    fin.close();
    return true;
}

bool StudentList::save() {
    ofstream fout;
    fout.open(getLocation() + "data/student.txt");

    //check if the file is missing?
    if (!fout.is_open())
        EXITCODE_V(4, false);

    fout << cnt << endl;
    StudentNode *Tail = nullptr;

    for (int i = 0; i<cnt; i++) {
        //check the actual length of the list < cnt?
        Tail = (i == 0 ? Head : Tail->Next);
        if (Tail == nullptr)
            EXITCODE_V(6, false)

        fout << Tail->studentID << endl;
        fout << Tail->password << endl;
        fout << Tail->studentName << endl;
        fout << Tail->DOB.y << " " << Tail->DOB.m << " " << Tail->DOB.d << endl;
        fout << Tail->classID << endl;
        fout << Tail->active << endl;
    }

    //check the actual length of the list > cnt?
    if (cnt > 0 && Tail->Next != nullptr)
        EXITCODE_V(6, false)

    return true;
}

bool StudentList::pushBack(StudentNode *studentNode) {
    if (Head == nullptr && cnt == 0) {
        Head = studentNode;
        cnt++;
        return true;
    }

    StudentNode *Tail = nullptr;

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
        Tail->Next = studentNode;
        cnt++;
    }

    return true;
}

StudentNode* StudentList::find(string studentID, bool mode) {
    StudentNode *Tail = nullptr;

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

void StudentList::print() {
    StudentNode *Tail = nullptr;

    for (int i = 0; i<cnt; i++) {
        //check the actual length of the list < cnt?
        Tail = (i == 0 ? Head : Tail->Next);
        if (Tail == nullptr)
        EXITCODE(6)

        Tail->print();
    }
}
