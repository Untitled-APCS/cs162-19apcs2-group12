//
// Created by Duc An Chu on 5/31/20.
//

#include "Menu.h"

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
            EXITCODE(3)
    }
}

void logInMenu() {
    cout << "\n\nGreat to see you back! Will you...\n";
    cout << "[   enter   ] Login you account so that we can identify you, or\n";
    cout << "[ `  + enter] Exit the program if your work has been done or this is a mistake?\n";

    char keyPress = cin.get();
    fflush(stdin);

    if (keyPress != '`')
        logIn();
    else {
        cout << "\n\nYour effort was appreciated. Have a nice day. [enter]\n";

        fflush(stdin);
        char keyPress = cin.get();
        fflush(stdin);
    }
}

void logo() { // █
    cout << "\n";
    cout << " █▙    █▙   ██▙   █▙   ███████▙   █▙   ███████▙   █▙        ██████▙   █████▙  \n";
    cout << " ██    ██   ██▜▙  ██      ██      ██      ██      ██        ██        ██  ▜█▙ \n";
    cout << " ██    ██   ██ ▜▙ ██      ██      ██      ██      ██        ██████▙   ██   ██ \n";
    cout << " ██▙  ▟██   ██  ▜▙██      ██      ██      ██      ██        ██        ██  ▟█▛ \n";
    cout << "  ▜████▛    ▜█   ▜██      ▜█      ▜█      ▜█      ▜█████▙   ▜█████▙   ▜████▛  \n";
    //cout << "\n\n";
}

void preferencesMenu() {
    cout << "\n\n" << userTitle << ", this is the place you can adjust your preferences. So, what's next?\n";
    cout << "[1 + enter] View my profile information.\n";
    cout << "[2 + enter] Change my password.\n";
    cout << "[3 + enter] Change my workplace folder.\n";
    cout << "[4 + enter] Turn off Recommendation System.\n";
    cout << "[5 + enter] Turn off Mistyping Correction.\n";
    cout << "[A + enter] About us.\n";
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
                changeWorkspace();
                break;
            case '4':
                turnOffRecommendation();
                break;
            case '5':
                turnOffCorrection();
                break;
            case 'A':
            case 'a':
                aboutUs();
                break;
            case '`':
                mainMenu();
                break;
            default:
                passed = false;
        }
    } while (!passed);
}

