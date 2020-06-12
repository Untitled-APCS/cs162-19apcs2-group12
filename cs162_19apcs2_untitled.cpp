#include "AcademicStaffCourse.h"
//#include "AcademicStaffClass.h"
//#include "AcademicStaffScoreBoard.h"
//#include "Lecturer.h"
#include "Student.h"
#include "AllRoles.h"
#include "Engine.h"
#include <filesystem>

bool checkTest(string* s, int cnt) {
//    for (int i = 0; i<cnt; i++)
//        for (int j = i+1; j<cnt; j++)
//            if (s[i] == s[j]) {
//                cout << "\n\nThree studentIDs must be nonidentical. [enter]\n";
//
//                fflush(stdin);
//                char keyPress = cin.get();
//                fflush(stdin);
//                return false;
//            }

//    if (s[0] == s[1]) {
//        cout << "\n\nThe two studentIDs must be nonidentical. [enter]\n";
//
//        fflush(stdin);
//        char keyPress = cin.get();
//        fflush(stdin);
//        return false;
//    }
//
//    ClassStudentList classStudentList;
//    classStudentList.load(s[2]);
//
//    if (classStudentList.find(s[0], ACTIVE) == nullptr ||
//        classStudentList.find(s[1], ACTIVE) == nullptr) {
//        cout << "\n\nThe two studentIDs must exist in the class. [enter]\n";
//
//        fflush(stdin);
//        char keyPress = cin.get();
//        fflush(stdin);
//        return false;
//    }

//    SemesterList semesterList;
//    semesterList.load();
//
//    if (s[0] != SemesterList::currentSemester) {
//        cout << "\n\nThe semester must be set to be current. [enter]\n";
//
//        fflush(stdin);
//        char keyPress = cin.get();
//        fflush(stdin);
//        return false;
//    }

    return true;
}

int main(int argc, const char **argv) {
//    fileLocation = argv[0];
//    while (fileLocation.size() > 0 && fileLocation[fileLocation.size()-1] != '/')
//        fileLocation.pop_back();
    logo();
    logInMenu();
    //lecturer_1_();

    //cout << getCheckInCode("2020-2021hk1", "18CTT1", "cs251", 1);

    //44BD29
    //7EA241
    //4F89E7
    //AFC0BE
    //string s;
    //getline(cin, s);

    //cout << (int) (21 - 1) / (int) 10 + 1;

//    SemesterList semesterList;
//    semesterList.load();
//
//    int cnt = 3;
//    string *s = new string [cnt] {SemesterList::currentSemester, "", ""};
//    fPtr *p = new fPtr [cnt] {inputSemester, inputClass, inputCourse};
//    if (!inputData(s, p, cnt, 0, checkTest))
//        EXITCODE_V(6, 0)
//
//    for (int i = 0; i<cnt; i++)
//        cout << s[i] << endl;

    //cout << isStudentListCSV("/Users/ducanchu/Documents/Assignments/CS162/Standard CSV Input/class-list-18ctt1.csv");
    //return 0;

//    int cnt = 1;
//    string *s = new string [cnt];
//    fPtr *p = new fPtr [cnt] {inputPathExportCSV};
//    if (!inputData(s, p, cnt, 0, checkTest))
//    EXITCODE_V(6, 0)
//
//    for (int i = 0; i<cnt; i++)
//        cout << s[i] << endl;

//    string ID;
//    int choice = 0;
//    char keyPress;
//
//    cout << "\n\nThe student with ID '" << ID << "' has already added.\n";
//    cout << "[1 + enter] Skip.\n";
//    cout << "[2 + enter] Replace.\n";
//    cout << "[3 + enter] Skip all.\n";
//    cout << "[4 + enter] Replace all.\n";
//
//    while (choice == 0) {
//        fflush(stdin);
//        keyPress = cin.get();
//        fflush(stdin);
//
//        switch (keyPress) {
//            case '1':
//                choice = SKIP;
//                break;
//            case '2':
//                choice = REPLACE;
//                break;
//            case '3':
//                choice = SKIP_ALL;
//                break;
//            case '4':
//                choice = REPLACE_ALL;
//                break;
//            default:
//                choice = 0;
//        }
//    }



//    string *Rec = new string [11], hint = "dANG dINH";
//    getRecStudent(Rec, hint);
//
//    StudentList studentList;
//    StudentNode *studentNode;
//    if (!studentList.load())
//        EXITCODE_V(6, 0)
//
//    cout << "Hint: " << hint << endl;
//    for (int i = 0; i<=10; i++)
//    if (Rec[i] != "") {
//        cout << i << " - " << Rec[i] << " - ";
//
//        studentNode = studentList.find(Rec[i], ACTIVE);
//        if (studentNode == nullptr)
//            EXITCODE_V(6, 0)
//
//        cout << studentNode->studentName << endl;
//    }

//    PathList pathList;
//    string *hint = new string [1] {"19ctt"};
//    pathList.getDirectoryList("/Users/ducanchu/Documents/Assignments/CS162/Standard CSV Input/CSVGenerator/cmake-build-debug/Student/", isStudentListCSV, hint, 1);
//
//    for (int i = 0; i<pathList.cnt; i++)
//        cout << pathList.c[i].path << endl;

    //cout << getHashedPassword("ltathao");

//    StudentList studentList;
//    studentList.load();
//    studentList.print();
//
//    StudentNode *studentNode = studentList.find("httu", ACTIVE);
//    if (studentNode != nullptr)
//        studentNode->print();

//    studentNode = new StudentNode {"19125050", getHashedPassword("19125050"), "Ta Huynh Tuan Kiet",
//                              {2001, 02, 02}, "19CTT2", true, nullptr};
//
//    studentList.pushBack(studentNode);

//    studentList.save();

//    PathList pathList;
//    string *hint = new string [3];
//    hint[0] = "2019-2020";
//    hint[1] = "19ctt2";
//    hint[2] = "cm101";
//    pathList.getDirectoryList("/Users/ducanchu/Documents/Assignments/CS162/cs162-19apcs2-group12/", isLecturerListCSV, hint, 3);
//    for (int i = 0; i<pathList.cnt; i++)
//        cout << pathList.c[i].path << endl;



    //cout << isClassListCSV(getLocation() + "CSVTemplate/ClassListCSVTemplate.csv");

    return 0;
}
