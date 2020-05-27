#include "Lecturer.h"

void input_list_courses(CourseNode*& head, ifstream& fin) {
	string s;
	
	
	fin.open("available_courses.txt");
	if (!fin.is_open()) {
		cout << "Cannot open this file " << endl;
		return;
	}
	int amount = 0;
	fin >> amount;
	CourseNode* cur = head;
	getline(fin, s);
	while (amount) {
		CourseNode* node = new CourseNode;
		getline(fin, node->id);
		getline(fin, node->name);
		getline(fin, node->lecturer_username);
		getline(fin, node->lecturer_name);
		getline(fin, node->degree);
		getline(fin, node->gender);
		getline(fin, node->starting_date);
		getline(fin, node->ending_date);
		getline(fin, node->day_of_week);
		getline(fin, node->starting_hour);
		getline(fin, node->ending_hour);
		getline(fin, node->room);
		getline(fin, s);
		getline(fin, s);
		if (head == nullptr) {
			cur = node;
			head = node;
		}
		else {
			cur->next = node;
			cur = node;
		}
		amount--;
	}
	fin.close();
}
void view_list_courses() {
	CourseNode* head = nullptr;
	ifstream fin;
	input_list_courses(head, fin);
	CourseNode* cur = head;
	while (cur) {
		cout << cur->id << endl;
		cout << cur->name << endl;
		cout << cur->lecturer_username << endl;
		cout << cur->lecturer_name << endl;
		cout << cur->degree << endl;
		cout << cur->gender << endl;
		cout << cur->starting_date << endl;
		cout << cur->ending_date << endl;
		cout << cur->day_of_week << endl;
		cout << cur->starting_hour << endl;
		cout << cur->ending_hour << endl;
		cout << cur->room << endl;
		cout << endl << endl;
		cur = cur->next;
	}
	delete_all(head);
}
void delete_all(CourseNode*& head) {
	while (head) {
		CourseNode* tmp = head->next;
		delete head;
		head = tmp;
	}
}

void input_list_student(StudentNode*& head, ifstream& fin, string& courseid) {
	string s = "";
	
	 s = courseid + "-Student.txt";
	fin.open(s);
	if (!fin.is_open()) {
		cout << "Cannot open this file ";
		return;
	}
	int n = 0;
	fin >> n;
	getline(fin, s);
	
	StudentNode* cur = head;
	
	while (n) {
		StudentNode* node = new StudentNode;
		getline(fin, node->id, '\n');
		getline(fin, node->password, '\n');
		getline(fin, node->name);
		getline(fin, node->doB);
		getline(fin, node->class_);
		getline(fin, node->status);
		for (int j = 0; j < 4; j++) {
			getline(fin, node->grade[j]);
		}
		for (int j = 0; j < 10; j++) {
			getline(fin, node->al[j]);
		}
		getline(fin, s);
		
		if (head == nullptr) {
			head = node;
			cur = node;
		}
		else {
			cur->next = node;
			cur = node;
		}
		n--;
	}

	fin.close();
}
//View list students of a course.
void view_list_student(string courseid) {
	/*StudentNode* root = nullptr;
	ifstream fin;
	
	string courseid;
	cout << "Enter the course's id ";
	getline(cin, courseid);
	
	CourseNode* course = nullptr;
	input_list_courses(course, fin);
	
	if (!valid_course(course, courseid)) {
		cout << "You don't have permission to access this course." << endl;
		return;
	}
	
	input_list_student(root, fin, courseid);*/
	// Test:
	StudentNode* root=nullptr;
	ifstream fin;
	input_list_student(root, fin, courseid);
	StudentNode* head = root;
	int i = 1;
	cout << "No\t" << "ID\t\t" << "Fullname\t" << "Date of birth\t" << "Class" << endl;
	while (head) {
		cout << i <<'\t'<< head->id << '\t' << head->name << '\t' << head->doB << "\t"
			<< head->class_ << endl;
		head = head->next;
		i++;
	}
	delete_all(root);
	//delete_all(course);
	
}
void delete_all(StudentNode*& head) {
	while (head) {
		StudentNode* tmp = head->next;
		delete head;
		head = tmp;
	}
}
// View attendance list of a course.
void view_attendance_list(string courseid) {
	StudentNode* root = nullptr;
	ifstream fin;

	input_list_student(root, fin, courseid);
	StudentNode* head = root;
	cout << "Students name\t";
	for (int i = 0; i < 10; i++) {
		cout << "W0" << i + 1 << '\t';
	}
	cout << endl;
	while (head) {
		cout << head->name << "\t";
		for (int j = 0; j < 10; j++) {
			int index = head->al[j].length() - 1;
			cout << head->al[j][index - 1] << head->al[j][index] << "\t";
		}
		cout << endl;
		head = head->next;
	}
	// Delete
	delete_all(root);
	
}

