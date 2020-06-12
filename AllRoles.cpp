//
// Created by Duc An Chu on 5/26/20.
//

#include "AllRoles.h"
//#include <openssl/sha.h>
//#include <openssl/evp.h>

namespace fs = std::filesystem;

void logIn() {
//    user::ID = "19125001";
//    cin >> user::type;
//    user::gender = MALE;
//    user::fullName = "Chu Duc An";

    string ID, fullName, password, hashedPassword;
    int type, gender;

    cout << "\n\nPlease type in your account ID.\n";
    cout << "[` + enter] Back to the entrance.\n";
    cout << "Your ID: ";

    getline(cin, ID);

    if (ID.find('`') != string::npos) {
        cout << "\n\nGetting you back to the entrance... [enter]";

        fflush(stdin);
        char keyPress = cin.get();
        fflush(stdin);
        logInMenu();
        return;
    }

    StaffList staffList;
    staffList.load();
    StaffNode *staffNode = staffList.find(ID);
    if (staffNode != nullptr) {
        fullName = staffNode->staffName;
        hashedPassword = staffNode->password;
        type = STAFF;
        gender = staffNode->gender;
    } else {
        LecturerList lecturerList;
        lecturerList.load();
        LecturerNode *lecturerNode = lecturerList.find(ID, ACTIVE);
        if (lecturerNode != nullptr) {
            fullName = lecturerNode->lecturerName;
            hashedPassword = lecturerNode->password;
            type = LECTURER;
            gender = lecturerNode->gender;
        } else {
            StudentList studentList;
            studentList.load();
            StudentNode *studentNode = studentList.find(ID, ACTIVE);
            if (studentNode != nullptr) {
                fullName = studentNode->studentName;
                hashedPassword = studentNode->password;
                type = STUDENT;
                gender = MALE;
            } else {
                cout << "\n\nSorry, we could not find you. Let's try one more time. [enter]";

                fflush(stdin);
                char keyPress = cin.get();
                fflush(stdin);
                logIn();
                return;
            }
        }
    }

    cout << "\n\nWe found you, " << getTitle(fullName, type, gender) << ". Type in your password and go ahead.\n";
    cout << "In this version, the password is not hidden on the screen. Please be aware of intentional glances of people around you.\n";
    cout << "[` + enter] This isn't you? Try again.\n\n";


    while (true) {
        cout << "Your password: ";

        fflush(stdin);
        getline(cin, password);
        fflush(stdin);

        if (password.find('`') != string::npos) {
            cout << "\n\nGetting you back to the entrance... [enter]";

            fflush(stdin);
            char keyPress = cin.get();
            fflush(stdin);
            logInMenu();
            return;
        }

        if (getHashedPassword(password) == hashedPassword) {
            user::ID = ID;
            user::fullName = fullName;
            user::password = hashedPassword;
            user::type = type;

            cout << "\n\nLogin successfully. [enter]\n";

            fflush(stdin);
            char keyPress = cin.get();
            fflush(stdin);
            mainMenu();
            return;
        } else
            cout << "Your password is incorrect. Please try again.\n";
    }
}

void logOut() {
    cout << "\n\n";
    user::ID = "";
    user::type = -1;
    user::fullName = "";
    user::gender = -1;
    user::workspace = "/";

    cout << "You have been logged out. Getting you back to the entrance... [enter]\n";

    char keyPress = cin.get();
    fflush(stdin);
    logInMenu();
}

void viewProfileInfo() {
    cout << "\n\nYour personal information:\n";

    if (user::type == STAFF) {
        cout << "ID: " << user::ID << endl;
        cout << "Full name: " << user::fullName << endl;
        cout << "Gender: " << (user::gender == MALE ? "Male" : "Female") << endl;
        cout << "[enter] Back to menu.\n";
    } else if (user::type == LECTURER) {
        LecturerList lecturerList;
        if (!lecturerList.load()) EXITCODE(3)

        LecturerNode *lecturerNode = lecturerList.find(user::ID, ACTIVE);
        if (lecturerNode == nullptr) EXITCODE(3)

        cout << "ID: " << user::ID << endl;
        cout << "Full name: " << user::fullName << endl;
        cout << "Academic Title: " << lecturerNode->academicTitle << endl;
        cout << "Gender: " << (user::gender == MALE ? "Male" : "Female") << endl;
        cout << "[enter] Back to menu.\n";
    } else if (user::type == STUDENT) {
        StudentList studentList;
        if (!studentList.load()) EXITCODE(3)

        StudentNode *studentNode = studentList.find(user::ID, ACTIVE);
        if (studentNode == nullptr) EXITCODE(3)

        cout << "ID: " << user::ID << endl;
        cout << "Full name: " << user::fullName << endl;
        cout << "Date of Birth: ";
        printf("%04d/%02d/%02d\n", studentNode->DOB.y, studentNode->DOB.m, studentNode->DOB.d);
        cout << "Class: " << studentNode->classID << endl;
        cout << "[enter] Back to Preferences.\n";
    } else
        EXITCODE(3)


    char keyPress = cin.get();
    fflush(stdin);
    preferencesMenu();
}

