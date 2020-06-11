//
// Created by Duc An Chu on 5/26/20.
//

#include "AllRoles.h"
//#include <openssl/sha.h>
//#include <openssl/evp.h>

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
    cout << "[` + enter] This isn't you? Try again.\n";


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
    user::workspace = "";

    cout << "You have been logged out. Getting you back to the entrance... [enter]\n";

    char keyPress = cin.get();
    fflush(stdin);
    logInMenu();
}

string getHashedPassword(string password) {
//    //hashing password using PBKDF2 with 10000 iterations of HMAC-SHA256
//
//    const int keyLen = 50;
//    string ans;
//
//    cppcrypto::hmac hmac(cppcrypto::sha256(), password);
//    unsigned char *key = new unsigned char [keyLen];
//    pbkdf2(hmac, (const unsigned char*)"Untitled_APCS_2020", 18, 20000, key, sizeof(unsigned char) * keyLen);
//
//    unsigedCharToHexString(key, keyLen, ans);
//    delete [] key;
//    return ans;

//    const unsigned int keyLen = 50;
//    unsigned char key[keyLen];
//    const char *pass = password.c_str();
//    PKCS5_PBKDF2_HMAC(pass, keyLen, (const unsigned char*)"Untitled_APCS_2020", 18, 20000, EVP_sha256(), keyLen, key);
////    for (unsigned int i = 0; i < sizeof(key); i++)
////    {
////        sprintf(hexResult + (i * 2), "%02x", 255 & digest[i]);
////        binResult[i] = digest[i];
////    };
//
//    for (int i = 0; i<keyLen; i++)
//        cout << key[i] << endl;

    return password;
}

void unsigedCharToHexString(unsigned char *key, int keyLen, string &ans) {
    //convert base-256 to hexadecimal

    char *digit = new char [16];
    for (int i = 0; i<10; i++) digit[i] = i + '0';
    for (int i = 10; i<16; i++) digit[i] = i - 10 + 'A';

    ans.resize(2*keyLen);
    for (int i = 0; i<keyLen; i++) {
        ans[2*i] = digit[(int) key[i] % 16];
        ans[2*i+1] = digit[(int) key[i] / 16];
    }
}

void viewProfileInfo() {
    cout << "\n\nYour personal information: [enter]\n";

    char keyPress = cin.get();
    fflush(stdin);
    preferencesMenu();
}

void changePassword() {
    cout << "\n\nYour password has been changed. [enter]\n";

    char keyPress = cin.get();
    fflush(stdin);
    preferencesMenu();
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
