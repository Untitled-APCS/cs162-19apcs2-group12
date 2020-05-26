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

void input_list_student(StudentNode*& head, ifstream& fin, string& coursename) {
	string s="";
	cout << "Enter name of the course ";
	getline(cin, coursename);
	 s = coursename + "-Student.txt";
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
void view_list_student() {
	StudentNode* root = nullptr;
	ifstream fin;
	string coursename;
	input_list_student(root, fin, coursename);
	StudentNode* head = root;
	cout << "ID\t\t" << "Fullname\t" << "Date of birth\t" << "Class" << endl;
	while (head) {
		cout << head->id << '\t' << head->name << '\t' << head->doB << "\t"
			<< head->class_ << endl;
		head = head->next;
	}
	delete_all(root);
	
}
void delete_all(StudentNode*& head) {
	while (head) {
		StudentNode* tmp = head->next;
		delete head;
		head = tmp;
	}
}
void view_attendance_list() {
	StudentNode* root = nullptr;
	ifstream fin;
	string coursename;
	input_list_student(root, fin, coursename);
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
	delete_all(root);
}
void edit_attendance() {
	StudentNode* root = nullptr;
	ifstream fin;
	string coursename;
	input_list_student(root, fin, coursename);
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
	filename = filename + "-Student.txt";
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
void export_to_csv() {
	StudentNode* root = nullptr;
	ifstream fin;

	string coursename;
	input_list_student(root, fin, coursename);
	ofstream fout;
	coursename = coursename + "-attendance.csv";
	fout.open(coursename);
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

