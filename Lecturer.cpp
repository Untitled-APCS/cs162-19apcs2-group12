#include "Lecturer.h"

bool isPermissible(string courseID) {
	return courseID == user::ID;
}

void printCourseList(CourseList courses) {
	CourseNode* node = courses.Head;
	cout << "\n\n" << "No\t" << "Course Name\t" << "Course ID\t" << "Starting Date\t" << "Starting time\t" << "Ending time\t" << "Room" << endl;
	int i = 1;
	while (node) {
		cout << i << "\t" << node->courseName << "\t" << node->courseID << "\t"
			<< node->startingDate.y << "/" << node->startingDate.m << "/" << node->startingDate.d << "\t"
			<< node->startingTime.h << ":" << node->startingTime.m << ":" << node->startingTime.s << "\t"
			<< node->endingTime.h << ":" << node->endingTime.m << ":" << node->endingTime.s << "\t"
			<< node->room << endl;
		node = node->Next;
  	}
}

CourseList Permissions(CourseList courses) {
	CourseNode* node = courses.Head;
	CourseList permissions;
	while (node) {
		if (isPermissible(node->courseID)) permissions.pushBack(node);
		node = node->Next;
	}
	return permissions;
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
	ClassList activeClass;
	while (classNode) {
		if (classNode->active) activeClass.pushBack(classNode);
		classNode = classNode->Next;
	}

	// Load all courses from all active classes.
	classNode = activeClass.Head;
	while (classNode) {
		if (!allCourses.load(node->semesterID, classNode->classID)) EXITCODE(6);
		classNode = classNode->Next;
	}

	CourseList permissions = Permissions(allCourses);

	printCourseList(permissions);

	
}
//---------------------------------------------------------------------------------------------------
void lecturer_2_() {
//	input semester, class, course
//  string *s = new string[2]{"", "", ""};
//  fptr *p = new fptr[2]{inputSemester, inputCourse};
//  inputdata(s, p, 0, 2, checkstaff_1_1);
//
//  string semesterID = s[0], courseID = s[2];
	 
//  SemesterList SemesterList;
//  if (!SemesterList.load() || SemmesterList.find(semesterID, ALL)==nullptr)  exitcode(6);

//	if (!isPermissible(courseID)){
//		cout << '\n\n' << "You are not allowed to access this course" << endl;
//		EXITCODE(3)
//	}
	/*ClassList llist1;
	if (!llist1.load()) EXITCODE(6);

	ClassNode* node = llist1.Head;
	CourseStudentList llist2;
	while (node) {
		if (!llist2.load(semesterID, node->classID, courseID)) EXITCODE(6);
		node = node->Next;
	}

	printStudents(llist2);
	*/
	
}

//------------------------------------------------------------------------------------------------------------
void lecturer_3_() {
	//	input semester, class, course
//  string *s = new string[2]{"", "", ""};
//  fptr *p = new fptr[2]{inputSemester, inputCourse};
//  inputdata(s, p, 0, 2, checkstaff_1_1);
//
//  string semesterID = s[0], courseID = s[2];

//  SemesterList SemesterList;
//  if (!SemesterList.load() || SemmesterList.find(semesterID, ALL)==nullptr)  exitcode(6);


//	if (!isPermissible(courseID)){
//		cout << '\n\n' << "You are not allowed to access this course" << endl;
//		EXITCODE(3)
//	}
	

/*ClassList llist1;
	if (!llist1.load()) EXITCODE(6);

	ClassNode* node = llist1.Head;
	CourseStudentList llist2;
	while (node) {
		if (!llist2.load(semesterID, node->classID, courseID)) EXITCODE(6);
		node = node->Next;
	}

	
*/


/*CourseStudentNode* stuNode = llist2.Head;
	cout << "\n\n" << "No\t" << "Student ID\t" << "W01\t" << "W02\t" << "W03\t" << "W04\t" 
		 << "W05\t" << "W06\t"<< "W07\t" << "W08\t" << "W09\t" << "W10" << endl;
	int index = 1;
	while (stuNode) {
		cout << index << "\t" << stuNode->studentID << "\t"; 
		printArray(stuNode->attendance, 10);
		stuNode = stuNode->Next;
	}
*/


}

//-------------------------------------------------------------------------------------------------------------------------

void lecturer_4_() {
	//	input semester, class, course
//  string *s = new string[3]{"", "", ""};
//  fptr *p = new fptr[3]{inputSemester, inputClass, inputCourse};
//  inputdata(s, p, 0, 3, checkstaff_1_1);
//
//  string semesterID = s[0], courseID = s[2], classID = s[1];

//  SemesterList semesterList;
//  if (!semesterList.load() || semmesterList.find(semesterID, ALL)==nullptr)  exitcode(6);

//  ClassList classList;
//  if (!classList.load() || classList.find(classID, ALL) == nullptr) EXITCODE(6);

//  CourseList courseList;
//	if (!courseList.load() || courseList.find(courseID, ALL) == nullptr) EXITCODE(6);

//	if (!isPermissible(courseID)){
//		cout << '\n\n' << "You are not allowed to access this course" << endl;
//		EXITCODE(3)
//	


/*
	CourseStudentList llist;
	if (!llist.load(semesterID, classID, courseID)) EXITCODE(6);
	
	string studentID;
	cout << "\n\nPlease enter the student's ID;
	getline(cin, studentID);

	CourseStudentNode* node = llist.Head;
	bool flag = false;
	while (node){
		if (node->studentID == studentID && node->active) {
			flag = true;
			break;
		}
		node = node->Next;
	}
	if (!flag) {
		cout << "\n\nThe student does not exist"<< endl;
		EXITCODE(6);
	}

	int weekChoice;
	cout << "\n\nPlease enter a week to edit ";
	cin >> weekChoice;
	
	int status;
	cout << "\n\nPlease enter new status ";
	cin >> status;

	node->attendance[weekChoice] = status;

	delete [] s;
	delete [] p;
	*/

}