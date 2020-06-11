#include "Lecturer.h"


void setAttendanceCourse() {
	// inputData: semesterID, classID, courseID
	// AttendanceCode

	// Enter the week. Recommend.
}
bool checklecturer_1(string* s, int n) {
	SemesterList llist;
	if (!llist.load()) {
		EXITCODE_V(6, false);
	}
	if (s[0] != llist.currentSemester) {
		cout << "\nThis is not current semester " << endl;
		return false;
	}
	return true;

}
bool checklecturer_2(string* s, int n) {
	ClassList classes;
	SemesterList semesters;
	CourseList courses;
	if (!semesters.load() || !classes.load()) {
		EXITCODE_V(6, false);
	}
	for (SemesterNode* semNode = semesters.Head; semNode; semNode = semNode->Next) {
		for (ClassNode* classNode = classes.Head; classNode; classNode = classNode->Next) {
			courses.load(semNode->semesterID, classNode->classID);
			if (courses.find(s[n - 1], ALL)) return true;
		}
	}
	cout << "\n\nThis course does not exist." << endl;
	return false;
}

bool checklecturer_3(string* s, int n) {

	return true;
}
bool checklecturer_4(string* s, int n) {
	ClassList classes;
	SemesterList semesters;
	CourseList courses;
	CourseStudentList stuList;
	if (!semesters.load() || !classes.load()) {
		EXITCODE_V(6, false);
	}
	if (s[0] != semesters.currentSemester) {
		fflush(stdin);
		char keyPress = cin.get();
		fflush(stdin);
		cout << "\n\nYou are not allowed to make changes in this semester" << endl;
		return false;
	}
	////if (classes.find(s[1], ACTIVE) == nullptr) {
	////	cout << "\n\nThis class does not exist" << endl;
	////	return false;
	////}
	/////*bool flag = false;
	//for (SemesterNode* semNode = semesters.Head; semNode; semNode = semNode->Next) {
	//	for (ClassNode* classNode = classes.Head; classNode; classNode = classNode->Next) {
	//		if(!courses.load(semNode->semesterID, classNode->classID)) EXITCODE_V(6, false);
	//		CourseNode* courseNode = courses.find(s[2], ACTIVE);
	//		if (courseNode == nullptr) {
	//			cout << "\n\nThis course does not exist" << endl;
	//			return false;
	//		}
	//		if (!stuList.load(semNode->semesterID, classNode->classID, courseNode->courseID)) EXITCODE_V(6, false);
	//		CourseStudentNode* stuNode = stuList.find(s[n - 1], ACTIVE);
	//		if (stuNode == nullptr) {
	//			cout << "\n\nThis student does not exist" << endl;
	//			return false;
	//		}
	//		

	//	}
	//}*/
	return true;

}
bool checklecturer_5(string* s, int n) {
	
	ClassList classes;
	SemesterList semesters;
	CourseList courses;
	CourseStudentList stuList;
	if (!semesters.load() || !classes.load()) {
		EXITCODE_V(6, false);
	}
	if (s[0] != semesters.currentSemester) {
		fflush(stdin);
		char keyPress = cin.get();
		fflush(stdin);
		cout << "\n\nYou are not allowed to make changes in this semester" << endl;
		return false;
	}
	/*if (classes.find(s[1], ACTIVE) == nullptr) {
		cout << "\n\nThis class does not exist" << endl;
		return false;
	}
	bool flag = false;
	for (SemesterNode* semNode = semesters.Head; semNode; semNode = semNode->Next) {
		for (ClassNode* classNode = classes.Head; classNode; classNode = classNode->Next) {
			if (!courses.load(semNode->semesterID, classNode->classID)) EXITCODE_V(6, false);
			CourseNode* courseNode = courses.find(s[2], ACTIVE);
			if (courseNode == nullptr) {
				cout << "\n\nThis course does not exist" << endl;
				return false;
			}
			if (!stuList.load(semNode->semesterID, classNode->classID, courseNode->courseID)) EXITCODE_V(6, false);
			CourseStudentNode* stuNode = stuList.find(s[3], ACTIVE);
			if (stuNode == nullptr) {
				cout << "\n\nThis student does not exist" << endl;
				return false;
			}


		}
		if (!isScoreBoardListCSV(s[n - 1])) {
			cout << "\n\nThis is not a csv file" << endl;
			return false;
		}
	}*/
	return true;
}
	
