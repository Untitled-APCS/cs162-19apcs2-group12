//
// Created by Duc An Chu on 5/26/20.
//

#include "Student.h"

void student_1() {
	//inputData: semesterID, classID, courseID..
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



void student_3() {
	//inputData : semesterID, studentID;
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
				if (stuList.find(studentID, ACTIVE)) {

				}

			}
		}

		courses.destroy();



	}

	
	
	
}