#include "Lecturer.h"

bool isPermissible(string courseID) {
	return courseID == user::ID;
}

void printCourse(CourseNode* node, int& index) {
	
	cout << index << "\t" << node->courseName << "\t" << node->courseID << "\t"
		<< node->startingDate.y << "/" << node->startingDate.m << "/" << node->startingDate.d << "\t"
		<< node->startingTime.h << ":" << node->startingTime.m << ":" << node->startingTime.s << "\t"
		<< node->endingTime.h << ":" << node->endingTime.m << ":" << node->endingTime.s << "\t"
		<< node->room << endl;
		node = node->Next;
		index++;

  	
}

void printScoreboard(StudentList llist1, CourseStudentList llist2) {
	cout << "\n\nNo\t" << "Student Name\t" << "Student ID\t" << "Midterm\t" << "Final\t" << "Bonus\t" << "Total" << endl;
	int index = 1;
	for (CourseStudentNode* node = llist2.Head; node; node = node->Next) {
		StudentNode* tmp = llist1.find(node->studentID, ACTIVE);
		cout << index << "\t" << tmp->studentName << "\t" << tmp->studentID << "\t" << node->score.midterm
			<< "\t" << node->score.final << "\t" << node->score.bonus << "\t" << node->score.total << endl;
		index++;
	}
}

void printStudents(CourseStudentList llist) {
	CourseStudentNode* node = llist.Head;
	cout << "\n\n" << "No\t" << "Student ID" << endl;
	int index = 1;
	while (node) {
		cout << index << "\t" << node->studentID << endl;
		node = node->Next;
	}
}
void printArray(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		if (i == n - 1) cout << arr[i] << endl;
		else cout << arr[i] <<"\t";
	}
}
void printStudent(StudentNode* node, int &index) {
	cout << index << "\t" << node->studentName << "\t" << node->studentID << endl;
	index++;
}

//---
void lecturer_1_() {
	CourseList allCourses;
	SemesterList Sems;
	ClassList classes;
	
	if (!Sems.load()) 
		EXITCODE(6);
	
	// Find current Semester:
	SemesterNode* node = Sems.Head;
	while (node && node->current != CURRENT) node = node->Next;
	
	if (!classes.load()) EXITCODE(6);

	// Find all active classes:
	ClassNode* classNode = classes.Head;
	CourseList courseList;
	int index = 1;
	cout << "\n\n" << "No\t" << "Course Name\t" << "Course ID\t" << "Starting Date\t" << "Starting time\t" << "Ending time\t" << "Room" << endl;
	while (classNode) {
		if (classNode->active) {
			if (!courseList.load(node->semesterID, classNode->classID)) EXITCODE(6);
			for (CourseNode* coursenode = courseList.Head; coursenode; coursenode = coursenode->Next) {
				if (isPermissible(coursenode->courseID)) {
					printCourse(coursenode, index);
				}
			}
			courseList.destroy();
		}

		classNode = classNode->Next;
	}

	

	
}
//---------------------------------------------------------------------------------------------------
void lecturer_2_() {
//	input semester, class, course
//  string *s = new string[3]{"", "", ""};
//  fptr *p = new fptr[3]{inputSemester, inputCourse, inputClass};
//  inputdata(s, p, 0, 3, checkstaff_1_1);

//	StudentList stuList;
//	if (!stuList.load()) EXITCODE(6);
//	
//  string semesterID = s[0], courseID = s[1], classID = s[2];
//	SemesterList sems; ClassList classes; CourseList courses;
//	if (!sems.load()|| !classes.load()) EXITCODE(6);

//	if (sems.find(semesterID, ACTIVE)==nullptr || classes.find(classID, ACTIVE)==nullptr) EXITCODE(6);

//	if (!courses.load(semesterID, classID)) EXITCODE(6);
//	CourseNode* node = courses.find(courseID, ACTIVE);
//	if (node == nullptr) EXITCODE(6);
//	int index=1;
//	CourseStudentList llist;
//	if (!llist.load(semesterID, classID, courseID) EXITCODE(6);

//	for(CourseStudentNode* node= llist.Head; node; node = node->next){
//		StudentNode* stuNode = stuList.find(node->studentID, ACTIVE);
//		printStudent(stuNode, index);
//	}
//	
//	
	
}

//------------------------------------------------------------------------------------------------------------
void lecturer_3_() {
//	input semester, class, course
//  string *s = new string[3]{"", "", ""};
//  fptr *p = new fptr[3]{inputSemester, inputCourse, inputClass};
//  inputdata(s, p, 0, 3, checkstaff_1_1);

//	StudentList stuList;
//	if (!stuList.load()) EXITCODE(6);
//	
//  string semesterID = s[0], courseID = s[1], classID = s[2];
//	SemesterList sems; ClassList classes; CourseList courses;
//	if (!sems.load()|| !classes.load()) EXITCODE(6);

//	if (sems.find(semesterID, ACTIVE)==nullptr || classes.find(classID, ACTIVE)==nullptr) EXITCODE(6);
	
//	if (!courses.load(semesterID, classID)) EXITCODE(6);
//	CourseNode* node = courses.find(courseID, ACTIVE);
//	if (node == nullptr) EXITCODE(6);
//	int index=1;
//	CourseStudentList llist;
//	if (!llist.load(semesterID, classID, courseID) EXITCODE(6);



/*CourseStudentNode* stuNode = llist.Head;
	cout << "\n\n" << "No\t" <<"Student Name\t" << "Student ID\t" << "W01\t" << "W02\t" << "W03\t" << "W04\t" 
		 << "W05\t" << "W06\t"<< "W07\t" << "W08\t" << "W09\t" << "W10" << endl;
	int index = 1;
	while (stuNode) {
		StudentNode* node = stuList.find(stuNode->studentID, ACTIVE);
		cout << index << "\t" << node->studentName << "\t" << node->studentID << "\t";
		printArray(stuNode->attendance, 10);
		stuNode = stuNode->Next;
	}
*/


}

