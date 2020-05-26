#include "AcademicStaffScoreBoard.h"

void import_from_csv(BoardNode*& head, ifstream& fin, StudentNode* root, ofstream &fout, string& coursename) {
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
	output_to_txt(root, fout, coursename);
	fin.close();
}
/*void view_scoreboard(BoardNode* head) {
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
}*/
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
/*void edit_grade(StudentNode* root) {
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
}*/

//Kiet's part
void outputScoreboard(BoardNode* pHead)
{
    string ID;
    cout << "Enter the ID of the student you want to view scoreboard";
    getline(cin, ID);
    while (pHead != nullptr)
    {
        if (pHead->id == ID)
        {
            cout << pHead->no << '\t' << pHead->student_id << '\t' << pHead->fullname << '\t' << pHead->class_
                << '\t';
            for (int i = 0; i < 4; i++) {
                cout << pHead->grade[i];
                if (i == 3) cout << endl;
                else cout << '\t';
            }
        }
        else
            cout << endl;
    }
}
void exportscoreboard(BoardNode* pHead, ofstream& f)
{
    f << "No,Student ID,Fullname,Class,Midterm,Final,Bonus,Total";
    while (pHead != nullptr)
    {
        f << pHead->no << "," << pHead->student_id << "," << pHead->fullname << "," << pHead->class_ << "," << pHead->grade[0] << "," << pHead->grade[1] << "," << pHead->grade[2] << "," << pHead->grade[3]<<endl;
        pHead = pHead->next;
    }
}

// Khang's part:
void import_scoreboard() {
	BoardNode* head = nullptr;
	ifstream fin;
	ofstream fout;
	StudentNode* root=nullptr;
	string coursename = "";
	input_list_student(root, fin, coursename);
	import_from_csv(head, fin, root, fout, coursename);
	delete_all(head);
	delete_all(root);
	
}

void view_scoreboard() {
	StudentNode* root = nullptr;
	string coursename = "";
	ifstream fin;
	StudentNode* head = root;
	input_list_student(root, fin, coursename);
	int i = 1;
	cout << "No" << '\t' << "ID " << '\t' << "Fullname" << '\t' << "Class" << '\t' << "Midterm" << '\t' << "Final" << '\t' << "Bonus" << '\t' << "Total" << endl;
	while (head) {
		cout << i << '\t' << head->id << '\t' << head->name << '\t' << head->class_
			<< '\t';
		for (int i = 0; i < 4; i++) {
			cout << head->grade[i];
			if (i == 3) cout << endl;
			else cout << '\t';
		}
		head = head->next;
		i++;
	}
	delete_all(root);
}


void edit_grade() {
	StudentNode* root = nullptr;
	string coursename = "";
	ifstream fin;
	input_list_student(root, fin, coursename);
	StudentNode* head = root;
	string id, name;
	cout << "Enter student's id ";
	getline(cin, id);
	cout << "Enter student's name ";
	getline(cin, name);
	while (head) {
		if (head->id == id) {
			break;
		}
		head = head->next;
	}
	if (head == nullptr) {
		cout << "Wrong ID" << endl;
		return;
	}
	int type;
	string new_grade;
	cout << "Enter the kind of grade ( 0 : Midterm, 1: final, 2: bonus, 3: total ) ";
	cin >> type;
	cout << "Enter new grade ";
	fflush(stdin);
	getline(cin, new_grade);
	
	head->grade[type] = new_grade;
	delete_all(root);

}