bool checklecturer_6(string * s, int n) {
	ClassList classes;
	SemesterList semesters;
	CourseList courses;
	CourseStudentList stuList;
	if (!semesters.load() || !classes.load()) {
		EXITCODE_V(6, false);
	}
	if (s[0] != semesters.currentSemester) {
		fflush(stdin);
		char keyPress = cin.get();
		fflush(stdin);
		cout << "\n\nYou are not allowed to make changes in this semester" << endl;
		return false;
	}
	/*if (classes.find(s[1], ACTIVE) == nullptr) {
		cout << "\n\nThis class does not exist" << endl;
		return false;
	}
	bool flag = false;
	for (SemesterNode* semNode = semesters.Head; semNode; semNode = semNode->Next) {
		for (ClassNode* classNode = classes.Head; classNode; classNode = classNode->Next) {
			if (!courses.load(semNode->semesterID, classNode->classID)) EXITCODE_V(6, false);
			CourseNode* courseNode = courses.find(s[2], ACTIVE);
			if (courseNode == nullptr) {
				cout << "\n\nThis course does not exist" << endl;
				return false;
			}
			if (!stuList.load(semNode->semesterID, classNode->classID, courseNode->courseID)) EXITCODE_V(6, false);
			CourseStudentNode* stuNode = stuList.find(s[n - 1], ACTIVE);
			if (stuNode == nullptr) {
				cout << "\n\nThis student does not exist" << endl;
				return false;
			}


		}
	}*/
	return true;
}
bool checklecturer_7(string* s, int n) {
	ClassList classes;
	SemesterList semesters;
	CourseList courses;
	if (!semesters.load() || !classes.load()) {
		EXITCODE_V(6, false);
	}
	for (SemesterNode* semNode = semesters.Head; semNode; semNode = semNode->Next) {
		for (ClassNode* classNode = classes.Head; classNode; classNode = classNode->Next) {
			courses.load(semNode->semesterID, classNode->classID);
			if (courses.find(s[n - 1], ALL)) return true;
		}
	}
	cout << "\n\nThis course does not exist." << endl;
	return false;
}

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
	//inputData : semesterID
	// checklecturer(string *s, 1);
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
void loadCSVScoreBoard(CourseStudentList& llist, string filePath) {
	ifstream fin;
	string temp;
	fin.open(filePath);
	if (!fin.is_open()) {
		cout << "\n\nCannot open this file " << endl;
		EXITCODE(6);
	}
	//CourseStudentList stuList;
	int choice;
	getline(fin, temp);
	CourseStudentNode* node;
	while (!fin.good()) {
		node = new CourseStudentNode;
		getline(fin, node->studentID, ',');
		getline(fin,temp, ',');
		node->score.midterm = stod(temp);
		getline(fin, temp, ',');
		node->score.final = stod(temp);
		getline(fin, temp, ',');
		node->score.bonus = stod(temp);
		getline(fin, temp, ',');
		node->score.total = stod(temp);
		CourseStudentNode* stuNode = llist.find(node->studentID, ALL);

		if (stuNode) {
			if (stuNode->score.midterm == -1 && stuNode->score.final == -1 && stuNode->score.bonus == -1 && stuNode->score.total == -1) {
				if (stuNode->active == 1) {
					stuNode->active = 1;
					stuNode->score.midterm = node->score.midterm;
					stuNode->score.final = node->score.final;
					stuNode->score.bonus = node->score.bonus;
					stuNode->score.total = node->score.total;
				}
				else {
					cout << "\n\nThis student has dropped out"; // inactive.
				}
			}
			else {
				if (choice == REPLACE_ALL) {
					if (stuNode->active == 1) {
						stuNode->active = 1;
						stuNode->score.midterm = node->score.midterm;
						stuNode->score.final = node->score.final;
						stuNode->score.bonus = node->score.bonus;
						stuNode->score.total = node->score.total;
					}
					else {
						cout << "\n\nThis student has dropped out" << endl; // inactive.
					}
				}
				else if (choice == REPLACE) {
					if (stuNode->active == 1) {
						stuNode->active = 1;
						stuNode->score.midterm = node->score.midterm;
						stuNode->score.final = node->score.final;
						stuNode->score.bonus = node->score.bonus;
						stuNode->score.total = node->score.total;
					}
					else {
						cout << "\n\nThis student has dropped out" << endl; // inactive.
					}
				}
				else if (choice == SKIP_ALL) {
					delete node;
					continue;
				}
				else if (choice == SKIP) {
					delete node;
					continue;
				}
				else {
		
					
					char keyPress;

					cout << "\n\nThe student with ID '" << node->studentID << "' has already added.\n";
					cout << "[1 + enter] Skip.\n";
					cout << "[2 + enter] Replace.\n";
					cout << "[3 + enter] Skip all.\n";
					cout << "[4 + enter] Replace all.\n";

					while (choice == 0) {
						fflush(stdin);
						keyPress = cin.get();
						fflush(stdin);

						switch (keyPress) {
						case '1':
							choice = SKIP;
							break;
						case '2':
							choice = REPLACE;
							break;
						case '3':
							choice = SKIP_ALL;
							break;
						case '4':
							choice = REPLACE_ALL;
							break;
						default:
							choice = 0;
						}
					}

				}
			}
		}
		else {
			cout << "\n\n" << node->studentID << " does not exist." << endl;
			
		}
		delete node;



	}
}


	


