#include "AcademicStaffScoreBoard.h"

void import_from_csv(boardnode*& head, ifstream& fin, studentnode* root, ofstream &fout, string& coursename) {
	string filename;
	cout << "enter the file's name ";
	getline(cin, filename);
	fin.open(filename);
	if (!fin.is_open()) {
		cout << "cannot open this file " << endl;
		return;
	}
	
	boardnode* cur = head;
	while (fin.good()) {
		boardnode* node = new boardnode;
		getline(fin, node->no, ',');
		getline(fin, node->student_id,',');
		getline(fin, node->fullname, ',');
		getline(fin, node->class_, ',');
		for (int i = 0; i < 4; i++) {
			if (i == 3) {
				getline(fin, node->grade[i]);
			}
			else {
				getline(fin, node->grade[i], ',');
			}
		}
		if (head == nullptr) {
			head = node;
			cur = node;
		}
		else {
			cur->next = node;
			cur = node;
		}
		
	}
	update_grade(head, root);
	output_to_txt(root, fout, coursename);
	fin.close();
}
void view_scoreboard(boardnode* head) {
	while (head) {
		cout << head->no << '\t' << head->student_id << '\t' << head->fullname << '\t' << head->class_
			<< '\t';
		for (int i = 0; i < 4;i++) {
			cout << head->grade[i];
			if (i == 3) cout << endl;
			else cout << '\t';
		}
		head = head->next;
	}
}
void delete_all(boardnode*& head) {
	while (head) {
		boardnode* tmp = head->next;
		delete head;
		head = tmp;
	}

}
void update_grade(boardnode* head, studentnode* root) {
	head = head->next;
	while (head && root) {
		for (int i = 0; i < 4; i++) {
			root->grade[i] = head->grade[i];
		}
		root = root->next;
		head = head->next;
	}
}
/*void edit_grade(studentnode* root) {
	if (root == nullptr) {
		cout << "empty course " << endl;
		return;
	}
	cout << "enter the student's id ";
	string s;
	getline(cin, s);
	while (root) {
		if (root->id == s) {
			break;
		}
		root = root->next;
	}
	int type;
	cout << "enter the kind of grade ( 0 : midterm, 1: final, 2: bonus, 3: total ) ";
	cin >> type;
	cout << "enter new grade ";
	fflush(stdin);
	getline(cin, s);
	if (root == nullptr) return;
	root->grade[type] = s;
}*/

//kiet's part



//void outputscoreboard()
//{
//	studentnode* root = nullptr;
//
//	ifstream fin;
//
//	input_list_student(root, fin, courseid);
//
//	studentnode* phead=root;
//    string id;
//    cout << "enter the id of the student you want to view scoreboard";
//    getline(cin, id);
//    while (phead != nullptr)
//    {
//        if (phead->id == id)
//        {
//            cout << phead->no << '\t' << phead->student_id << '\t' << phead->fullname << '\t' << phead->class_
//                << '\t';
//            for (int i = 0; i < 4; i++) {
//                cout << phead->grade[i];
//                if (i == 3) cout << endl;
//                else cout << '\t';
//            }
//        }
//        else
//            cout << endl;
//    }
//}



