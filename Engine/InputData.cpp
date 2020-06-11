//
// Created by Duc An Chu on 5/31/20.
//

#include "InputData.h"

bool inputStudent(string *s, int cnt, int x) {
    StudentList studentList;
    studentList.load();
    StudentNode *studentNode;

    string *Rec = new string [11];
    string tmp;

    if (s[x].length() == 0) {
        cout << "\n\nPlease enter the student information (name or id).\n";
        cout << "[  enter  ] Search.\n";
        cout << "[` + enter] Back to the previous field.\n";
        cout << "[~ + enter] Back to the menu.\n";
        cout << "Your hint: ";

        fflush(stdin);
        getline(cin, s[x]);
        fflush(stdin);

        if (s[x].find('`') != string::npos || s[x].find('~') != string::npos)
            return true;
    } else {
        cout << "\n\nPlease enter the student information (name or id).\n";
        cout << "[  enter  ] Search.\n";
        cout << "[` + enter] Back to previous field.\n";
        cout << "[~ + enter] Back to menu.\n";
        cout << "Default hint: '" << s[x] << "'. Press [enter] to keep this.\n";
        cout << "Your hint: ";

        fflush(stdin);
        getline(cin, tmp);
        fflush(stdin);

        if (tmp.length() > 0) s[x] = tmp;

        if (tmp.find('`') != string::npos || tmp.find('~') != string::npos)
            return true;
    }

    getRecStudent(Rec, s[x]);

    cout << "\n\n";
    if (Rec[0].length() > 0) {
        studentNode = studentList.find(Rec[0], ACTIVE);
        if (studentNode == nullptr)
        EXITCODE_V(6, false)

        cout << "[  enter  ] " << Rec[0] << " - " << studentNode->studentName << endl;
    }

    for (int i = 1; i<=10; i++)
    if (Rec[i].length() > 0) {
        studentNode = studentList.find(Rec[i], ACTIVE);
        if (studentNode == nullptr)
        EXITCODE_V(6, false)

        cout << "[" << to_string(i%10) << " + enter] " << Rec[i] << " - " << studentNode->studentName << endl;
    }

    cout << "[` + enter] Back to typing.\n";
    cout << "[~ + enter] Back to menu.\n";


    char keyPress;

    while (true) {
        fflush(stdin);
        keyPress = cin.get();
        fflush(stdin);

        if (keyPress == '`')
            return inputStudent(s, cnt, x);

        if (keyPress == '~') {
            s[x] = "~";
            return true;
        }

        for (int i = 1; i<=10; i++)
            if (keyPress == i%10 + '0' && Rec[i].length() > 0) {
                s[x] = Rec[i];
                return true;
            }

        if (Rec[0].length() > 0) {
            s[x] = Rec[0];
            return true;
        }
    }

}

bool inputClass(string *s, int cnt, int x) {
    ClassList classList;
    classList.load();
    ClassNode *classNode;

    string *Rec = new string [11];
    string tmp;

    if (s[x].length() == 0) {
        cout << "\n\nPlease enter the class information.\n";
        cout << "[  enter  ] Search.\n";
        cout << "[` + enter] Back to the previous field.\n";
        cout << "[~ + enter] Back to the menu.\n";
        cout << "Your hint: ";

        fflush(stdin);
        getline(cin, s[x]);
        fflush(stdin);

        if (s[x].find('`') != string::npos || s[x].find('~') != string::npos)
            return true;
    } else {
        cout << "\n\nPlease enter the class information.\n";
        cout << "[  enter  ] Search.\n";
        cout << "[` + enter] Back to previous field.\n";
        cout << "[~ + enter] Back to menu.\n";
        cout << "Default hint: '" << s[x] << "'. Press [enter] to keep this.\n";
        cout << "Your hint: ";

        fflush(stdin);
        getline(cin, tmp);
        fflush(stdin);

        if (tmp.length() > 0) s[x] = tmp;

        if (tmp.find('`') != string::npos || tmp.find('~') != string::npos)
            return true;
    }

    getRecClass(Rec, s[x]);

    cout << "\n\n";
    if (Rec[0].length() > 0)
        cout << "[  enter  ] " << Rec[0] << endl;


    for (int i = 1; i<=10; i++)
        if (Rec[i].length() > 0)
            cout << "[" << to_string(i%10) << " + enter] " << Rec[i] << endl;

    cout << "[` + enter] Back to typing.\n";
    cout << "[~ + enter] Back to menu.\n";


    char keyPress;

    while (true) {
        fflush(stdin);
        keyPress = cin.get();
        fflush(stdin);

        if (keyPress == '`')
            return inputClass(s, cnt, x);

        if (keyPress == '~') {
            s[x] = "~";
            return true;
        }

        for (int i = 1; i<=10; i++)
            if (keyPress == i%10 + '0' && Rec[i].length() > 0) {
                s[x] = Rec[i];
                return true;
            }

        if (Rec[0].length() > 0) {
            s[x] = Rec[0];
            return true;
        }
    }
}