//---------------------------------------------------------------------------------------------------
void lecturer_2_() {
//	input semester, class, course
//  string *s = new string[3]{"", "", ""};
//  fptr *p = new fptr[3]{inputSemester, inputClass, inputCourse};
//  inputdata(s, p, 0, 3, checkstaff_1_1);

//	StudentList stuList;
//	if (!stuList.load()) EXITCODE(6);
//	
//  string semesterID = s[0], courseID = s[2], classID = s[1];
//	if (!isPermissible(courseID)) {
//		cout << "\n\nYou are not allowed to access this course" << endl;
//		return;
//	}
//	SemesterList sems; ClassList classes; CourseList courses;
//	if (!sems.load()|| !classes.load()) EXITCODE(6);

//	if (sems.find(semesterID, ACTIVE)==nullptr || classes.find(classID, ACTIVE)==nullptr) EXITCODE(6);

//	if (!courses.load(semesterID, classID)) EXITCODE(6);
//	CourseNode* node = courses.find(courseID, ACTIVE);
//	if (node == nullptr) EXITCODE(6);
//	int index=1;
//	CourseStudentList llist;
//	if (!llist.load(semesterID, classID, courseID)) EXITCODE(6);

//	for(CourseStudentNode* node= llist.Head; node; node = node->next){
//		StudentNode* stuNode = stuList.find(node->studentID, ACTIVE);
//		printStudent(stuNode, index);
//	}
//	delete [] s;
//	delete[] p;
	
}

//------------------------------------------------------------------------------------------------------------
void lecturer_3_() {
//	input semester, class, course
//  string *s = new string[3]{"", "", ""};
//  fptr *p = new fptr[3]{inputSemester, inputClass, inputCourse};
//  inputdata(s, p, 0, 3, checkstaff_1_1);

//	StudentList stuList;
//	if (!stuList.load()) EXITCODE(6);
//	
//  string semesterID = s[0], courseID = s[2], classID = s[1];
//	if (!isPermissible(courseID)) {
//		cout << "\n\nYou are not allowed to access this course" << endl;
//		return;
//  }
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

	delete[]s;
	delete[]p;
*/


}

//-------------------------------------------------------------------------------------------------------------------------

void lecturer_4_() {
/*	input semester, class, course
	string *s = new string[4]{"", "", "",""};
	fptr *p = new fptr[4]{inputSemester, inputClass, inputCourse, inputStudent};
	inputdata(s, p, 0, 4, checkstaff_1_1);

	StudentList stuList;
	if (!stuList.load()) EXITCODE(6);
		
	string semesterID = s[0], courseID = s[1], classID = s[2], studentID = s[3];
	SemesterList sems; ClassList classes; CourseList courses;
	if (!sems.load()|| !classes.load()) EXITCODE(6);
	if (stuList.find(studentID, ACTIVE)== nullptr) EXITCODE(6);
	
	// An's part 

	if (sems.find(semesterID, ACTIVE)==nullptr || classes.find(classID, ACTIVE)==nullptr) EXITCODE(6);

	if (!courses.load(semesterID, classID)) EXITCODE(6);
	CourseNode* node = courses.find(courseID, ACTIVE);
	if (node == nullptr) EXITCODE(6);
	int index=1;
	CourseStudentList llist;
	if (!llist.load(semesterID, classID, courseID) EXITCODE(6);
	bool* attendance = // An'parts.
*/
/*
	CourseStudentNode* node = llist.find(studentID, ALL);
	for (int i=0; i < 10; i++){
		node->attendance[i] = attendance[i];
	}
	llist.save(semeseterID, classID, courseID);

	delete[]s;
	detete[]p;
*/	

	
}


void lecturer_5_() {
/*
	input semester, class, course
	string *s = new string[4]{"", "", "","",""};
	fptr *p = new fptr[4]{inputSemester, inputClass, inputCourse, filePath};
	inputdata(s, p, 0, 4, checkstaff_1_1);

	StudentList stuList;
	if (!stuList.load()) EXITCODE(6);
		
	string semesterID = s[0], courseID = s[2], classID = s[1], filePath = s[3];
	
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

	if (loadCSVScoreBoard(llist,filePath)) return ;
	llist.save();

	delete []s;
	delete[]p;
	
*/

}


void lecturer_6_() {
/*
	input semester, class, course
	string *s = new string[4]{"", "", "",""};
	fptr *p = new fptr[4]{inputSemester, inputClass, inputCourse, inputStudent};
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

	Score newScore = An's part
*/
/*
	CourseStudentNode* node = llist.find(studentID, ALL);
	node->score = newScore;
	
*/
	//delete[] s;
	// delete[]p;
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
	printScoreboard(stuList, llist);
	
*/
	//delete[] s;
	//delete[] p;
}

