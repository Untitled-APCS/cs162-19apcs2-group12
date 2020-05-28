//
// Created by Duc An Chu on 5/26/20.
//

#include "AllRoles.h"

void mainMenu() {
    switch (user::type) {
        case STAFF:
            staffMenu();
            break;
        case LECTURER:
            lecturerMenu();
            break;
        case STUDENT:
            studentMenu();
            break;
        default:
            cout << "Oops! Something went wrong.";
            logOut();
    }
}

void logIn() {
    user::ID = "19125001";
    cin >> user::type;
    user::gender = MALE;
    user::fullName = "Chu Duc An";

    cout << "Login successfully. [enter]\n";

    char keyPress = cin.get();
    fflush(stdin);
    mainMenu();
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
    //hashing password using PBKDF2 with 10000 iterations of HMAC-SHA256

    const int keyLen = 50;
    string ans;

    cppcrypto::hmac hmac(cppcrypto::sha256(), password);
    unsigned char *key = new unsigned char [keyLen];
    pbkdf2(hmac, (const unsigned char*)"Untitled_APCS_2020", 18, 20000, key, sizeof(unsigned char) * keyLen);

    unsigedCharToHexString(key, keyLen, ans);
    delete [] key;
    return ans;
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

void logInMenu() {
    cout << "\n\nGreat to see you back! Will you...\n";
    cout << "[   enter   ] Login you account so that we can identify you, or\n";
    cout << "[ `  + enter] Exit the program if your work has been done or this is a mistake?\n\n";

    char keyPress = cin.get();
    fflush(stdin);

    if (keyPress != '`') {
        cout << endl;
        logIn();
    } else {
        cout << "\nYour effort was appreciated. Have a nice day.\n\n";
    }
}

void logo() { // █
    cout << "\n";
    cout << " █▙     █▙   ██▙   █▙   ███████▙   █▙   ███████▙   █▙        ██████▙   █████▙  \n";
    cout << " ██     ██   ██▜▙  ██      ██      ██      ██      ██        ██        ██  ▜█▙ \n";
    cout << " ██     ██   ██ ▜▙ ██      ██      ██      ██      ██        ██████▙   ██   ██ \n";
    cout << " ██▙   ▟██   ██  ▜▙██      ██      ██      ██      ██        ██        ██  ▟█▛ \n";
    cout << "  ▜█████▛    ▜█   ▜██      ▜█      ▜█      ▜█      ▜█████▙   ▜█████▙   ▜████▛  \n";
    //cout << "\n\n";
}

void preferencesMenu() {
    cout << "\n\n" << userTitle << ", this is the place you can adjust your preferences. So, what next?\n";
    cout << "[1 + enter] View my profile information.\n";
    cout << "[2 + enter] Change my password.\n";
    cout << "[3 + enter] Turn off Recommendation System.\n";
    cout << "[4 + enter] Turn off Mystyping Correction.\n";
    cout << "[` + enter] Back.\n";

    char keyPress;
    bool passed;

    do {
        keyPress = cin.get();
        fflush(stdin);
        passed = true;

        switch (keyPress) {
            case '1':
                viewProfileInfo();
                break;
            case '2':
                changePassword();
                break;
            case '3':
                turnOffRecommendation();
                break;
            case '4':
                turnOffCorrection();
                break;
            case '`':
                mainMenu();
                break;
            default:
                passed = false;
        }
    } while (!passed);
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

void staffMenu() {
    cout << "\n\n" << getGreeting() << userTitle << ". The weather is so perfect today. Your job will be too. "
         << "What can I help you with?\n";
    cout << "[1 + enter] Classes.\n";
    cout << "[2 + enter] Courses.\n";
    cout << "[P + enter] Preferences.\n";
    cout << "[` + enter] Log out.\n";

    char keyPress;
    bool passed;

    do {
        keyPress = cin.get();
        fflush(stdin);
        passed = true;

        switch (keyPress) {
            case '1':
                classMenu();
                break;
            case '2':
                courseMenu();
                break;
            case 'P':
            case 'p':
                preferencesMenu();
                break;
            case '`':
                logOut();
                break;
            default:
                //testStudent();
                passed = false;
        }
    } while (!passed);
}

void lecturerMenu() {
    cout << "\n\n" << getGreeting() << userTitle << ". It is believed that many young people have been inspired by you. "
         << "What can I help you with?\n";
    cout << "[1 + enter] View list of courses in the current semester.\n";
    cout << "[2 + enter] View list of students of a course.\n";
    cout << "[3 + enter] View attendance list of a course.\n";
    cout << "[4 + enter] Edit attendance of a student.\n";
    cout << "[5 + enter] Import scoreboard of a course from file.\n";
    cout << "[6 + enter] Edit grade of a student.\n";
    cout << "[7 + enter] View scoreboard of a course.\n";
    cout << "[P + enter] Preferences.\n";
    cout << "[` + enter] Log out.\n";

    char keyPress;
    bool passed;

    do {
        keyPress = cin.get();
        fflush(stdin);
        passed = true;

        switch (keyPress) {
            case '1':
                testLecturer();
                break;
            case '2':
                testLecturer();
                break;
            case '3':
                testLecturer();
                break;
            case '4':
                testLecturer();
                break;
            case '5':
                testLecturer();
                break;
            case '6':
                testLecturer();
                break;
            case '7':
                testLecturer();
                break;
            case 'P':
            case 'p':
                preferencesMenu();
                break;
            case '`':
                logOut();
                break;
            default:
                //testStudent();
                passed = false;
        }
    } while (!passed);
}

void studentMenu() {
    cout << "\n\nHi, " << userTitle << ". You must have been hard-working this week. "
         << "What do you want to do?\n";
    cout << "[1 + enter] Check-in my class right now.\n";
    cout << "[2 + enter] View my check-in result in this semester.\n";
    cout << "[3 + enter] View my schedules in this semester.\n";
    cout << "[4 + enter] View my scores in this semester.\n";
    cout << "[P + enter] Preferences.\n";
    cout << "[` + enter] Log out.\n";

    char keyPress;
    bool passed;

    do {
        keyPress = cin.get();
        fflush(stdin);
        passed = true;

        switch (keyPress) {
            case '1':
                testStudent();
                break;
            case '2':
                testStudent();
                break;
            case '3':
                testStudent();
                break;
            case '4':
                testStudent();
                break;
            case 'P':
            case 'p':
                preferencesMenu();
                break;
            case '`':
                logOut();
                break;
            default:
                //testStudent();
                passed = false;
        }
    } while (!passed);
}

void classMenu() {
    cout << "\n\n" << "Alright, " << userTitle << ". What do you want to do with the classes?\n";
    cout << "[1 + enter] Inport students of a class from file.\n";
    cout << "[2 + enter] Add a new student to a class.\n";
    cout << "[3 + enter] Edit a student.\n";
    cout << "[4 + enter] Remove a student.\n";
    cout << "[5 + enter] Move a student to another class.\n";
    cout << "[6 + enter] View list of class.\n";
    cout << "[7 + enter] View list of students in a class.\n";
    cout << "[P + enter] Preferences.\n";
    cout << "[` + enter] Back.\n";

    char keyPress;
    bool passed;

    do {
        keyPress = cin.get();
        fflush(stdin);
        passed = true;

        switch (keyPress) {
            case '1':
                testStaffClass();
                break;
            case '2':
                testStaffClass();
                break;
            case '3':
                testStaffClass();
                break;
            case '4':
                testStaffClass();
                break;
            case '5':
                testStaffClass();
                break;
            case '6':
                testStaffClass();
                break;
            case '7':
                testStaffClass();
                break;
            case 'P':
            case 'p':
                preferencesMenu();
                break;
            case '`':
                staffMenu();
                break;
            default:
                //testStudent();
                passed = false;
        }
    } while (!passed);
}

void courseMenu() {
    cout << "\n\n" << "Alright, " << userTitle << ". What do you want to do with the courses?\n";
    cout << "[1 + enter] Academic years and semesters.\n";
    cout << "[2 + enter] Import courses from file.\n";
    cout << "[3 + enter] Add a new course.\n";
    cout << "[4 + enter] Edit a course.\n";
    cout << "[5 + enter] Remove a course.\n";
    cout << "[6 + enter] Remove a student from a course.\n";
    cout << "[7 + enter] Add a student to a course.\n";
    cout << "[8 + enter] View list of courses in the current semester.\n";
    cout << "[9 + enter] View list of student of a course.\n";
    cout << "[0 + enter] View attendance list of a course.\n";
    cout << "[A + enter] Lecturers.\n";
    cout << "[P + enter] Preferences.\n";
    cout << "[` + enter] Back.\n";

    char keyPress;
    bool passed;

    do {
        keyPress = cin.get();
        fflush(stdin);
        passed = true;

        switch (keyPress) {
            case '1':
                testStaffCourse();
                break;
            case '2':
                testStaffCourse();
                break;
            case '3':
                testStaffCourse();
                break;
            case '4':
                testStaffCourse();
                break;
            case '5':
                testStaffCourse();
                break;
            case '6':
                testStaffCourse();
                break;
            case '7':
                testStaffCourse();
                break;
            case '8':
                testStaffCourse();
                break;
            case '9':
                testStaffCourse();
                break;
            case '0':
                testStaffCourse();
                break;
            case 'A':
            case 'a':
                testStaffCourse();
                break;
            case 'P':
            case 'p':
                preferencesMenu();
                break;
            case '`':
                staffMenu();
                break;
            default:
                //testStudent();
                passed = false;
        }
    } while (!passed);
}

void testStaffClass() {
    cout << "\n\nStaff_class_function has been tested successfully. [enter]\n";

    char keyPress = cin.get();
    fflush(stdin);
    classMenu();
}

void testStaffCourse() {
    cout << "\n\nStaff_course_function has been tested successfully. [enter]\n";

    char keyPress = cin.get();
    fflush(stdin);
    courseMenu();
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
