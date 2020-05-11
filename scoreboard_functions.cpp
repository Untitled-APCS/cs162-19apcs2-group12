#include "scoreboard.h"

void import_from_csv(BoardNode*& head, ifstream& fin, StudentNode* root, ofstream &fout) {
	string filename;
	cout << "Enter the file's name ";
	getline(cin, filename);
	fin.open(filename);
	if (!fin.is_open()) {
		cout << "Cannot open this file ";
		return;
	}
	
	BoardNode* cur = head;
	while (fin.good()) {
		BoardNode* node = new BoardNode;
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
	output_to_txt(root, fout);
	fin.close();
}
void view_scoreboard(BoardNode* head) {
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
void delete_all(BoardNode*& head) {
	while (head) {
		BoardNode* tmp = head->next;
		delete head;
		head = tmp;
	}

}
void update_grade(BoardNode* head, StudentNode* root) {
	head = head->next;
	while (head && root) {
		for (int i = 0; i < 4; i++) {
			root->grade[i] = head->grade[i];
		}
		root = root->next;
		head = head->next;
	}
}
void edit_grade(StudentNode* root) {
	if (root == nullptr) {
		cout << "Empty course " << endl;
		return;
	}
	cout << "Enter the student's id ";
	string s;
	getline(cin, s);
	while (root) {
		if (root->id == s) {
			break;
		}
		root = root->next;
	}
	int type;
	cout << "Enter the kind of grade ( 0 : Midterm, 1: final, 2: bonus, 3: total ) ";
	cin >> type;
	cout << "Enter new grade ";
	fflush(stdin);
	getline(cin, s);
	if (root == nullptr) return;
	root->grade[type] = s;
}