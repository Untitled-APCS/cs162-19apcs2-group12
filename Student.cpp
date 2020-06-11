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
	CourseNode* currentCourse;
	ClassNode* classNode;
	CourseList courses;

	bool flag = false;
	if (!sems.load() || !classes.load()) EXITCODE(6);
	string semesterID = sems.currentSemester;
	for (ClassNode* node = classes.Head; node; node = node->Next) {
		if (!courses.load(semesterID, node->classID)) EXITCODE(6);
		for (CourseNode* courseNode = courses.Head; courseNode; courseNode = courseNode->Next) {
			if (!stuCourse.load(semesterID, node->classID, courseNode->courseID)) EXITCODE(6);

			stuNode = stuCourse.find(user::ID, ACTIVE);
			if (stuNode != nullptr && currentTime >= courseNode->startingTime && currentTime <= courseNode->endingTime) {
				currentCourse = courseNode;
				flag = true;
				break;
			}
		}
			
		if (flag == true) {
			classNode = node;
			break;
		}
		courses.destroy();

	}
	
	int week = 0;
	Date startingDate = currentCourse->startingDate;
	Date currentDate;
	currentDate.capture();
	while (startingDate <= currentDate) {
		week++;
		startingDate.nextWeek();

	}
	cout << "\n\nPlease enter the checkin code ";
	getline(cin, code);
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
/*	//inputData : semesterID, studentID;
	// Print courseName, courseID, Day, starting time, ending time, rooms
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
	*/
}


void student_4() {
/*	// inputData: semesterID, studentID
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
	*/
}