void staffMenu() {
    cout << "\n\n" << getGreeting() << userTitle << ". The weather is so perfect today. Your job will be too. "
         << "What can I help you with?\n";
    cout << "[1 + enter] Semesters.\n";
    cout << "[2 + enter] Classes.\n";
    cout << "[3 + enter] Courses.\n";
    cout << "[4 + enter] Lecturers.\n";
    cout << "[5 + enter] Students.\n";
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
                staffSemesterMenu();
                break;
            case '2':
                staffClassMenu();
                break;
            case '3':
                staffCourseMenu();
                break;
            case '4':
                staffLecturerMenu();
                break;
            case '5':
                staffStudentMenu();
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

void staffStudentMenu() {
    cout << "\n\n" << "Alright, " << userTitle << ". What do you want to do with the students?\n";
    cout << "[1 + enter] Import list of students from file.\n";
    cout << "[2 + enter] Create a new student.\n";
    cout << "[3 + enter] Update a specific student.\n";
    cout << "[4 + enter] Remove a specific student.\n";
    cout << "[5 + enter] View list of students of a class.\n";
    cout << "[` + enter] Back.\n";

    char keyPress;
    bool passed;

    do {
        keyPress = cin.get();
        fflush(stdin);
        passed = true;

        switch (keyPress) {
            case '1':
                staff_5_1();
                break;
            case '2':
                testStaffStudent();
                break;
            case '3':
                testStaffStudent();
                break;
            case '4':
                testStaffStudent();
                break;
            case '5':
                testStaffStudent();
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

void staffLecturerMenu() {
    cout << "\n\n" << "Alright, " << userTitle << ". What do you want to do with the lecturers?\n";
    cout << "[1 + enter] Import list of lecturers from file.\n";
    cout << "[2 + enter] Create a new lecturer.\n";
    cout << "[3 + enter] Update a specific lecturer.\n";
    cout << "[4 + enter] Remove a specific lecturer.\n";
    cout << "[5 + enter] View list of lecturers.\n";
    cout << "[` + enter] Back.\n";

    char keyPress;
    bool passed;

    do {
        keyPress = cin.get();
        fflush(stdin);
        passed = true;

        switch (keyPress) {
            case '1':
                testStaffLecturer();
                break;
            case '2':
                testStaffLecturer();
                break;
            case '3':
                testStaffLecturer();
                break;
            case '4':
                testStaffLecturer();
                break;
            case '5':
                testStaffLecturer();
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

void staffSemesterMenu() {
    cout << "\n\n" << "Alright, " << userTitle << ". What do you want to do with the semesters?\n";
    cout << "[1 + enter] Create a new semester.\n";
    cout << "[2 + enter] Update a specific semester.\n";
    cout << "[3 + enter] Remove a specific semester.\n";
    cout << "[4 + enter] View list of semesters.\n";
    cout << "[` + enter] Back.\n";

    char keyPress;
    bool passed;

    do {
        keyPress = cin.get();
        fflush(stdin);
        passed = true;

        switch (keyPress) {
            case '1':
                staff_1_1();
                break;
            case '2':
                staff_1_2();
                break;
            case '3':
                staff_1_3();
                break;
            case '4':
                staff_1_4();
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

void staffClassMenu() {
    cout << "\n\n" << "Alright, " << userTitle << ". What do you want to do with the classes?\n";
    cout << "[1 + enter] Import list of classes from file.\n";
    cout << "[2 + enter] Create a new class.\n";
    cout << "[3 + enter] Update a specific class.\n";
    cout << "[4 + enter] Remove a specific class.\n";
    cout << "[5 + enter] View list of classes.\n";
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
            case '`':
                staffMenu();
                break;
            default:
                //testStudent();
                passed = false;
        }
    } while (!passed);
}

void staffCourseMenu() {
    cout << "\n\n" << "Alright, " << userTitle << ". What do you want to do with the courses?\n";
    cout << "[1 + enter] Import list of courses from file.\n";
    cout << "[2 + enter] Create a new courses.\n";
    cout << "[3 + enter] Update a specific course.\n";
    cout << "[4 + enter] Remove a specific course.\n";
    cout << "[5 + enter] View list of courses.\n";
    cout << "[6 + enter] Remove a specific student from a course.\n";
    cout << "[7 + enter] Add a specific student to a course.\n";
    cout << "[8 + enter] View list of students of a course.\n";
    cout << "[9 + enter] View a scoreboard.\n";
    cout << "[0 + enter] Export a scoreboard to file.\n";
    cout << "[A + enter] View an attendance list.\n";
    cout << "[B + enter] Export an attendance list to file.\n";
    cout << "[` + enter] Back.\n";

    char keyPress;
    bool passed;

    do {
        keyPress = cin.get();
        fflush(stdin);
        passed = true;

        switch (keyPress) {
            case '1':
                staff_3_1();
                break;
            case '2':
                staff_3_2();
                break;
            case '3':
                staff_3_3();
                break;
            case '4':
                staff_3_4();
                break;
            case '5':
                staff_3_5();
                break;
            case '6':
                staff_3_6();
                break;
            case '7':
                staff_3_7();
                break;
            case '8':
                staff_3_8();
                break;
            case '9':
                staff_3_9();
                break;
            case '0':
                staff_3_10();
                break;
            case 'A':
            case 'a':
                staff_3_11();
                break;
            case 'B':
            case 'b':
                staff_3_12();
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
                lecturer_1_();
                break;
            case '2':
                lecturer_2_();
                break;
            case '3':
                lecturer_3_();
                break;
            case '4':
                lecturer_4_();
                break;
            case '5':
                lecturer_5_();
                break;
            case '6':
                lecturer_6_();
                break;
            case '7':
                lecturer_7_();
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
                student_1();
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

void aboutUs() {
    cout << "\n\nUntitled Team - CS162 Final Project\n";
    cout << "- Chu Duc An\n";
    cout << "- Hoang Vu\n";
    cout << "- Ngo Nhat Khang\n";
    cout << "- Ta Huynh Tuan Kiet\n";
    cout << "[enter]";

    char keyPress = cin.get();
    fflush(stdin);
    preferencesMenu();
}