// Edit an attendance of a student in a course.
void edit_attendance(string courseid) {
	StudentNode* root = nullptr;
	ifstream fin;
	


	input_list_student(root, fin, courseid);
	StudentNode* head = root;
	
	if (head == nullptr) return;
	
	int week;
	string id;
	string name;
	int status;
	
	
	cout << "Enter the student's id ";
	getline(cin, id);
	cout << "Enter the student's name ";
	getline(cin, name);
	StudentNode* cur = head;
	while (cur) {
		if (cur->id == id) break;
		else cur  = cur->next;
	}
	if (cur == nullptr) {
		cout << "Wrong id" << endl;
		return;
	}
	
	cout << "Enter the week from (1-10) ";
	cin >> week;

	cout << "Enter the status: (1 for presence and -1 for absence) ";
	cin >> status;
	


	int pos = cur->al[0].length() - 1;
	if (status == 1) {
		cur->al[week - 1][pos - 1] = ' ';
		cur->al[week - 1][pos] = '1';
	}
	else {
		cur->al[week - 1][pos - 1] = '-';
		cur->al[week - 1][pos] = '1';
	}

	
	delete_all(root);
}
void output_to_txt(StudentNode* head, ofstream& fout, string& coursename) {
	string filename;
	/*cout << "Enter the course's name ";
	
	getline(cin, filename);*/
	filename = coursename + "-Student.txt";
	fout.open(filename);
	if (!fout.is_open()) {
		cout << "Cannot open this file" << endl;
		return;
	}
	int amount = size(head);
	fout << amount << endl;
	while (head) {
		fout << head->id << endl;
		fout << head->password << endl;
		fout << head->name << endl;
		fout << head->doB << endl;
		fout << head->class_ << endl;
		fout << head->status << endl;
		for (int j = 0; j < 4; j++) {
			fout << head->grade[j] << endl;
		}
		for (int j = 0; j < 10; j++) {
			fout << head->al[j] << endl;
		}
		fout << endl;
		head = head->next;
		
	}
	fout.close();
}
// Export attendance list to file csv.
void export_to_csv(string courseid) {
	StudentNode* root = nullptr;
	ifstream fin;
	
	input_list_student(root, fin, courseid);
	
	ofstream fout;
	courseid = courseid + "-attendance.csv";
	fout.open(courseid);
	if (!fout.is_open()) {
		cout << "Cannot open this file" << endl;
		return;
	}
	StudentNode* head = root;
	fout << "No, Student name, Student Id,";
	for(int i=1; i<=10; i++) {
		if (i == 10) {
			fout << "W" << i << "\n";
		}
		else {
			fout << "W0" << i << ",";
		}
	}
	int i = 1;
	while (head) {
		fout << i <<","<< head->name << "," << head->id << ",";
		for (int j = 0; j < 10; j++) {
			int index = head->al[j].length() - 1;
			if (j == 9) {
				fout << head->al[j][index - 1] << head->al[j][index] << "\n";
			}
			else {
				fout << head->al[j][index - 1] <<head->al[j][index] << ",";
			}
		}
		head = head->next;
		i++;

	}
	delete_all(root);

	fout.close();
}
int size(StudentNode* head) {
	int sum = 0;
	while (head) {
		sum++;
		head = head->next;
	}
	return sum;
}

bool valid_course(CourseNode* course, string courseid) {
	string username;
	cout << "Enter your user name ";
	getline(cin, username);
	normalize(username);
	normalize_course(course);
	while (course) {
		if (course->lecturer_username == username && course->id == courseid) return true;
		course = course->next;
	}
	return false;
}
void normalize_course(CourseNode* course) {
	while (course) {
		normalize(course->name);
		normalize(course->lecturer_username);
		course = course->next;
	}
}

string get_courseid(CourseNode* course, string coursename) {
	while (course) {
		if (course->name == coursename) {
			return course->id;
		}
		course = course->next;
	}
	return "";
}
/*void lecturer_options() {
	CourseNode* course=nullptr;
	ifstream fin;
	input_list_courses(course, fin);
	string courseid;
	cout << "Enter the course's id ";
	getline(cin, courseid);	
	
	if (!valid_course(course, courseid)) {
		cout << "You don't have permission to access this course " << endl;
		return;
	}
	view_list_student(courseid);
	delete_all(course);
	return ;
}*/