//-------------------------------------------------------------------------------------------------------------------------

void lecturer_4_() {
/*	input semester, class, course
	string *s = new string[4]{"", "", "",""};
	fptr *p = new fptr[4]{inputSemester, inputCourse, inputClass, inputStudent};
	inputdata(s, p, 0, 4, checkstaff_1_1);

	StudentList stuList;
	if (!stuList.load()) EXITCODE(6);
		
	string semesterID = s[0], courseID = s[1], classID = s[2], studentID = s[3];
	SemesterList sems; ClassList classes; CourseList courses;
	if (!sems.load()|| !classes.load()) EXITCODE(6);
	if (stuList.find(studentID, ACTIVE)== nullptr) EXITCODE(6);

	if (sems.find(semesterID, ACTIVE)==nullptr || classes.find(classID, ACTIVE)==nullptr) EXITCODE(6);

	if (!courses.load(semesterID, classID)) EXITCODE(6);
	CourseNode* node = courses.find(courseID, ACTIVE);
	if (node == nullptr) EXITCODE(6);
	int index=1;
	CourseStudentList llist;
	if (!llist.load(semesterID, classID, courseID) EXITCODE(6);
*/
/*
	int weekChoice, status;
	cout << "\n\nPlease enter a week to edit ";
	cin >> weekChoice;
	cout <<"\n\nPlease enter new status ";
	cin >> status;
	llist.find(studentID, ACTIVE)->attendance[weekChoice] = status;
*/

	
}


void lecturer_5_() {
/*
	input semester, class, course
	string *s = new string[4]{"", "", "","",""};
	fptr *p = new fptr[4]{inputSemester, inputCourse, inputClass, filePath};
	inputdata(s, p, 0, 4, checkstaff_1_1);

	StudentList stuList;
	if (!stuList.load()) EXITCODE(6);
		
	string semesterID = s[0], courseID = s[1], classID = s[2], filePath = s[3];
	SemesterList sems; ClassList classes; CourseList courses;
	if (!sems.load()|| !classes.load()) EXITCODE(6);
	if (stuList.find(studentID, ACTIVE)== nullptr) EXITCODE(6);

	if (sems.find(semesterID, ACTIVE)==nullptr || classes.find(classID, ACTIVE)==nullptr) EXITCODE(6);

	if (!courses.load(semesterID, classID)) EXITCODE(6);
	CourseNode* node = courses.find(courseID, ACTIVE);
	if (node == nullptr) EXITCODE(6);
	int index=1;
	CourseStudentList llist;
	if (!llist.load(semesterID, classID, courseID) EXITCODE(6);
	ScoreboardList board;
	if (!board.loadCSV()) 
	
*/

}


void lecturer_6_() {
/*
	input semester, class, course
	string *s = new string[4]{"", "", "",""};
	fptr *p = new fptr[4]{inputSemester, inputCourse, inputClass, inputStudent};
	inputdata(s, p, 0, 4, checkstaff_1_1);

	StudentList stuList;
	if (!stuList.load()) EXITCODE(6);
		
	string semesterID = s[0], courseID = s[1], classID = s[2], studentID = s[3];
	SemesterList sems; ClassList classes; CourseList courses;
	if (!sems.load()|| !classes.load()) EXITCODE(6);
	if (stuList.find(studentID, ACTIVE)== nullptr) EXITCODE(6);

	if (sems.find(semesterID, ACTIVE)==nullptr || classes.find(classID, ACTIVE)==nullptr) EXITCODE(6);

	if (!courses.load(semesterID, classID)) EXITCODE(6);
	CourseNode* node = courses.find(courseID, ACTIVE);
	if (node == nullptr) EXITCODE(6);
	int index=1;
	CourseStudentList llist;
	if (!llist.load(semesterID, classID, courseID) EXITCODE(6);
*/
/*
	CourseStudentNode* node = llist.find(studentID, ALL);
	if (node == nullptr) EXITCODE(6);
	
	string typeGrade;
	cout << "\n\nPlease enter a type of grade to edit ";
	getline(cin, typeGrade);
	cout << "\n\nPlease enter the new grade ";
	cin >> node->score.typeGrade;
	
*/
}


void lecturer_7_() {
/*
	input semester, class, course
	string *s = new string[3]{"", "", "",""};
	fptr *p = new fptr[3]{inputSemester, inputCourse, inputClass};
	inputdata(s, p, 0, 3, checkstaff_1_1);


		
	string semesterID = s[0], courseID = s[1], classID = s[2];
	if (!isPermissible(courseID)) {
		cout <<"\n\nYou are not allowed to access this course" << endl;
		EXITCODE(3);
	}
	SemesterList sems; ClassList classes; CourseList courses;
	if (!sems.load()|| !classes.load()) EXITCODE(6);
	

	if (sems.find(semesterID, ACTIVE)==nullptr || classes.find(classID, ACTIVE)==nullptr) EXITCODE(6);

	if (!courses.load(semesterID, classID)) EXITCODE(6);
	
	CourseNode* node = courses.find(courseID, ACTIVE);
	if (node == nullptr) EXITCODE(6);
	int index=1;
	CourseStudentList llist;
	if (!llist.load(semesterID, classID, courseID) EXITCODE(6);
*/
/*
	StudentList stuList;
	if (!stuList.load()) EXITCODE(6);
	printScoreboard(stulist, llist);
	
*/
}