bool inputSemester(string *s, int cnt, int x) {
    SemesterList semesterList;
    semesterList.load();
    SemesterNode *semesterNode;

    string *Rec = new string [11];
    string tmp;

    if (s[x].length() == 0) {
        cout << "\n\nPlease enter the semester information.\n";
        cout << "[  enter  ] Search.\n";
        cout << "[` + enter] Back to the previous field.\n";
        cout << "[~ + enter] Back to the menu.\n";
        cout << "Your hint: ";

        fflush(stdin);
        getline(cin, s[x]);
        fflush(stdin);

        if (s[x].find('`') != string::npos || s[x].find('~') != string::npos)
            return true;
    } else {
        cout << "\n\nPlease enter the semester information.\n";
        cout << "[  enter  ] Search.\n";
        cout << "[` + enter] Back to previous field.\n";
        cout << "[~ + enter] Back to menu.\n";
        cout << "Default hint: '" << s[x] << "'. Press [enter] to keep this.\n";
        cout << "Your hint: ";

        fflush(stdin);
        getline(cin, tmp);
        fflush(stdin);

        if (tmp.length() > 0) s[x] = tmp;

        if (tmp.find('`') != string::npos || tmp.find('~') != string::npos)
            return true;
    }

    getRecSemester(Rec, s[x]);

    cout << "\n\n";
    if (Rec[0].length() > 0)
        cout << "[  enter  ] " << Rec[0] << endl;

    for (int i = 1; i<=10; i++)
        if (Rec[i].length() > 0)
            cout << "[" << to_string(i%10) << " + enter] " << Rec[i] << endl;

    cout << "[` + enter] Back to typing.\n";
    cout << "[~ + enter] Back to menu.\n";


    char keyPress;

    while (true) {
        fflush(stdin);
        keyPress = cin.get();
        fflush(stdin);

        if (keyPress == '`')
            return inputSemester(s, cnt, x);

        if (keyPress == '~') {
            s[x] = "~";
            return true;
        }

        for (int i = 1; i<=10; i++)
            if (keyPress == i%10 + '0' && Rec[i].length() > 0) {
                s[x] = Rec[i];
                return true;
            }

        if (Rec[0].length() > 0) {
            s[x] = Rec[0];
            return true;
        }
    }
}

bool inputCourse(string *s, int cnt, int x) {
    CourseList courseList;
    courseList.load(s[x-2], s[x-1]);
    CourseNode *courseNode;

    string *Rec = new string [11];
    string tmp;

    if (s[x].length() == 0) {
        cout << "\n\nPlease enter the course information (name or id).\n";
        cout << "[  enter  ] Search.\n";
        cout << "[` + enter] Back to the previous field.\n";
        cout << "[~ + enter] Back to the menu.\n";
        cout << "Your hint: ";

        fflush(stdin);
        getline(cin, s[x]);
        fflush(stdin);

        if (s[x].find('`') != string::npos || s[x].find('~') != string::npos)
            return true;
    } else {
        cout << "\n\nPlease enter the course information (name or id).\n";
        cout << "[  enter  ] Search.\n";
        cout << "[` + enter] Back to previous field.\n";
        cout << "[~ + enter] Back to menu.\n";
        cout << "Default hint: '" << s[x] << "'. Press [enter] to keep this.\n";
        cout << "Your hint: ";

        fflush(stdin);
        getline(cin, tmp);
        fflush(stdin);

        if (tmp.length() > 0) s[x] = tmp;

        if (tmp.find('`') != string::npos || tmp.find('~') != string::npos)
            return true;
    }

    getRecCourse(s[x-2], s[x-1], Rec, s[x]);

    cout << "\n\n";
    if (Rec[0].length() > 0) {
        courseNode = courseList.find(Rec[0], ACTIVE);
        if (courseNode == nullptr)
        EXITCODE_V(6, false)

        cout << "[  enter  ] " << Rec[0] << " - " << courseNode->courseName << endl;
    }

    for (int i = 1; i<=10; i++)
        if (Rec[i].length() > 0) {
            courseNode = courseList.find(Rec[i], ACTIVE);
            if (courseNode == nullptr)
            EXITCODE_V(6, false)

            cout << "[" << to_string(i%10) << " + enter] " << Rec[i] << " - " << courseNode->courseName << endl;
        }

    cout << "[` + enter] Back to typing.\n";
    cout << "[~ + enter] Back to menu.\n";


    char keyPress;

    while (true) {
        fflush(stdin);
        keyPress = cin.get();
        fflush(stdin);

        if (keyPress == '`')
            return inputCourse(s, cnt, x);

        if (keyPress == '~') {
            s[x] = "~";
            return true;
        }

        for (int i = 1; i<=10; i++)
            if (keyPress == i%10 + '0' && Rec[i].length() > 0) {
                s[x] = Rec[i];
                return true;
            }

        if (Rec[0].length() > 0) {
            s[x] = Rec[0];
            return true;
        }
    }
}

