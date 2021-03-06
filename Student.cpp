//
// Created by Duc An Chu on 5/26/20.
//

#include "Student.h"

void student_1() {
	Time currentTime;
	
	SemesterList sems;
	ClassList classes;
	CourseStudentList stuCourse;
	CourseStudentNode *stuNode;
	string code = "";
	CourseNode* courseNode, *currentCourse = nullptr;
	ClassNode* classNode, *currentClass = nullptr;
	CourseList courses;

	int week;
	Date startingDate, currentDate;

	bool flag = false;
	if (!sems.load() || !classes.load()) EXITCODE(6);
	string semesterID = sems.currentSemester;
	for (classNode = classes.Head; classNode; classNode = classNode->Next) {
		if (!courses.load(semesterID, classNode->classID)) EXITCODE(6);
		for (courseNode = courses.Head; courseNode; courseNode = courseNode->Next) {
			if (!stuCourse.load(semesterID, classNode->classID, courseNode->courseID)) EXITCODE(6);

			stuNode = stuCourse.find(user::ID, ACTIVE);
			if (stuNode != nullptr) {

			    //check if courseNode occurs on currentDate
                week = 0;
                startingDate = courseNode->startingDate;
                currentDate.capture();
                while (startingDate <= currentDate) {
                    week++;
                    startingDate.nextWeek();
                }

                startingDate = courseNode->startingDate;
                for (int i = 0; i<week-1; i++)
                    startingDate.nextWeek();

                if (currentDate == startingDate &&
                    currentTime >= courseNode->startingTime &&
                    currentTime <= courseNode->endingTime) {
                    currentCourse = courseNode;
                    currentClass = classNode;
                    flag = true;
                    break;
                }
			}

			stuCourse.destroy();
		}

		if (!flag)
		    courses.destroy();
	}

	//courses.print();

	if (!flag) {
	    cout << "\n\nYou currently have no available courses. Please try again later or contact your lecturer. [enter]\n";

	    fflush(stdin);
	    char keyPress = cin.get();
	    fflush(stdin);

	    studentMenu();
	    return;
	}

	cout << "\n\nPreparing to verify your attendance in...\n";
	cout << "Course: " << currentCourse->courseID << " - " << currentCourse->courseName << endl;
	cout << "Class: " << currentClass->classID << endl;
	cout << "Week: " << week << endl;
	cout << "Please enter the check-in code provided by your lecturer to complete the verification.\n";
	cout << "[  enter  ] Verify my attendance.\n";
	cout << "[` + enter] Back to menu.\n\n";

	while (true) {
        cout << "Your check-in code: ";

        fflush(stdin);
        getline(cin, code);
        fflush(stdin);

        if (code.find('`') != string::npos) {
            studentMenu();
            return;
        }

        if (code == getCheckInCode(semesterID, currentClass->classID, currentCourse->courseID, week)) {
            stuNode->attendance[week-1] = true;
            stuCourse.save(semesterID, currentClass->classID, currentCourse->courseID);

            cout << "Your attendance is verified. Have a good lesson. [enter]\n";

            fflush(stdin);
            char keyPress = cin.get();
            fflush(stdin);
            studentMenu();
            return;
        }

        cout << "Your code is invalid. Please try one more time.\n";
	}
	studentMenu();
	//AttendanceCode
	// Enter the week. Recommend .
}

string getDay(Date date) {
	int year = (date.y % 100);
	year = date.m < 3 ? year-1 : year ;
	int cen = date.y / 100;
	int month = (((date.m - 2) % 12) + 12) % 12;
	int result = (date.d + (int)((double)(2.6 * month - 0.2)) - 2 * cen + year + year / 4 + cen / 4) % 7;
	switch (result) {
	case 0: return "Sunday";
	case 1: return "Monday";
	case 2: return "Tuesday";
	case 3: return "Wednesday";
	case 4: return "Thursday";
	case 5: return "Friday";
	case 6: return "Saturday";

	}
	return "";
}
bool isInRange( CourseNode* node) {
	Date currentDate; // get current date
	Date endingDate = node->startingDate;
	for (int i = 1; i <= 10; i++) endingDate.nextWeek();
	return currentDate <= endingDate;
}
void student_2() {
	string* s = new string[2]{ "","" };
	fPtr* p = new fPtr[2]{ inputSemester, inputStudent };
	inputData(s, p, 2, 0, checkStudent_2);
	if (s[0].length() == 0 || s[1].length() == 0) {
		studentMenu();
		delete[]s;
		delete[]p;
		return;
	}
	string semesterID = s[0], studentID = s[1];
	CourseStudentList llist;
	CourseList courses;
	ClassList classes;
	CourseStudentList stuList;
	cout << "Course Name\tCourse ID\tMidterm\tFinal\tBonus\tTotal" << endl;
	if (!classes.load()) EXITCODE(6);
	for (ClassNode* classNode = classes.Head; classNode; classNode = classNode->Next) {
		if (!courses.load(semesterID, classNode->classID)) EXITCODE(6);
		for (CourseNode* courseNode = courses.Head; courseNode; courseNode = courseNode->Next) {
			if (courses.find(courseNode->courseID, ACTIVE)) {
				if (!stuList.load(semesterID, classNode->classID, courseNode->courseID)) EXITCODE(6);
				CourseStudentNode* stuNode = stuList.find(studentID, ACTIVE);
				if (stuNode) {
					cout << courseNode->courseName << "\t" << courseNode->courseID << "\t";
					for (int i = 0; i < 10; i++) {
						if (i == 9) cout << stuNode->attendance[i] << endl;
						else cout << stuNode->attendance[i] << "\t";
					}
				}
				stuList.destroy();

			}
		}

		courses.destroy();
	}
	cout << "\n\nBack to menu" << endl;
	studentMenu();
	delete[]s;
	delete[]p;
}

