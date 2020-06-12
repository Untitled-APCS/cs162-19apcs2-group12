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
	/*if (s[0] != llist.currentSemester) {
		cout << "\nThis is not current semester " << endl;
		fflush(stdin);
		char keyPress = cin.get();
		fflush(stdin);
		return false;
	}*/
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
	fflush(stdin);
	char keyPress = cin.get();
	fflush(stdin);
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
	
	if (!courses.load(s[0],s[1])) {
		EXITCODE_V(6, false);
	}
	CourseNode* courseNode = courses.find(s[2], ACTIVE);
	if (courseNode->lecturerID != user::ID) {
		cout << "\n\nYou are not allowed to access this course";
		fflush(stdin);
		char keyPress = cin.get();
		fflush(stdin);
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
	
	if (!courses.load(s[0], s[1])) {
		EXITCODE_V(6, false);
	}
	CourseNode* courseNode = courses.find(s[2], ACTIVE);
	if (courseNode->lecturerID != user::ID) {
		cout << "\n\nYou are not allowed to access this course";
		fflush(stdin);
		char keyPress = cin.get();
		fflush(stdin);
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
	
	if (!courses.load(s[0], s[1])) {
		EXITCODE_V(6, false);
	}
	CourseNode* courseNode = courses.find(s[2], ACTIVE);
	if (courseNode->lecturerID != user::ID) {
		cout << "\n\nYou are not allowed to access this course";
		fflush(stdin);
		char keyPress = cin.get();
		fflush(stdin);
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
bool checklecturer_7(string* s, int n) {
	ClassList classes;
	SemesterList semesters;
	CourseList courses;
	if (!semesters.load() || !classes.load()) {
		EXITCODE_V(6, false);
	}
	if (!courses.load(s[0], s[1])) EXITCODE_V(6,false);
	if (courses.find(s[n - 1], ALL)) return true;
	/*for (SemesterNode* semNode = semesters.Head; semNode; semNode = semNode->Next) {
		for (ClassNode* classNode = classes.Head; classNode; classNode = classNode->Next) {
			courses.load(semNode->semesterID, classNode->classID);
			if (courses.find(s[n - 1], ALL)) return true;
		}
	}*/
	cout << "\n\nThis course does not exist." << endl;
	return false;
}

bool isPermissible(string courseID) {
	return courseID == user::ID;
}

void printCourse(CourseNode* node, int& index) {
	
	cout << index << "\t" << node->courseName << "\t" << node->courseID << "\t"
		<< node->startingDate.y << "/" << node->startingDate.m << "/" << node->startingDate.d << "\t"
		<< node->startingTime.h << ":" << node->startingTime.m << ":" << node->startingTime.s<<"0" << "\t"
		<< node->endingTime.h << ":" << node->endingTime.m << ":" << node->endingTime.s<<"0" << "\t"
		<< node->room << endl;
		node = node->Next;
		index++;

  	
}

void printScoreboard(StudentList llist1, CourseStudentList llist2) {
	cout << "\n\nNo\t" << "Student Name\t" << "Student ID\t" << "Midterm\t" << "Final\t" << "Bonus\t" << "Total" << endl;
	int index = 1;
	for (CourseStudentNode* node = llist2.Head; node; node = node->Next) {
		StudentNode* tmp = llist1.find(node->studentID, ACTIVE);
		if (tmp) {
			cout << index << "\t" << tmp->studentName << "\t" << tmp->studentID << "\t" << node->score.midterm
				<< "\t" << node->score.final << "\t" << node->score.bonus << "\t" << node->score.total << endl;
			index++;
		}
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
	string* s = new string[1]{ "" };
	fPtr* p = new fPtr[1]{ inputSemester };
	// checklecturer(string *s, 1);
	inputData(s, p, 1, 0, checklecturer_1);
	string semesterID = s[0];
	CourseList allCourses;
	SemesterList Sems;
	ClassList classes;
	
	
	if (!Sems.load()) 
		EXITCODE(6);
	
	// Find current Semester:
	//SemesterNode* node = Sems.Head;
	//while (node && node->current != CURRENT) node = node->Next;
	
	if (!classes.load()) EXITCODE(6);

	// Find all active classes:
	ClassNode* classNode = classes.Head;
	CourseList courseList;
	int index = 1;
	while (classNode) {
		if (classNode->active) {
			if (!courseList.load(semesterID, classNode->classID)) EXITCODE(6);
			for (CourseNode* coursenode = courseList.Head; coursenode; coursenode = coursenode->Next) {
				if (coursenode->lecturerID == user::ID && courseList.find(coursenode->courseID, ACTIVE)) {
					cout << "No: " << index << endl;
					cout << "Course Name " << coursenode->courseName << endl;
					cout << "Course ID " << coursenode->courseID << endl;
					cout << "Starting Date " << coursenode->startingDate.y << "/" << coursenode->startingDate.m << "/"
						<< coursenode->startingDate.d << endl;
					cout << "Starting Time " << coursenode->startingTime.h << ":" << coursenode->startingTime.m << ":"
						<< coursenode->startingTime.s << endl;
					cout << "Ending Time " << coursenode->endingTime.h << ":" << coursenode->endingTime.m << ":"
						<< coursenode->endingTime.s << endl;
					cout << "Room " << coursenode->room << endl;
					index++;
				}
			}
			courseList.destroy();
		}

		classNode = classNode->Next;
	}
	lecturerMenu();
	delete[]s;
	delete[]p;

	
}
bool loadCSVScoreBoard(CourseStudentList& llist, string filePath) {
	ifstream fin;
	string temp;
	fin.open(filePath);
	if (!fin.is_open()) {
		cout << "\n\nCannot open this file " << endl;
		EXITCODE_V(6, false);
	}
	bool choice = 0;
	getline(fin, temp);
	cout << temp << endl;
	CourseStudentNode* node;
	while (fin.good()) {
		node = new CourseStudentNode;
		getline(fin, temp, ',');
		if (temp == "") {
			delete node;
			continue;
		}
		cout << temp << " ";
		getline(fin, temp, ',');
		cout << temp << " ";
		node->studentID = temp;
		getline(fin, temp, ',');
		cout << temp << " ";
		node->score.midterm = stod(temp);
		getline(fin, temp, ',');
		cout << temp << " ";
		node->score.final = stod(temp);
		getline(fin, temp, ',');
		cout << temp << " ";
		node->score.bonus = stod(temp);
		getline(fin, temp, '\n');
		cout << temp << endl;
		node->score.total = stod(temp);


		CourseStudentNode* stuNode = llist.find(node->studentID, ACTIVE);
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
			cout << "\n\n" << node->studentID << " does not exist" << endl;
		}
		delete node;
	}
	

	fin.close();
	return true;
}



	


//---------------------------------------------------------------------------------------------------
void lecturer_2_() {
	
	string *s = new string[3]{"", "", ""};
	fPtr *p = new fPtr[3]{inputSemester, inputClass, inputCourse};
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	inputData(s, p, 3, 0, checklecturer_2);
	string semesterID = s[0], classID=s[1], courseID=s[2];
	StudentList stuList;
	if (!stuList.load()) EXITCODE(6);
	
  
	/*if (!isPermissible(courseID)) {
		cout << "\n\nYou are not allowed to access this course" << endl;
		fflush(stdin);
		char keyPress = cin.get();
		fflush(stdin);
		lecturerMenu();
		return;
	}*/
	SemesterList sems; ClassList classes; CourseList courses;
	if (!sems.load()|| !classes.load()) EXITCODE(6);

	if (sems.find(semesterID, ACTIVE)==nullptr || classes.find(classID, ACTIVE)==nullptr) EXITCODE(6);

	if (!courses.load(semesterID, classID)) EXITCODE(6);
	CourseNode* node = courses.find(courseID, ACTIVE);
	if (node == nullptr) EXITCODE(6);
	int index=1;
	CourseStudentList llist;
	if (!llist.load(semesterID, classID, courseID)) EXITCODE(6);

	
	
	

	for(CourseStudentNode* node= llist.Head; node; node = node->Next){
		StudentNode* stuNode = stuList.find(node->studentID, ACTIVE);
		if (stuNode){
			cout << index<<"\t" << stuNode->studentName << "\t" << stuNode->studentID << endl;
			index++;
		}
	}
	
	cout << "Success";
	/*fflush(stdin);
	char keyPress = cin.get();
	fflush(stdin);*/
	
	lecturerMenu();
	delete [] s;
	delete[] p;
	
}

//------------------------------------------------------------------------------------------------------------
void lecturer_3_() {

	string *s = new string[3]{"", "", ""};
	fPtr *p = new fPtr[3]{inputSemester, inputClass, inputCourse};
	inputData(s, p, 3, 0, checklecturer_3);

	StudentList stuList;
	if (!stuList.load()) EXITCODE(6);
	string semesterID = s[0], classID = s[1], courseID = s[2];
  
	SemesterList sems; ClassList classes; CourseList courses;
	if (!sems.load()|| !classes.load()) EXITCODE(6);

	if (sems.find(semesterID, ACTIVE)==nullptr || classes.find(classID, ACTIVE)==nullptr) EXITCODE(6);
	
	if (!courses.load(semesterID, classID)) EXITCODE(6);
	CourseNode* node = courses.find(courseID, ACTIVE);
	if (node == nullptr) EXITCODE(6);
	int index=1;
	CourseStudentList llist;
	if (!llist.load(semesterID, classID, courseID)) EXITCODE(6);



	CourseStudentNode* stuNode = llist.Head;
	cout << "\n\n" << "No\t" <<"Student Name\t" << "Student ID\t" << "W01   " << "W02   " << "W03   " << "W04   " 
		 << "W05   " << "W06   "<< "W07   " << "W08   " << "W09   " << "W10" << endl;
	
	while (stuNode) {
		StudentNode* node = stuList.find(stuNode->studentID, ACTIVE);
		if (node) {
			cout << index << "\t" << node->studentName <<  "\t" << node->studentID << "\t";
			for (int i = 0; i < 10; i++) {
				if (i == 9) cout << stuNode->attendance[i] << endl;
				else cout << stuNode->attendance[i] << "     ";
			}
			index++;
		}
		stuNode = stuNode->Next;
		
	}
	lecturerMenu();
	delete[]s;
	delete[]p;



}

//-------------------------------------------------------------------------------------------------------------------------

void lecturer_4_() {
	
	string *s = new string[4]{"", "", "",""};
	fPtr *p = new fPtr[4]{inputSemester, inputClass, inputCourse, inputStudent};
	
	inputData(s, p, 4, 0, checklecturer_4);

	StudentList stuList;
	if (!stuList.load()) EXITCODE(6);
	//string semesterID = "2020-2021hk1", classID = "18ctt1", courseID = "wr227", studentID ="19125133";
	string semesterID = s[0], courseID = s[1], classID = s[2], studentID = s[3];
	SemesterList sems; ClassList classes; CourseList courses;
	if (!sems.load()|| !classes.load()) EXITCODE(6);
	if (stuList.find(studentID, ACTIVE)== nullptr) EXITCODE(6);
	
	 //An's part 

	if (sems.find(semesterID, ACTIVE)==nullptr || classes.find(classID, ACTIVE)==nullptr) EXITCODE(6);

	if (!courses.load(semesterID, classID)) EXITCODE(6);
	CourseNode* courseNode = courses.find(courseID, ACTIVE);
	if (courseNode == nullptr) EXITCODE(6);
	int index=1;
	CourseStudentList llist;
	if (!llist.load(semesterID, classID, courseID)) EXITCODE(6);
	//bool* attendance = // An'parts.


	CourseStudentNode* node = llist.find(studentID, ALL);
	if (node == nullptr) {
		cout << "\n\nThis student does not exist " << endl;
		lecturerMenu();
		return;
	}
	
	cout << "Enter the new attendance list " << endl;
	for (int i = 0; i < 10; i++) {
		cin >> node->attendance[i];
	}
	/*for (int i=0; i < 10; i++){
		node->attendance[i] = attendance[i];
	}*/
	llist.save(semesterID, classID, courseID);
	lecturerMenu();
	
	delete[]s;
	delete[]p;
	

	
}


void lecturer_5_() {

	
	string *s = new string[4]{"", "", "",""};
	fPtr *p = new fPtr[4]{inputSemester, inputClass, inputCourse, inputPathScoreBoardListCSV};
	inputData(s, p, 4, 0, checklecturer_5);


	//string filePath = "D:/cs162-19apcs2-group12/wr272_scoreboard.csv";
	StudentList stuList;
	if (!stuList.load()) EXITCODE(6);
	//string semesterID = "2020-2021hk1", classID = "18ctt1", courseID = "wr227", filePath = "";
	
	string semesterID = s[0], courseID = s[2], classID = s[1], filePath = s[3];
	
	SemesterList sems; ClassList classes; CourseList courses;
	if (!sems.load()|| !classes.load()) EXITCODE(6);
	//if (stuList.find(studentID, ACTIVE)== nullptr) EXITCODE(6);

	if (sems.find(semesterID, ACTIVE)==nullptr || classes.find(classID, ACTIVE)==nullptr) EXITCODE(6);

	if (!courses.load(semesterID, classID)) EXITCODE(6);
	CourseNode* node = courses.find(courseID, ACTIVE);
	if (node == nullptr) EXITCODE(6);
	int index=1;
	CourseStudentList llist;
	if (!llist.load(semesterID, classID, courseID)) EXITCODE(6);

	if(loadCSVScoreBoard(llist, filePath)) cout <<"OK"<<endl;
	llist.save(semesterID, classID, courseID);

	lecturerMenu();
	delete []s;
	delete[]p;
	


}


void lecturer_6_() {

	
	string *s = new string[4]{"", "", "",""};
	fPtr *p = new fPtr[4]{inputSemester, inputClass, inputCourse, inputStudent};
	inputData(s, p, 4, 0, checklecturer_6);

	StudentList stuList;
	if (!stuList.load()) EXITCODE(6);
	string semesterID = "2020-2021hk1", classID = "18ctt1", courseID = "wr227", studentID = "19125133";
	//string semesterID = s[0], courseID = s[1], classID = s[2], studentID = s[3];
	SemesterList sems; ClassList classes; CourseList courses;
	if (!sems.load()|| !classes.load()) EXITCODE(6);
	if (stuList.find(studentID, ACTIVE)== nullptr) EXITCODE(6);

	if (sems.find(semesterID, ACTIVE)==nullptr || classes.find(classID, ACTIVE)==nullptr) EXITCODE(6);

	if (!courses.load(semesterID, classID)) EXITCODE(6);
	CourseNode* courseNode = courses.find(courseID, ACTIVE);
	if (courseNode == nullptr) EXITCODE(6);
	int index=1;
	CourseStudentList llist;
	if (!llist.load(semesterID, classID, courseID)) EXITCODE(6);

	//Score newScore = An's part


	CourseStudentNode* node = llist.find(studentID, ALL);
	if (node == nullptr) {
		cout << "\n\nThis student is not in this course" << endl;
		lecturerMenu();
		return;
	}
	// Test
	cout << "Enter new scores: ";
	cin >> node->score.midterm >> node->score.final >> node->score.bonus >> node->score.total;

	llist.save(semesterID, classID, courseID);

	lecturerMenu();
	

	delete[] s;
	delete[]p;
}


void lecturer_7_() {

	
	string *s = new string[3]{"", "", ""};
	fPtr *p = new fPtr[3]{inputSemester, inputClass, inputCourse};
	inputData(s, p, 3, 0, checklecturer_7);


	string semesterID = s[0], classID = s[1], courseID =s[2];
	
	SemesterList sems; ClassList classes; CourseList courses;
	if (!sems.load()|| !classes.load()) EXITCODE(6);
	

	if (sems.find(semesterID, ACTIVE)==nullptr || classes.find(classID, ACTIVE)==nullptr) EXITCODE(6);

	if (!courses.load(semesterID, classID)) EXITCODE(6);
	
	CourseNode* node = courses.find(courseID, ACTIVE);
	if (node == nullptr) EXITCODE(6);
	int index=1;
	CourseStudentList llist;
	if (!llist.load(semesterID, classID, courseID)) EXITCODE(6);


	StudentList stuList;
	if (!stuList.load()) EXITCODE(6);
	printScoreboard(stuList, llist);
	lecturerMenu();

	delete[] s;
	delete[] p;
}

