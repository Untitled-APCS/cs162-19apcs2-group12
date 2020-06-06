//
// Created by Duc An Chu on 5/31/20.
//

#include "CourseList.h"

CourseNode::CourseNode() {
    Next = nullptr;
}

CourseNode::CourseNode(string courseID_, string courseName_, string lecturerID_, Date startingDate_, Time startingTime_,
                       Time endingTime_, string room_, bool active_, CourseNode *Next_) {
    courseID = courseID_;
    courseName = courseName_;
    lecturerID = lecturerID_;
    startingDate = startingDate_;
    startingTime = startingTime_;
    endingTime = endingTime_;
    room = room_;
    active = active_;
}

void CourseNode::print() {
    cout << "Course ID: " << courseID << endl;
    cout << "Course Name: " << courseName << endl;
    cout << "Lecturer ID: " << lecturerID << endl;
    cout << "Starting Date: " << startingDate.y << " " << startingDate.m << " " << startingDate.d << endl;
    cout << "Starting Time: " << startingTime.h << " " << startingTime.m << " " << startingTime.s << endl;
    cout << "Ending Time: " << endingTime.h << " " << endingTime.m << " " << endingTime.s << endl;
    cout << "Room: " << room << endl;
    cout << "Active: " << active << endl;
}

CourseList::CourseList() {
    Head = nullptr;
    cnt = 0;
}

CourseList::~CourseList() {
    destroy();
}

void CourseList::destroy() {
    CourseNode *tmp;
    while (Head != nullptr) {
        tmp = Head;
        Head = Head->Next;
        delete tmp;
    }

    cnt = 0;
}

bool CourseList::load(string semesterID, string classID) {
    ifstream fin;
    fin.open(getLocation() + "data/" + semesterID + "-" + classID + "-course.txt");

    //check if the file is missing?
    if (!fin.is_open())
    EXITCODE_V(4, false);

    fin >> cnt;
    string tmp;
    getline(fin, tmp);
    CourseNode *Tail = nullptr;

    for (int i = 0; i<cnt; i++) {
        //create a new node
        if (Head == nullptr)
            Head = Tail = new CourseNode;
        else
            Tail = Tail->Next = new CourseNode;

        CHECKDAMAGED
        getline(fin, Tail->courseID);

        CHECKDAMAGED
        getline(fin, Tail->courseName);

        CHECKDAMAGED
        getline(fin, Tail->lecturerID);

        CHECKDAMAGED
        fin >> Tail->startingDate.y;
        CHECKDAMAGED
        fin >> Tail->startingDate.m;
        CHECKDAMAGED
        fin >> Tail->startingDate.d;
        if (Tail->startingDate.wrongFormat())
        EXITCODE_V(5, false)
        getline(fin, tmp);

        CHECKDAMAGED
        fin >> Tail->startingTime.h;
        CHECKDAMAGED
        fin >> Tail->startingTime.m;
        CHECKDAMAGED
        fin >> Tail->startingTime.s;
        if (Tail->startingTime.wrongFormat())
        EXITCODE_V(5, false)
        getline(fin, tmp);

        CHECKDAMAGED
        fin >> Tail->endingTime.h;
        CHECKDAMAGED
        fin >> Tail->endingTime.m;
        CHECKDAMAGED
        fin >> Tail->endingTime.s;
        if (Tail->endingTime.wrongFormat())
        EXITCODE_V(5, false)
        getline(fin, tmp);

        CHECKDAMAGED
        getline(fin, Tail->room);

        CHECKDAMAGED
        fin >> Tail->active;
        getline(fin, tmp);
    }

    fin.close();
    return true;
}

bool CourseList::save(string semesterID, string classID) {
    ofstream fout;
    fout.open(getLocation() + "data/" + semesterID + "-" + classID + "-course.txt");

    //check if the file is missing?
    if (!fout.is_open())
    EXITCODE_V(4, false);

    fout << cnt << endl;
    CourseNode *Tail = nullptr;

    for (int i = 0; i<cnt; i++) {
        //check the actual length of the list < cnt?
        Tail = (i == 0 ? Head : Tail->Next);
        if (Tail == nullptr)
        EXITCODE_V(6, false)

        fout << Tail->courseID << endl;
        fout << Tail->courseName << endl;
        fout << Tail->lecturerID << endl;
        fout << Tail->startingDate.y << " " << Tail->startingDate.m << " " << Tail->startingDate.d << endl;
        fout << Tail->startingTime.h << " " << Tail->startingTime.m << " " << Tail->startingTime.s << endl;
        fout << Tail->endingTime.h << " " << Tail->endingTime.m << " " << Tail->endingTime.s << endl;
        fout << Tail->room << endl;
        fout << Tail->active << endl;
    }

    //check the actual length of the list > cnt?
    if (Tail->Next != nullptr)
    EXITCODE_V(6, false)

    return true;
}

bool CourseList::pushBack(CourseNode *courseNode) {
    if (Head == nullptr && cnt == 0) {
        Head = courseNode;
        cnt++;
        return true;
    }

    CourseNode *Tail = nullptr;

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
        Tail->Next = courseNode;
        cnt++;
    }

    return true;
}

CourseNode *CourseList::find(string courseID, bool mode) {
    CourseNode *Tail = nullptr;

    for (int i = 0; i<cnt; i++) {
        //check the actual length of the list < cnt?
        Tail = (i == 0 ? Head : Tail->Next);
        if (Tail == nullptr)
        EXITCODE_V(6, nullptr)

        if (Tail->active || mode == ALL) {
            if (Tail->courseID == courseID)
                return Tail;
        }
    }

    if (Tail->Next != nullptr)
    EXITCODE_V(6, nullptr)
    else
        return nullptr;
}

void CourseList::print() {
    CourseNode *Tail = nullptr;

    for (int i = 0; i<cnt; i++) {
        //check the actual length of the list < cnt?
        Tail = (i == 0 ? Head : Tail->Next);
        if (Tail == nullptr)
        EXITCODE(6)

        Tail->print();
    }
}