void printCourse(CourseNode* node) {
	cout << "Course ID: " << node->courseID << endl;
	cout << "Course Name: " << node->courseName << endl;
	cout << "Starting Date: " << node->startingDate.y << " " << node->startingDate.m << " " << node->startingDate.d << endl;
	cout << "Day: " << getDay(node->startingDate) << endl;
	cout << "Starting Time: " << node->startingTime.h << " " << node->startingTime.m << " " << node->startingTime.s << endl;
	cout << "Ending Time: " << node->endingTime.h << " " << node->endingTime.m << " " << node->endingTime.s << endl;
	cout << "Room: " << node->room << endl;
}


void student_3() {
	
	
	//Print courseName, courseID, Day, starting time, ending time, rooms
	string* s = new string[2]{ "","" };
	fPtr* p = new fPtr[2]{ inputSemester, inputStudent };
	inputData(s, p, 2 ,0, checkStudent_3);
	if (s[0].length() == 0 || s[1].length() == 0) {
		studentMenu();
		delete[]s;
		delete[]p;
		return;
	}
	string semesterID = s[0], studentID = s[1];

	CourseStudentList llist;
	CourseList courses;
	ClassList classes;
	CourseStudentList stuList;
	
	if (!classes.load()) EXITCODE(6);
	for (ClassNode* classNode = classes.Head; classNode; classNode = classNode->Next) {
		if (!courses.load(semesterID, classNode->classID)) EXITCODE(6);
		for (CourseNode* courseNode = courses.Head; courseNode; courseNode = courseNode->Next) {
			if (courses.find(courseNode->courseID, ACTIVE)){
				if (!stuList.load(semesterID, classNode->classID, courseNode->courseID)) EXITCODE(6);
				if (stuList.find(studentID, ACTIVE) && isInRange(courseNode)) {
					printCourse(courseNode);
				}
				stuList.destroy();

			}
		}

		courses.destroy();
	}
	cout << "\n\nBack to menu" << endl;
	studentMenu();
	delete[]s;
	delete[]p;
	
}


void student_4() {
	//inputData: semesterID, studentID
	string* s = new string[2]{ "","" };
	fPtr* p = new fPtr[2]{ inputSemester, inputStudent };
	inputData(s, p, 2, 0, checkStudent_4);
	if (s[0].length() == 0 || s[1].length() == 0) {
		studentMenu();
		delete[]s;
		delete[]p;
		return;
	}
	string semesterID = s[0], studentID = s[1];
	CourseStudentList llist;
	CourseList courses;
	ClassList classes;
	CourseStudentList stuList;
	cout << "Course Name\tCourse ID\tMidterm\tFinal\tBonus\tTotal" << endl;
	if (!classes.load()) EXITCODE(6);
	for (ClassNode* classNode = classes.Head; classNode; classNode = classNode->Next) {
		if (!courses.load(semesterID, classNode->classID)) EXITCODE(6);
		for (CourseNode* courseNode = courses.Head; courseNode; courseNode = courseNode->Next) {
			if (courses.find(courseNode->courseID, ACTIVE)) {
				if (!stuList.load(semesterID, classNode->classID, courseNode->courseID)) EXITCODE(6);
				CourseStudentNode* stuNode = stuList.find(studentID, ACTIVE);
				if ( stuNode ) {
					cout << courseNode->courseName << "\t" << courseNode->courseID << "\t" << stuNode->score.midterm
						<< "\t" << stuNode->score.final << "\t" << stuNode->score.bonus << "\t" << stuNode->score.total << endl;
				}
				stuList.destroy();

			}
		}

		courses.destroy();
	}
	cout << "\n\nBack to menu" << endl;
	studentMenu();
	delete[]s;
	delete[]p;
}

bool checkStudent_3(string* s, int n) {
	return true;
}
bool checkStudent_1(string* s, int n) {
	return true;
}
bool checkStudent_2(string* s, int n) {
	return true;
}
bool checkStudent_4(string* s, int n) {
	return true;
}