void changePassword() {
    string password, oldPassword, newPassword, newPasswordRetyped;
    bool passed;

    cout << "\n\nYou are under protection, " << getTitle(user::fullName, user::type, user::gender) << ". Please type in your old password.\n";
    cout << "In this version, the password is not hidden on the screen. Please be aware of intentional glances of people around you.\n";
    cout << "[` + enter] Back to Preferences.\n\n";

    passed = false;

    while (!passed) {
        cout << "Your old password: ";

        fflush(stdin);
        getline(cin, oldPassword);
        fflush(stdin);

        if (oldPassword.find('`') != string::npos) {
//            cout << "\n\nGetting you back to Preferences... [enter]";
//
//            fflush(stdin);
//            char keyPress = cin.get();
//            fflush(stdin);
            preferencesMenu();
            return;
        }

        if (getHashedPassword(oldPassword) == user::password)
            passed = true;
//            cout << "\n\nLogin successfully. [enter]\n";
//
//            fflush(stdin);
//            char keyPress = cin.get();
//            fflush(stdin);
//            mainMenu();
//            return;
        else
            cout << "Your password is incorrect. Please try again.\n";
    }

    cout << "\n\nGood job! Now create a new password.\n";
    cout << "In this version, the password is not hidden on the screen. Please be aware of intentional glances of people around you.\n";
    cout << "[` + enter] Back to Preferences.\n\n";

    passed = false;

    while (!passed) {
        cout << "Your new password: ";

        fflush(stdin);
        getline(cin, newPassword);
        fflush(stdin);

        if (newPassword.find('`') != string::npos) {
//            cout << "\n\nGetting you back to Preferences... [enter]";
//
//            fflush(stdin);
//            char keyPress = cin.get();
//            fflush(stdin);
            preferencesMenu();
            return;
        }

        if (isStrongPassword(newPassword)) {
            passed = true; cout << newPassword << endl;}
        else {
            cout << "Your password is not strong enough. Please create another one.\n";
            cout << "A strong password has at least 8 characters, 1 lowercase, 1 uppercase, 1 special character and must not"
                 << " consist of character '`'.\n";
        }
    }

    cout << "\n\nYou are almost done. Re-enter your new password to finish the process.\n";
    cout << "In this version, the password is not hidden on the screen. Please be aware of intentional glances of people around you.\n";
    cout << "[` + enter] Back to Preferences.\n\n";

    passed = false;

    while (!passed) {
        cout << "Retype your new password: ";

        fflush(stdin);
        getline(cin, newPasswordRetyped);
        fflush(stdin);

        if (newPasswordRetyped.find('`') != string::npos) {
//            cout << "\n\nGetting you back to Preferences... [enter]";
//
//            fflush(stdin);
//            char keyPress = cin.get();
//            fflush(stdin);
            preferencesMenu();
            return;
        }

        if (newPassword == newPasswordRetyped)
            passed = true;
        else
            cout << "They do not match. Please type again.\n";
    }

    if (user::type == STAFF) {
        StaffList staffList;
        if (!staffList.load()) EXITCODE(3)

        StaffNode *staffNode;
        staffNode = staffList.find(user::ID);
        if (staffNode == nullptr) EXITCODE(3)

        staffNode->password = getHashedPassword(newPassword);
        if (!staffList.save()) EXITCODE(3);
    } else if (user::type == LECTURER) {
        LecturerList lecturerList;
        if (!lecturerList.load()) EXITCODE(3)

        LecturerNode *lecturerNode;
        lecturerNode = lecturerList.find(user::ID, ACTIVE);
        if (lecturerNode == nullptr) EXITCODE(3)

        lecturerNode->password = getHashedPassword(newPassword);
        if (!lecturerList.save()) EXITCODE(3);
    } else if (user::type == STUDENT) {
        StudentList studentList;
        if (!studentList.load()) EXITCODE(3)

        StudentNode *studentNode;
        studentNode = studentList.find(user::ID, ACTIVE);
        if (studentNode == nullptr) EXITCODE(3)

        studentNode->password = getHashedPassword(newPassword);
        if (!studentList.save()) EXITCODE(3);
    } else
        EXITCODE(3)

    cout << "\n\nYour password has been changed. [enter]\n";

    char keyPress = cin.get();
    fflush(stdin);
    preferencesMenu();
}