/*void exportscoreboard(boardnode* phead, ofstream& f)
{
    f << "no,student id,fullname,class,midterm,final,bonus,total";
    while (phead != nullptr)
    {
        f << phead->no << "," << phead->student_id << "," << phead->fullname << "," << phead->class_ << "," << phead->grade[0] << "," << phead->grade[1] << "," << phead->grade[2] << "," << phead->grade[3]<<endl;
        phead = phead->next;
    }
}

// khang's part:
void import_scoreboard(string courseid) {
	boardnode* head = nullptr;
	ifstream fin;
	ofstream fout;
	studentnode* root=nullptr;
	
	input_list_student(root, fin, courseid);
	import_from_csv(head, fin, root, fout, courseid);
	delete_all(head);
	delete_all(root);
	
}

void view_scoreboard(string courseid) {
	studentnode* root = nullptr;
	
	ifstream fin;
	
	input_list_student(root, fin, courseid);
	studentnode* head = root;
	int i = 1;
	cout << "no" << '\t' << "id " << "\t\t" << "fullname" << "\t" << "class" << "\t" << "midterm" << "\t" << "final" << "\t" << "bonus" << "\t" << "total" << endl;
	while (head) {
		cout << i << "\t" << head->id << "\t" << head->name << "\t" << head->class_<<"\t"
			;
		for (int i = 0; i < 4; i++) {
			cout << head->grade[i] <<"\t";
		}
		cout << endl;
		head = head->next;
		i++;
	}
	delete_all(root);
}


void edit_grade(string courseid) {
	studentnode* root = nullptr;

	ifstream fin;
	input_list_student(root, fin, courseid);
	studentnode* head = root;
	string id, name;
	cout << "enter student's id ";
	getline(cin, id);
	cout << "enter student's name ";
	getline(cin, name);
	while (head) {
		if (head->id == id) {
			break;
		}
		head = head->next;
	}
	if (head == nullptr) {
		cout << "wrong id" << endl;
		return;
	}
	int type;
	string new_grade;
	cout << "enter the kind of grade ( 0 : midterm, 1: final, 2: bonus, 3: total ) ";
	cin >> type;
	cin.ignore();
	cout << "enter new grade ";
	
	getline(cin, new_grade);
	
	head->grade[type] = new_grade;
	ofstream fout;
	output_to_txt(root, fout, courseid);
	delete_all(root);

}

void lecturer_options() {
	cout << "1. view list of courses in the current semester " << endl;
	cout << "2. view list of students of a course " << endl;
	cout << "3. view attendance list of a course" << endl;
	cout << "4. edit an attendance " << endl;
	int choice;
	cin >> choice;
	cin.ignore();
	if (choice == 1) {
		view_list_courses();
	}
	else {
		coursenode* course = nullptr;
		ifstream fin;
		input_list_courses(course, fin);
		string courseid;
		cout << "enter the course's id ";
		getline(cin, courseid);

		if (!valid_course(course, courseid)) {
			cout << "you don't have permission to access this course " << endl;
			return;
		}
		
		if (choice == 2) view_list_student(courseid);
		else if (choice == 3) view_attendance_list(courseid);
		else if (choice == 4) edit_attendance(courseid);
		delete_all(course);
	}
	return;
}
void scoreboard_options() {
	cout << "1. search and view scoreborad " << endl;
	cout << "2. export scoreboard to csv " << endl;
	cout << "3. import scoreboard from csv file " << endl;
	cout << "4. edit grade of a student " << endl;
	cout << "5. view scoreboard of a course" << endl;
	int choice;
	cin >> choice;
	cin.ignore();
	if (choice == 1) {
		return;
	}
	else if (choice == 2) {
		return;
	}
	else if (choice == 3 || choice==4|| choice ==5) {
		coursenode* course = nullptr;
		ifstream fin;
		input_list_courses(course, fin);
		string courseid;
		cout << "enter the course's id ";
		getline(cin, courseid);
		if (!valid_course(course, courseid)) {
			cout << "you don't have permission to access this course " << endl;
			return;
		}
		if (choice == 3) {
			import_scoreboard(courseid);
		}
		else if (choice == 4) {
			edit_grade(courseid);
		}
		else if (choice == 5) {
			view_scoreboard(courseid);
		}
		else {
			cout << "invalid" << endl;
			return;
		}
	}
}*/
void staff_3_1();

void staff_3_2();

void staff_3_3();

void staff_3_4();

void staff_3_5();

void staff_3_6();

void staff_3_7();

void staff_3_8();

void staff_3_9();

void staff_3_10();

void staff_3_11();

void staff_3_12();

bool checkStaff_3_1();

bool checkStaff_3_2();

bool checkStaff_3_3();

bool checkStaff_3_4();

bool checkStaff_3_5();

bool checkStaff_3_6();

bool checkStaff_3_7();

bool checkStaff_3_8();

bool checkStaff_3_9();

bool checkStaff_3_10();

bool checkStaff_3_11();

bool checkStaff_3_12();