bool inputLecturer(string *s, int cnt, int x) {
    LecturerList lecturerList;
    lecturerList.load();
    LecturerNode *lecturerNode;

    string *Rec = new string [11];
    string tmp;

    if (s[x].length() == 0) {
        cout << "\n\nPlease enter the lecturer information (name or id).\n";
        cout << "[  enter  ] Search.\n";
        cout << "[` + enter] Back to the previous field.\n";
        cout << "[~ + enter] Back to the menu.\n";
        cout << "Your hint: ";

        fflush(stdin);
        getline(cin, s[x]);
        fflush(stdin);

        if (s[x].find('`') != string::npos || s[x].find('~') != string::npos)
            return true;
    } else {
        cout << "\n\nPlease enter the lecturer information (name or id).\n";
        cout << "[  enter  ] Search.\n";
        cout << "[` + enter] Back to previous field.\n";
        cout << "[~ + enter] Back to menu.\n";
        cout << "Default hint: '" << s[x] << "'. Press [enter] to keep this.\n";
        cout << "Your hint: ";

        fflush(stdin);
        getline(cin, tmp);
        fflush(stdin);

        if (tmp.length() > 0) s[x] = tmp;

        if (tmp.find('`') != string::npos || tmp.find('~') != string::npos)
            return true;
    }

    getRecLecturer(Rec, s[x]);

    cout << "\n\n";
    if (Rec[0].length() > 0) {
        lecturerNode = lecturerList.find(Rec[0], ACTIVE);
        if (lecturerNode == nullptr)
        EXITCODE_V(6, false)

        cout << "[  enter  ] " << Rec[0] << " - " << lecturerNode->lecturerName << endl;
    }

    for (int i = 1; i<=10; i++)
        if (Rec[i].length() > 0) {
            lecturerNode = lecturerList.find(Rec[i], ACTIVE);
            if (lecturerNode == nullptr)
            EXITCODE_V(6, false)

            cout << "[" << to_string(i%10) << " + enter] " << Rec[i] << " - " << lecturerNode->lecturerName << endl;
        }

    cout << "[` + enter] Back to typing.\n";
    cout << "[~ + enter] Back to menu.\n";


    char keyPress;

    while (true) {
        fflush(stdin);
        keyPress = cin.get();
        fflush(stdin);

        if (keyPress == '`')
            return inputLecturer(s, cnt, x);

        if (keyPress == '~') {
            s[x] = "~";
            return true;
        }

        for (int i = 1; i<=10; i++)
            if (keyPress == i%10 + '0' && Rec[i].length() > 0) {
                s[x] = Rec[i];
                return true;
            }

        if (Rec[0].length() > 0) {
            s[x] = Rec[0];
            return true;
        }
    }
}

bool inputFilePath(string *s, int cnt, int x) {
    return false;
}

bool inputData(string *s, fPtr *p, int cnt, int x, bool (*check)(string *, int)) {
    if (x == cnt) {
        if (check(s, cnt))
            return true;
        else
            return inputData(s, p, cnt, 0, check);
    } else {
        if (!p[x](s, cnt, x))
            EXITCODE_V(6, false)

//        cout << s[0];
//        for (int i = 1; i<cnt; i++)
//            cout << " | " << s[i];
//        cout << endl << x << endl;

        if (s[x].find('`') != string::npos && x == 0 || s[x].find('~') != string::npos) {
            for (int i = 0; i<cnt; i++) s[i] = "";
            return true;
        } else if (s[x].find('`') != string::npos) {
            s[x] = "";
            return inputData(s, p, cnt, x-1, check);
        }

        return inputData(s, p, cnt, x+1, check);
    }
}