void changeWorkspace() {
    int page;

    if (!fs::exists(user::workspace)) {
        cout << "\n\nYour old workspace has been deleted or corrupted. [enter]\n";

        fflush(stdin);
        char keyPress = cin.get();
        fflush(stdin);

        user::workspace = "/";
    }

    PathList pathList;
    char keyPress; bool passed;
    refreshFolderList(pathList, user::workspace, page);

    while (true) {
        cout << "\n\nFile Browser - Please select your workspace folder.\n";
        cout << "Only folders and accepted files are shown below. If your file is hidden, please check its file format.\n\n";
        cout << "Current directory: " << user::workspace << endl;

        for (int i = page * 10; i < min((page + 1) * 10, pathList.cnt); i++)
            cout << "[" << (i+1)%10 << " + enter] " << pathList.c[i].path << endl;

        cout << endl;

        if (page > 0)
            cout << "[A + enter] Previous.\n";

        if (page < ((pathList.cnt-1)/10+1) - 1)
            cout << "[D + enter] Next.\n";

        if (user::workspace != "/")
            cout << "[W + enter] Back to parent folder.\n";

        cout << "[S + enter] Select current directory.\n";

        cout << endl;

        cout << "[` + enter] Back to menu.\n";

        passed = false;
        do {
            fflush(stdin);
            keyPress = cin.get();
            fflush(stdin);

            if (keyPress >= '0' && keyPress <= '9') {
                int k = (keyPress == '0' ? page * 10 + 9 : page * 10 + keyPress - '0' - 1);
                if (k < 0 || k >= pathList.cnt) continue;

                passed = true;
                user::workspace += pathList.c[k].path;

                if (user::workspace.length() > 0 && user::workspace[user::workspace.length()-1] != '/')
                    user::workspace.push_back('/');
                refreshFolderList(pathList, user::workspace, page);
            }

            if ((keyPress == 'A' || keyPress == 'a') && page > 0) {
                page--;
                passed = true;
            }

            if ((keyPress == 'D' || keyPress == 'd') && page < ((pathList.cnt-1)/10+1) - 1) {
                page++;
                passed = true;
            }

            if ((keyPress == 'W' || keyPress == 'w') && user::workspace != "/") {
                if (user::workspace.length() > 0 && user::workspace[user::workspace.length()-1] == '/') user::workspace.pop_back();
                user::workspace = fs::path(user::workspace).parent_path().u8string();
                //cout << s[x] << endl;

                if (user::workspace.length() > 0 && user::workspace[user::workspace.length()-1] != '/') user::workspace.push_back('/');

                refreshFolderList(pathList, user::workspace, page);
                passed = true;
            }

            if (keyPress == 'S' || keyPress == 's') {
                cout << "Your workspace has been changed to '" << user::workspace << "' successfully. [enter]\n";

                fflush(stdin);
                keyPress = cin.get();
                fflush(stdin);
                preferencesMenu();
                return;
            }

            if (keyPress == '`') {
                user::workspace = "/";
                cout << "Your workspace is being erased. [enter]\n";

                fflush(stdin);
                keyPress = cin.get();
                fflush(stdin);
                preferencesMenu();
                return;
            }
        } while (!passed);
    }
}

void turnOffRecommendation() {
    cout << "\n\nThis feature could not be turned off at this time. You can donate for the Untiled Team and "
         << "hope/pray for the coming updates. [enter]\n";

    char keyPress = cin.get();
    fflush(stdin);
    preferencesMenu();
}

void turnOffCorrection() {
    cout << "\n\nThis feature could not be turned off at this time. You can donate for the Untiled Team and "
         << "hope/pray for the coming updates. [enter]\n";

    char keyPress = cin.get();
    fflush(stdin);
    preferencesMenu();
}

void testStaffClass() {
    cout << "\n\nStaff_class_function has been tested successfully. [enter]\n";

    char keyPress = cin.get();
    fflush(stdin);
    staffClassMenu();
}

void testStaffCourse() {
    cout << "\n\nStaff_course_function has been tested successfully. [enter]\n";

    char keyPress = cin.get();
    fflush(stdin);
    staffCourseMenu();
}

void testStaffSemester() {
    cout << "\n\nStaff_semester_function has been tested successfully. [enter]\n";

    char keyPress = cin.get();
    fflush(stdin);
    staffSemesterMenu();
}

void testStaffLecturer() {
    cout << "\n\nStaff_lecturer_function has been tested successfully. [enter]\n";

    char keyPress = cin.get();
    fflush(stdin);
    staffLecturerMenu();
}

void testStaffStudent() {
    cout << "\n\nStaff_student_function has been tested successfully. [enter]\n";

    char keyPress = cin.get();
    fflush(stdin);
    staffStudentMenu();
}

void testLecturer() {
    cout << "\n\nLecturer_function has been tested successfully. [enter]\n";

    char keyPress = cin.get();
    fflush(stdin);
    lecturerMenu();
}

void testStudent() {
    cout << "\n\nStudent_function has been tested successfully. [enter]\n";

    char keyPress = cin.get();
    fflush(stdin);
    studentMenu();
}
