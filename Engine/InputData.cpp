//
// Created by Duc An Chu on 5/31/20.
//

#include "InputData.h"

namespace fs = std::filesystem;

bool inputStudent(string *s, int cnt, int x) {
    StudentList studentList;
    studentList.load();

    if (studentList.cnt == 0) {
        cout << "\n\nThere is currently no students at this time. Please add new students manually or by importing from "
             << "file and get back later. [enter]\n";

        fflush(stdin);
        char keyPress = cin.get();
        fflush(stdin);

        s[x] = "~";
        return true;
    }

    StudentNode *studentNode;

    string *Rec = new string [11];
    string tmp;

    if (s[x].length() == 0) {
        cout << "\n\nPlease enter the student information (name or id).\n";
        cout << "[  enter  ] Search.\n";
        cout << "[` + enter] Back to the previous field.\n";
        cout << "[~ + enter] Back to the menu.\n\n";
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
        cout << "[~ + enter] Back to menu.\n\n";
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
        cout << "We have found a student that matches with your hint:\n";

        studentNode = studentList.find(Rec[0], ACTIVE);
        if (studentNode == nullptr)
        EXITCODE_V(6, false)

        cout << "[  enter  ] " << Rec[0] << " - " << studentNode->studentName << endl;
        if (Rec[1].length() > 0)
            cout << "\nNot your choice? Choose one from the list below.\n";
    } else
        cout << "We have found some students that correspond to your hint:\n";

    for (int i = 1; i<=10; i++)
    if (Rec[i].length() > 0) {
        studentNode = studentList.find(Rec[i], ACTIVE);
        if (studentNode == nullptr)
        EXITCODE_V(6, false)

        cout << "[" << to_string(i%10) << " + enter] " << Rec[i] << " - " << studentNode->studentName << endl;
    }

    cout << endl;

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

    if (classList.cnt == 0) {
        cout << "\n\nThere is currently no classes at this time. Please add new classes manually or by importing from "
             << "file and get back later. [enter]\n";

        fflush(stdin);
        char keyPress = cin.get();
        fflush(stdin);

        s[x] = "~";
        return true;
    }

    ClassNode *classNode;

    string *Rec = new string [11];
    string tmp;

    if (s[x].length() == 0) {
        cout << "\n\nPlease enter the class information.\n";
        cout << "[  enter  ] Search.\n";
        cout << "[` + enter] Back to the previous field.\n";
        cout << "[~ + enter] Back to the menu.\n\n";
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
        cout << "[~ + enter] Back to menu.\n\n";
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
    if (Rec[0].length() > 0) {
        cout << "We have found a class that matches with your hint:\n";
        cout << "[  enter  ] " << Rec[0] << endl;

        if (Rec[1].length() > 0)
            cout << "\nNot your choice? Choose one from the list below.\n";
    } else
        cout << "We have found some classes that correspond to your hint:\n";


    for (int i = 1; i<=10; i++)
        if (Rec[i].length() > 0)
            cout << "[" << to_string(i%10) << " + enter] " << Rec[i] << endl;

    cout << endl;

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

    if (semesterList.cnt == 0) {
        cout << "\n\nThere is currently no semesters at this time. Please add new semesters manually and get back later. [enter]\n";

        fflush(stdin);
        char keyPress = cin.get();
        fflush(stdin);

        s[x] = "~";
        return true;
    }

    SemesterNode *semesterNode;

    string *Rec = new string [11];
    string tmp;

    if (s[x].length() == 0) {
        cout << "\n\nPlease enter the semester information.\n";
        cout << "[  enter  ] Search.\n";
        cout << "[` + enter] Back to the previous field.\n";
        cout << "[~ + enter] Back to the menu.\n\n";
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
        cout << "[~ + enter] Back to menu.\n\n";
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
    if (Rec[0].length() > 0) {
        cout << "We have found a semester that matches with your hint:\n";

        cout << "[  enter  ] " << Rec[0] << endl;

        if (Rec[1].length() > 0)
            cout << "\nNot your choice? Choose one from the list below.\n";
    } else
        cout << "We have found some students that correspond to your hint:\n";

    for (int i = 1; i<=10; i++)
        if (Rec[i].length() > 0)
            cout << "[" << to_string(i%10) << " + enter] " << Rec[i] << endl;

    cout << endl;

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

    if (courseList.cnt == 0) {
        cout << "\n\nThis class currently has no courses in this semester. Please add new courses manually or by importing from "
             << "file and get back later. [enter]\n";

        fflush(stdin);
        char keyPress = cin.get();
        fflush(stdin);

        s[x] = "~";
        return true;
    }

    CourseNode *courseNode;

    string *Rec = new string [11];
    string tmp;

    if (s[x].length() == 0) {
        cout << "\n\nPlease enter the course information (name or id).\n";
        cout << "[  enter  ] Search.\n";
        cout << "[` + enter] Back to the previous field.\n";
        cout << "[~ + enter] Back to the menu.\n\n";
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
        cout << "[~ + enter] Back to menu.\n\n";
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
        cout << "We have found a course that matches with your hint:\n";
        courseNode = courseList.find(Rec[0], ACTIVE);
        if (courseNode == nullptr)
        EXITCODE_V(6, false)

        cout << "[  enter  ] " << Rec[0] << " - " << courseNode->courseName << endl;

        if (Rec[1].length() > 0)
            cout << "\nNot your choice? Choose one from the list below.\n";
    } else
        cout << "We have found some courses that correspond to your hint:\n";

    for (int i = 1; i<=10; i++)
        if (Rec[i].length() > 0) {
            courseNode = courseList.find(Rec[i], ACTIVE);
            if (courseNode == nullptr)
            EXITCODE_V(6, false)

            cout << "[" << to_string(i%10) << " + enter] " << Rec[i] << " - " << courseNode->courseName << endl;
        }

    cout << endl;

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

    if (lecturerList.cnt == 0) {
        cout << "\n\nThere is currently no lecturers at this time. Please add new lecturers manually or by importing from "
             << "file and get back later. [enter]\n";

        fflush(stdin);
        char keyPress = cin.get();
        fflush(stdin);

        s[x] = "~";
        return true;
    }

    LecturerNode *lecturerNode;

    string *Rec = new string [11];
    string tmp;

    if (s[x].length() == 0) {
        cout << "\n\nPlease enter the lecturer information (name or id).\n";
        cout << "[  enter  ] Search.\n";
        cout << "[` + enter] Back to the previous field.\n";
        cout << "[~ + enter] Back to the menu.\n\n";
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
        cout << "[~ + enter] Back to menu.\n\n";
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
        cout << "We have found a lecturer that matches with your hint:\n";

        lecturerNode = lecturerList.find(Rec[0], ACTIVE);
        if (lecturerNode == nullptr)
        EXITCODE_V(6, false)

        cout << "[  enter  ] " << Rec[0] << " - " << lecturerNode->lecturerName << endl;

        if (Rec[1].length() > 0)
            cout << "\nNot your choice? Choose one from the list below.\n";
    } else
        cout << "We have found some lecturers that correspond to your hint\n";

    for (int i = 1; i<=10; i++)
        if (Rec[i].length() > 0) {
            lecturerNode = lecturerList.find(Rec[i], ACTIVE);
            if (lecturerNode == nullptr)
            EXITCODE_V(6, false)

            cout << "[" << to_string(i%10) << " + enter] " << Rec[i] << " - " << lecturerNode->lecturerName << endl;
        }

    cout << endl;

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

void refreshPathList(PathList &pathList, string &path, int &page, bool (*checkPath)(string), string *hint, int n) {
    pathList.destroy();
    pathList.getDirectoryList(path, checkPath, hint, n);
    page = 0;

    //cout << pathList.cnt << " " << ((pathList.cnt-1)/10+1) << endl;
}

void refreshFolderList(PathList &pathList, string &path, int &page) {
    pathList.destroy();
    pathList.getFolderList(path);
    page = 0;

    //cout << pathList.cnt << " " << ((pathList.cnt-1)/10+1) << endl;
}

bool inputPathClassListCSV(string *s, int cnt, int x) {
    int page;

    if (user::workspace == "/") {
        cout << "\n\nTips: Select your own workplace folder in Preferences to speed up the workflow. [enter]\n";

        fflush(stdin);
        char keyPress = cin.get();
        fflush(stdin);
    }

    if (!fs::exists(user::workspace)) {
        cout << "\n\nYour workspace '" << user::workspace << "'has been deleted or corrupted. Please reset it in Preferences. [enter]\n";

        fflush(stdin);
        char keyPress = cin.get();
        fflush(stdin);

        user::workspace = "/";
    }

    s[x] = user::workspace;

    PathList pathList;
    char keyPress; bool passed;
    refreshPathList(pathList, s[x], page, isClassListCSV, s, x);

    while (true) {
        cout << "\n\nFile Browser - Please select your class-list file.\n";
        cout << "Only folders and accepted files are shown below. If your file is hidden, please check its file format.\n\n";
        cout << "Current directory: " << s[x] << endl;

        for (int i = page * 10; i < min((page + 1) * 10, pathList.cnt); i++)
            cout << "[" << (i+1)%10 << " + enter] " << pathList.c[i].path << endl;

        cout << endl;

        if (page > 0)
            cout << "[A + enter] Previous.\n";

        if (page < ((pathList.cnt-1)/10+1) - 1)
            cout << "[D + enter] Next.\n";

        if (s[x] != "/")
            cout << "[W + enter] Back to parent folder.\n";

        cout << endl;

        cout << "[` + enter] Back to previous field.\n";
        cout << "[~ + enter] Back to menu.\n";

        passed = false;
        do {
            fflush(stdin);
            keyPress = cin.get();
            fflush(stdin);

            if (keyPress >= '0' && keyPress <= '9') {
                int k = (keyPress == '0' ? page * 10 + 9 : page * 10 + keyPress - '0' - 1);
                if (k < 0 || k >= pathList.cnt) continue;

                passed = true;
                s[x] += pathList.c[k].path;

                if (fs::is_regular_file(s[x]))
                    return true;
                else {
                    if (s[x].length() > 0 && s[x][s[x].length()-1] != '/')
                        s[x].push_back('/');
                    refreshPathList(pathList, s[x], page, isClassListCSV, s, x);
                }
            }

            if ((keyPress == 'A' || keyPress == 'a') && page > 0) {
                page--;
                passed = true;
            }

            if ((keyPress == 'D' || keyPress == 'd') && page < ((pathList.cnt-1)/10+1) - 1) {
                page++;
                passed = true;
            }

            if ((keyPress == 'W' || keyPress == 'w') && s[x] != "/") {
                if (s[x].length() > 0 && s[x][s[x].length()-1] == '/') s[x].pop_back();
                s[x] = fs::path(s[x]).parent_path().u8string();
                //cout << s[x] << endl;

                if (s[x].length() > 0 && s[x][s[x].length()-1] != '/') s[x].push_back('/');

                refreshPathList(pathList, s[x], page, isClassListCSV, s, x);
                passed = true;
            }

            if (keyPress == '`') {
                s[x] = "`";
                return true;
            }

            if (keyPress == '~') {
                s[x] = "~";
                return true;
            }
        } while (!passed);
    }
}

bool inputPathCourseListCSV(string *s, int cnt, int x) {
    int page;

    if (user::workspace == "/") {
        cout << "\n\nTips: Select your own workplace folder in Preferences to speed up the workflow. [enter]\n";

        fflush(stdin);
        char keyPress = cin.get();
        fflush(stdin);
    }

    if (!fs::exists(user::workspace)) {
        cout << "\n\nYour workspace '" << user::workspace << "'has been deleted or corrupted. Please reset it in Preferences. [enter]\n";

        fflush(stdin);
        char keyPress = cin.get();
        fflush(stdin);

        user::workspace = "/";
    }

    s[x] = user::workspace;

    PathList pathList;
    char keyPress; bool passed;
    refreshPathList(pathList, s[x], page, isCourseListCSV, s, x);

    while (true) {
        cout << "\n\nFile Browser - Please select your course-list file.\n";
        cout << "Only folders and accepted files are shown below. If your file is hidden, please check its file format.\n\n";
        cout << "Current directory: " << s[x] << endl;

        for (int i = page * 10; i < min((page + 1) * 10, pathList.cnt); i++)
            cout << "[" << (i+1)%10 << " + enter] " << pathList.c[i].path << endl;

        cout << endl;

        if (page > 0)
            cout << "[A + enter] Previous.\n";

        if (page < ((pathList.cnt-1)/10+1) - 1)
            cout << "[D + enter] Next.\n";

        if (s[x] != "/")
            cout << "[W + enter] Back to parent folder.\n";

        cout << endl;

        cout << "[` + enter] Back to previous field.\n";
        cout << "[~ + enter] Back to menu.\n";

        passed = false;
        do {
            fflush(stdin);
            keyPress = cin.get();
            fflush(stdin);

            if (keyPress >= '0' && keyPress <= '9') {
                int k = (keyPress == '0' ? page * 10 + 9 : page * 10 + keyPress - '0' - 1);
                if (k < 0 || k >= pathList.cnt) continue;

                passed = true;
                s[x] += pathList.c[k].path;

                if (fs::is_regular_file(s[x]))
                    return true;
                else {
                    if (s[x].length() > 0 && s[x][s[x].length()-1] != '/')
                        s[x].push_back('/');
                    refreshPathList(pathList, s[x], page, isCourseListCSV, s, x);
                }
            }

            if ((keyPress == 'A' || keyPress == 'a') && page > 0) {
                page--;
                passed = true;
            }

            if ((keyPress == 'D' || keyPress == 'd') && page < ((pathList.cnt-1)/10+1) - 1) {
                page++;
                passed = true;
            }

            if ((keyPress == 'W' || keyPress == 'w') && s[x] != "/") {
                if (s[x].length() > 0 && s[x][s[x].length()-1] == '/') s[x].pop_back();
                s[x] = fs::path(s[x]).parent_path().u8string();
                //cout << s[x] << endl;

                if (s[x].length() > 0 && s[x][s[x].length()-1] != '/') s[x].push_back('/');

                refreshPathList(pathList, s[x], page, isCourseListCSV, s, x);
                passed = true;
            }

            if (keyPress == '`') {
                s[x] = "`";
                return true;
            }

            if (keyPress == '~') {
                s[x] = "~";
                return true;
            }
        } while (!passed);
    }
}

bool inputPathLecturerListCSV(string *s, int cnt, int x) {
    int page;

    if (user::workspace == "/") {
        cout << "\n\nTips: Select your own workplace folder in Preferences to speed up the workflow. [enter]\n";

        fflush(stdin);
        char keyPress = cin.get();
        fflush(stdin);
    }

    if (!fs::exists(user::workspace)) {
        cout << "\n\nYour workspace '" << user::workspace << "'has been deleted or corrupted. Please reset it in Preferences. [enter]\n";

        fflush(stdin);
        char keyPress = cin.get();
        fflush(stdin);

        user::workspace = "/";
    }

    s[x] = user::workspace;

    PathList pathList;
    char keyPress; bool passed;
    refreshPathList(pathList, s[x], page, isLecturerListCSV, s, x);

    while (true) {
        cout << "\n\nFile Browser - Please select your lecturer-list file.\n";
        cout << "Only folders and accepted files are shown below. If your file is hidden, please check its file format.\n\n";
        cout << "Current directory: " << s[x] << endl;

        for (int i = page * 10; i < min((page + 1) * 10, pathList.cnt); i++)
            cout << "[" << (i+1)%10 << " + enter] " << pathList.c[i].path << endl;

        cout << endl;

        if (page > 0)
            cout << "[A + enter] Previous.\n";

        if (page < ((pathList.cnt-1)/10+1) - 1)
            cout << "[D + enter] Next.\n";

        if (s[x] != "/")
            cout << "[W + enter] Back to parent folder.\n";

        cout << endl;

        cout << "[` + enter] Back to previous field.\n";
        cout << "[~ + enter] Back to menu.\n";

        passed = false;
        do {
            fflush(stdin);
            keyPress = cin.get();
            fflush(stdin);

            if (keyPress >= '0' && keyPress <= '9') {
                int k = (keyPress == '0' ? page * 10 + 9 : page * 10 + keyPress - '0' - 1);
                if (k < 0 || k >= pathList.cnt) continue;

                passed = true;
                s[x] += pathList.c[k].path;

                if (fs::is_regular_file(s[x]))
                    return true;
                else {
                    if (s[x].length() > 0 && s[x][s[x].length()-1] != '/')
                        s[x].push_back('/');
                    refreshPathList(pathList, s[x], page, isLecturerListCSV, s, x);
                }
            }

            if ((keyPress == 'A' || keyPress == 'a') && page > 0) {
                page--;
                passed = true;
            }

            if ((keyPress == 'D' || keyPress == 'd') && page < ((pathList.cnt-1)/10+1) - 1) {
                page++;
                passed = true;
            }

            if ((keyPress == 'W' || keyPress == 'w') && s[x] != "/") {
                if (s[x].length() > 0 && s[x][s[x].length()-1] == '/') s[x].pop_back();
                s[x] = fs::path(s[x]).parent_path().u8string();
                //cout << s[x] << endl;

                if (s[x].length() > 0 && s[x][s[x].length()-1] != '/') s[x].push_back('/');

                refreshPathList(pathList, s[x], page, isLecturerListCSV, s, x);
                passed = true;
            }

            if (keyPress == '`') {
                s[x] = "`";
                return true;
            }

            if (keyPress == '~') {
                s[x] = "~";
                return true;
            }
        } while (!passed);
    }
}

bool inputPathStudentListCSV(string *s, int cnt, int x) {
    int page;

    if (user::workspace == "/") {
        cout << "\n\nTips: Select your own workplace folder in Preferences to speed up the workflow. [enter]\n";

        fflush(stdin);
        char keyPress = cin.get();
        fflush(stdin);
    }

    if (!fs::exists(user::workspace)) {
        cout << "\n\nYour workspace '" << user::workspace << "'has been deleted or corrupted. Please reset it in Preferences. [enter]\n";

        fflush(stdin);
        char keyPress = cin.get();
        fflush(stdin);

        user::workspace = "/";
    }

    s[x] = user::workspace;

    PathList pathList;
    char keyPress; bool passed;
    refreshPathList(pathList, s[x], page, isStudentListCSV, s, x);

    while (true) {
        cout << "\n\nFile Browser - Please select your student-list file.\n";
        cout << "Only folders and accepted files are shown below. If your file is hidden, please check its file format.\n\n";
        cout << "Current directory: " << s[x] << endl;

        for (int i = page * 10; i < min((page + 1) * 10, pathList.cnt); i++)
            cout << "[" << (i+1)%10 << " + enter] " << pathList.c[i].path << endl;

        cout << endl;

        if (page > 0)
            cout << "[A + enter] Previous.\n";

        if (page < ((pathList.cnt-1)/10+1) - 1)
            cout << "[D + enter] Next.\n";

        if (s[x] != "/")
            cout << "[W + enter] Back to parent folder.\n";

        cout << endl;

        cout << "[` + enter] Back to previous field.\n";
        cout << "[~ + enter] Back to menu.\n";

        passed = false;
        do {
            fflush(stdin);
            keyPress = cin.get();
            fflush(stdin);

            if (keyPress >= '0' && keyPress <= '9') {
                int k = (keyPress == '0' ? page * 10 + 9 : page * 10 + keyPress - '0' - 1);
                if (k < 0 || k >= pathList.cnt) continue;

                passed = true;
                s[x] += pathList.c[k].path;

                if (fs::is_regular_file(s[x]))
                    return true;
                else {
                    if (s[x].length() > 0 && s[x][s[x].length()-1] != '/')
                        s[x].push_back('/');
                    refreshPathList(pathList, s[x], page, isStudentListCSV, s, x);
                }
            }

            if ((keyPress == 'A' || keyPress == 'a') && page > 0) {
                page--;
                passed = true;
            }

            if ((keyPress == 'D' || keyPress == 'd') && page < ((pathList.cnt-1)/10+1) - 1) {
                page++;
                passed = true;
            }

            if ((keyPress == 'W' || keyPress == 'w') && s[x] != "/") {
                if (s[x].length() > 0 && s[x][s[x].length()-1] == '/') s[x].pop_back();
                s[x] = fs::path(s[x]).parent_path().u8string();
                //cout << s[x] << endl;

                if (s[x].length() > 0 && s[x][s[x].length()-1] != '/') s[x].push_back('/');

                refreshPathList(pathList, s[x], page, isStudentListCSV, s, x);
                passed = true;
            }

            if (keyPress == '`') {
                s[x] = "`";
                return true;
            }

            if (keyPress == '~') {
                s[x] = "~";
                return true;
            }
        } while (!passed);
    }
}

bool inputPathScoreBoardListCSV(string *s, int cnt, int x) {
    int page;

    if (user::workspace == "/") {
        cout << "\n\nTips: Select your own workplace folder in Preferences to speed up the workflow. [enter]\n";

        fflush(stdin);
        char keyPress = cin.get();
        fflush(stdin);
    }

    if (!fs::exists(user::workspace)) {
        cout << "\n\nYour workspace '" << user::workspace << "'has been deleted or corrupted. Please reset it in Preferences. [enter]\n";

        fflush(stdin);
        char keyPress = cin.get();
        fflush(stdin);

        user::workspace = "/";
    }

    s[x] = user::workspace;

    PathList pathList;
    char keyPress; bool passed;
    refreshPathList(pathList, s[x], page, isScoreBoardListCSV, s, x);

    while (true) {
        cout << "\n\nFile Browser - Please select your scoreboard file.\n";
        cout << "Only folders and accepted files are shown below. If your file is hidden, please check its file format.\n\n";
        cout << "Current directory: " << s[x] << endl;

        for (int i = page * 10; i < min((page + 1) * 10, pathList.cnt); i++)
            cout << "[" << (i+1)%10 << " + enter] " << pathList.c[i].path << endl;

        cout << endl;

        if (page > 0)
            cout << "[A + enter] Previous.\n";

        if (page < ((pathList.cnt-1)/10+1) - 1)
            cout << "[D + enter] Next.\n";

        if (s[x] != "/")
            cout << "[W + enter] Back to parent folder.\n";

        cout << endl;

        cout << "[` + enter] Back to previous field.\n";
        cout << "[~ + enter] Back to menu.\n";

        passed = false;
        do {
            fflush(stdin);
            keyPress = cin.get();
            fflush(stdin);

            if (keyPress >= '0' && keyPress <= '9') {
                int k = (keyPress == '0' ? page * 10 + 9 : page * 10 + keyPress - '0' - 1);
                if (k < 0 || k >= pathList.cnt) continue;

                passed = true;
                s[x] += pathList.c[k].path;

                if (fs::is_regular_file(s[x]))
                    return true;
                else {
                    if (s[x].length() > 0 && s[x][s[x].length()-1] != '/')
                        s[x].push_back('/');
                    refreshPathList(pathList, s[x], page, isScoreBoardListCSV, s, x);
                }
            }

            if ((keyPress == 'A' || keyPress == 'a') && page > 0) {
                page--;
                passed = true;
            }

            if ((keyPress == 'D' || keyPress == 'd') && page < ((pathList.cnt-1)/10+1) - 1) {
                page++;
                passed = true;
            }

            if ((keyPress == 'W' || keyPress == 'w') && s[x] != "/") {
                if (s[x].length() > 0 && s[x][s[x].length()-1] == '/') s[x].pop_back();
                s[x] = fs::path(s[x]).parent_path().u8string();
                //cout << s[x] << endl;

                if (s[x].length() > 0 && s[x][s[x].length()-1] != '/') s[x].push_back('/');

                refreshPathList(pathList, s[x], page, isScoreBoardListCSV, s, x);
                passed = true;
            }

            if (keyPress == '`') {
                s[x] = "`";
                return true;
            }

            if (keyPress == '~') {
                s[x] = "~";
                return true;
            }
        } while (!passed);
    }
}

bool inputPathExportCSV(string *s, int cnt, int x) {
    int page;

    if (!fs::exists(user::workspace)) {
        cout << "\n\nYour workspace '" << user::workspace << "'has been deleted or corrupted. Please reset it in Preferences. [enter]\n";

        fflush(stdin);
        char keyPress = cin.get();
        fflush(stdin);

        user::workspace = "/";
    }

    s[x] = user::workspace;

    PathList pathList;
    char keyPress; bool passed;
    refreshFolderList(pathList, s[x], page);

    while (true) {
        cout << "\n\nFile Browser - Please select your export folder.\n";
        cout << "Only folders and accepted files are shown below. If your file is hidden, please check its file format.\n\n";
        cout << "Current directory: " << s[x] << endl;

        for (int i = page * 10; i < min((page + 1) * 10, pathList.cnt); i++)
            cout << "[" << (i+1)%10 << " + enter] " << pathList.c[i].path << endl;

        cout << endl;

        if (page > 0)
            cout << "[A + enter] Previous.\n";

        if (page < ((pathList.cnt-1)/10+1) - 1)
            cout << "[D + enter] Next.\n";

        if (s[x] != "/")
            cout << "[W + enter] Back to parent folder.\n";

        cout << "[S + enter] Select current directory.\n";

        cout << endl;

        cout << "[` + enter] Back to previous field.\n";
        cout << "[~ + enter] Back to menu.\n";

        passed = false;
        do {
            fflush(stdin);
            keyPress = cin.get();
            fflush(stdin);

            if (keyPress >= '0' && keyPress <= '9') {
                int k = (keyPress == '0' ? page * 10 + 9 : page * 10 + keyPress - '0' - 1);
                if (k < 0 || k >= pathList.cnt) continue;

                passed = true;
                s[x] += pathList.c[k].path;

                if (s[x].length() > 0 && s[x][s[x].length()-1] != '/')
                    s[x].push_back('/');
                refreshFolderList(pathList, s[x], page);
            }

            if ((keyPress == 'A' || keyPress == 'a') && page > 0) {
                page--;
                passed = true;
            }

            if ((keyPress == 'D' || keyPress == 'd') && page < ((pathList.cnt-1)/10+1) - 1) {
                page++;
                passed = true;
            }

            if ((keyPress == 'W' || keyPress == 'w') && s[x] != "/") {
                if (s[x].length() > 0 && s[x][s[x].length()-1] == '/') s[x].pop_back();
                s[x] = fs::path(s[x]).parent_path().u8string();
                //cout << s[x] << endl;

                if (s[x].length() > 0 && s[x][s[x].length()-1] != '/') s[x].push_back('/');

                refreshFolderList(pathList, s[x], page);
                passed = true;
            }

            if (keyPress == 'S' || keyPress == 's') {
                string fileName;

                while (true) {
                    cout << "\n\nFile Browser - Please enter the file name.\n\n";
                    cout << "Your file path: " << s[x];

                    fflush(stdin);
                    getline(cin, fileName);
                    fflush(stdin);


                    if (fileName.length() >= 4) {
                        string tmp = fileName.substr(fileName.length() - 4, 4);
                        normalize(tmp);

                        if (tmp != ".csv") fileName += ".csv";
                    } else
                        fileName += ".csv";

                    ofstream fout;
                    fout.open(s[x] + fileName);
                    if (fout.is_open()) {
                        fout.close();
                        s[x] += fileName;
                        return true;
                    }
                }
            }

            if (keyPress == '`') {
                s[x] = "`";
                return true;
            }

            if (keyPress == '~') {
                s[x] = "~";
                return true;
            }
        } while (!passed);
    }
}
