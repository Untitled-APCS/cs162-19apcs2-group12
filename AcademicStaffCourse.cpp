#include"AcademicStaffCourse.h"

void readSemester(ifstream& finput,Semester*& semesterHead)
{
	finput.open("semester.txt");
	if (finput.peek() == finput.eof())
		return;
	semesterHead = new Semester;
	Semester* cur = semesterHead;
	while (!finput.eof())
	{
		finput >> cur->year;
		while (finput.get() != '\n');
		while (finput.get() != 'K');
		finput >> cur->term;
		if (finput.eof())
		{
			finput.close();
			return;
		}
		cur->next = new Semester;
		cur = cur->next;
	}
}

void createSemester(Semester*& semesterHead)
{
	if (semesterHead == NULL)
	{
		semesterHead = new Semester;
		cout << "Please input year: ";
		cin >> semesterHead->year;
		cout << "Please input term: ";
		cin >> semesterHead->term;
		return;
	}
	int checkTerm;
	int checkYear;
	cout << "Please input year: ";
	cin >> checkYear;
	cout << "Please input term: ";
	cin >> checkTerm;
	Semester* check = semesterHead;
	while (check != NULL)
	{
		if (check->term == checkTerm && check->year==checkYear)
		{
			cout << "Term has already existed." << endl;
			return;
		}
		check = check->next;
	}
	Semester* cur = semesterHead;
	while (cur->next!=NULL)
		cur = cur->next;
	cur->next = new Semester;
	cur = cur->next;
	cur->term = checkTerm;
	cur->year = checkYear;
}

void saveSemester(Semester* semesterHead, ofstream& foutput)
{
	while (semesterHead != NULL)
	{
		foutput << semesterHead->year<<"-"<<semesterHead->year+1 << endl;
		foutput << "HK" << semesterHead->term;
		if (semesterHead->next == NULL)
			return;
		foutput << endl << endl;
		semesterHead = semesterHead->next;
	}
}

void updateSemester(Semester*& semesterHead)
{
	Semester* cur = semesterHead;
	int checkYear;
	int checkTerm;
	cout << "Please choose semester's year to update: ";
	cin >> checkYear;
	cout << "Please choose term: ";
	cin >> checkTerm;
	while (true)
	{
		if (cur->year == checkYear&&cur->term==checkTerm)
			break;
		if (cur->next == NULL)
		{
			cout << "Semester does not exist" << endl;
			return;
		}
		cur = cur->next;
	}
}

void deleteSemester(Semester*& semesterHead)
{
	int checkYear, checkTerm;
	cout << "Please choose year: ";
	cin >> checkYear;
	cout << "Please choose term: ";
	cin >> checkTerm;
	Semester* cur = semesterHead;
	while (true)
	{
		if (cur->year == checkYear && cur->term == checkTerm)
			break;
		if (cur->next == NULL)
		{
			cout << "Semester does not exist" << endl;
			return;
		}
		cur = cur->next;
	}
	if (cur == semesterHead)
	{
		semesterHead = semesterHead->next;
		delete cur;
		cout << "Deleted successfully!" << endl;
		return;
	}
	Semester* prev=semesterHead;
	while (prev->next != cur)
		prev = prev->next;
	prev = cur->next;
	cout << "Deleted successfully!" << endl;
	delete cur;
}

void viewSemester(Semester* semesterHead)
{
	cout << "List:" << endl;
	while (semesterHead != NULL)
	{
		cout << semesterHead->year<<"-"<<semesterHead->year+1<<endl;
		cout << "HK"<<semesterHead->term<<endl<<endl;
		semesterHead = semesterHead->next;
	}
}

Course* inputCourse()
{
	Course* cur = new Course;
	cur->ID = new char[10];
	cur->name = new char[100];
	cur->className = new char[10];
	cur->lecturerUsername = new char[10];
	cur->lecturerName = new char[50];
	cur->lecturerDegree = new char[10];
	cur->lecturerGender = new char[10];
	cout << "Input Course ID: ";
	cin.ignore();
	cin.get(cur->ID, 10, '\n');
	cin.ignore();
	cout << "Input course name: ";
	cin.get(cur->name, 100, '\n');
	cin.ignore();
	cout << "Input class name: ";
	cin.get(cur->className, 10, '\n');
	cin.ignore();
	cout << "Input lecturer username: ";
	cin.get(cur->lecturerUsername, 10, '\n');
	cin.ignore();
	cout << "Input lecturer name: ";
	cin.get(cur->lecturerName, 50, '\n');
	cin.ignore();
	cout << "Input lecturer degree: ";
	cin.get(cur->lecturerDegree, 10, '\n');
	cin.ignore();
	cout << "Input lecturer gender: ";
	cin.get(cur->lecturerGender, 10, '\n');
	cout << "Input Course's start day: ";
	cin >> cur->startDate.day;
	cout << "Input Course's start month: ";
	cin >> cur->startDate.month;
	cout << "Input Course's start year: ";
	cin >> cur->startDate.year;
	cout << "Input Course's end day: ";
	cin >> cur->endDate.day;
	cout << "Input Course's end month: ";
	cin >> cur->endDate.month;
	cout << "Input Course's end year: ";
	cin >> cur->endDate.year;
	cin.ignore();
	char* tempDay = new char[4];
	cout << "Input day in weeks: ";
	cin.get(tempDay, 4, '\n');
	if (strcmp(tempDay, "MON") == 0)
		cur->daysOfWeek = 2;
	else if (strcmp(tempDay, "TUE") == 0)
		cur->daysOfWeek = 3;
	else if (strcmp(tempDay, "WED") == 0)
		cur->daysOfWeek = 4;
	else if (strcmp(tempDay, "THU") == 0)
		cur->daysOfWeek = 5;
	else if (strcmp(tempDay, "FRI") == 0)
		cur->daysOfWeek = 6;
	else if (strcmp(tempDay, "SAT") == 0)
		cur->daysOfWeek = 7;
	else if (strcmp(tempDay, "SUN") == 0)
		cur->daysOfWeek = 8;
	cout << "Input course's start hour: ";
	cin >> cur->startHour;
	cout << "Input course's start min: ";
	cin >> cur->startMin;
	cout << "Input course's end hour: ";
	cin >> cur->endHour;
	cout << "Input course's end min: ";
	cin >> cur->endMin;
	cin.ignore();
	cout << "Input room: ";
	cur->room = new char[10];
	cin.get(cur->room, 10, '\n');
	return cur;
}

void importSchedule(ifstream& finput,ofstream& foutput,Course*& courseHead,Semester* semesterHead)
{
	int checkYear, checkTerm;
	string filename;
	cout << "Enter academic years: ";
	cin >> checkYear;
	cout << "Enter semester: ";
	cin >> checkTerm;
	Semester* check = semesterHead;
	if (semesterHead == NULL)
	{
		cout << "Semester does not exist" << endl;
		return;
	}
	while (true)
	{
		if (semesterHead->year == checkYear && semesterHead->term == checkTerm)
			break;
		if (semesterHead->next == NULL)
		{
			cout << "Semester does not exist"<<endl;
			return;
		}
		semesterHead = semesterHead->next;
	}
	char* className = new char[10];
	cout << "Enter class: ";
	cin.ignore();
	cin.get(className, 10, '\n');
	filename = "Student-";
	filename += className;
	filename += ".txt";
	finput.open(filename);
	if (!finput.is_open())
	{
		cout << "Student file not found.";
		return;
	}
	Student* studentHead = new Student;
	Student* curStu = studentHead;
	while (!finput.eof())
	{
		curStu->password = new char[100];
		curStu->name = new char[100];
		curStu->className = new char[10];
		finput >> curStu->ID;
		finput.ignore();
		finput.get(curStu->password, 100, '\n');
		finput.ignore();
		finput.get(curStu->name, 100, '\n');
		finput >> curStu->doB.year;
		finput >> curStu->doB.month;
		finput >> curStu->doB.day;
		finput.ignore();
		finput.get(curStu->className, 10, '\n');
		finput >> curStu->status;
		finput.ignore(1000, '\n');
		if (finput.eof())
			break;
		curStu->next = new Student;
		curStu = curStu->next;
		
	}
	finput.close();
	
	char temp[1000];
	cout << "Enter file path: ";
	cin.ignore();
	cin.get(temp, 1000, '\n');
	char* path = new char[strlen(temp) + 1];
	strcpy_s(path, strlen(temp) + 1, temp);
	finput.open(path);
	if (!finput.is_open())
		cout << "File does not exist" << endl;
	else
	{
		courseHead = new Course;
		Course* cur = courseHead;
		while (finput.get() != '1');
		finput.ignore();
		while (!finput.eof())
		{
			cur->ID = new char[10];
			cur->name = new char[100];
			cur->className = new char[10];
			cur->lecturerUsername= new char[10];
			cur->lecturerName= new char[50];
			cur->lecturerDegree= new char[10];
			cur->lecturerGender= new char[10];
			finput.get(cur->ID, 10, ',');
			finput.ignore();
			finput.get(cur->name, 100, ',');
			finput.ignore();
			finput.get(cur->className, 10, ',');
			finput.ignore();
			finput.get(cur->lecturerUsername, 10, ',');
			finput.ignore();
			finput.get(cur->lecturerName, 50, ',');
			finput.ignore();
			finput.get(cur->lecturerDegree, 10, ',');
			finput.ignore();
			finput.get(cur->lecturerGender, 10, ',');
			char* tempDate = new char[5];
			finput.ignore();
			finput.get(tempDate, 3, '/');
			cur->startDate.month = atoi(tempDate);
			finput.ignore();
			finput.get(tempDate, 3, '/');
			cur->startDate.day = atoi(tempDate);
			finput.ignore();
			finput.get(tempDate, 5, ',');
			cur->startDate.year = atoi(tempDate);
			finput.ignore();
			finput.get(tempDate, 3, '/');
			cur->endDate.month = atoi(tempDate);
			finput.ignore();
			finput.get(tempDate, 3, '/');
			cur->endDate.day = atoi(tempDate);
			finput.ignore();
			finput.get(tempDate, 5, ',');
			cur->endDate.year = atoi(tempDate);
			finput.ignore();
			char* tempDay = new char[4];
			finput.get(tempDay, 4, ',');
			if (strcmp(tempDay, "MON") == 0)
				cur->daysOfWeek = 2;
			else if (strcmp(tempDay,"TUE")==0)
				cur->daysOfWeek = 3;
			else if (strcmp(tempDay, "WED") == 0)
				cur->daysOfWeek = 4;
			else if (strcmp(tempDay, "THU") == 0)
				cur->daysOfWeek = 5;
			else if (strcmp(tempDay, "FRI") == 0)
				cur->daysOfWeek = 6;
			else if (strcmp(tempDay, "SAT") == 0)
				cur->daysOfWeek = 7;
			else if (strcmp(tempDay, "SUN") == 0)
				cur->daysOfWeek = 8;
			finput.ignore();
			finput >> cur->startHour;
			finput.ignore();
			finput >> cur->startMin;
			finput.ignore();
			finput >> cur->endHour;
			finput.ignore();
			finput >> cur->endMin;
			finput.ignore();
			cur->room = new char[10];
			finput.get(cur->room, 10, '\n');
			
			if (finput.eof())
				break;
			cur->next = new Course;
			cur = cur->next;
			while (finput.get() != ',');
		}
		finput.close();
	}
	
	filename = "";
	filename += to_string(checkYear);
	filename += "-";
	filename += to_string(checkYear+1);
	filename += "-HK";
	filename += to_string(checkTerm);
	filename += "-Schedule-";
	filename += className;
	filename += ".txt";
	
	Course* cur = courseHead;
	foutput.open(filename.c_str());
	while (cur != NULL)
	{
		foutput << cur->ID << endl;
		foutput << cur->name << endl;
		foutput << cur->className << endl;
		foutput << cur->lecturerUsername << endl;
		foutput << cur->lecturerName << endl;
		foutput << cur->lecturerDegree << endl;
		foutput << cur->lecturerGender << endl;
		foutput << cur->startDate.month << " " << cur->startDate.day << " "<<cur->startDate.year << endl;
		foutput << cur->endDate.month << " " << cur->endDate.day << " " << cur->endDate.year << endl;
		foutput << cur->daysOfWeek<<endl;
		foutput << cur->startHour << " " << cur->startMin << endl;
		foutput << cur->endHour << " " << cur->endMin << endl;
		foutput << cur->room;
		if (cur->next == NULL)
			break;
		foutput << endl << endl;
		cur = cur->next;
	}
	foutput.close();
	cur = courseHead;
	
	while (cur != NULL)
	{
		curStu = studentHead;
		filename = "";
		filename += to_string(checkYear);
		filename += "-";
		filename += to_string(checkYear + 1);
		filename += "-HK";
		filename += to_string(checkTerm);
		filename += "-";
		filename += className;
		filename += "-";
		filename += cur->ID;
		filename += "-Student.txt";
		foutput.open(filename.c_str());
		while (curStu != NULL)
		{
			foutput << curStu->ID << endl;
			foutput << curStu->name << endl;
			foutput << curStu->doB.year << " " << curStu->doB.month << " " << curStu->doB.day << endl;
			foutput << curStu->className << endl;
			foutput << curStu->status << endl;
			foutput << "-1" << endl << "-1" << endl << "-1" << endl << "-1" << endl;
			for (int i = 0; i < 9; ++i)
				foutput << "Week" << i + 1 << " -1" << endl;
			if (curStu->next == NULL)
			{
				foutput << "Week10 -1";
				break;
			}
			foutput << "Week10 -1" << endl << endl;
			curStu = curStu->next;
		}
		
		foutput.close();
		cur = cur->next;
	}

	cout << "Import successfully!";
}

void addCourse(ofstream& foutput,Semester* semesterHead)
{
	int checkYear, checkTerm;
	cout << "Enter academic years: ";
	cin >> checkYear;
	cout << "Enter semester: ";
	cin >> checkTerm;
	Semester* check = semesterHead;
	if (semesterHead == NULL)
	{
		cout << "Semester does not exist" << endl;
		return;
	}
	while (true)
	{
		if (semesterHead->year == checkYear && semesterHead->term == checkTerm)
			break;
		if (semesterHead->next == NULL)
		{
			cout << "Semester does not exist" << endl;
			return;
		}
		semesterHead = semesterHead->next;
	}
	char* className = new char[10];
	cout << "Enter class: ";
	cin.ignore();
	cin.get(className, 10, '\n');

	string filename;
	filename += to_string(checkYear);
	filename += "-";
	filename += to_string(checkYear + 1);
	filename += "-HK";
	filename += to_string(checkTerm);
	filename += "-Schedule-";
	filename += className;
	filename += ".txt";
	foutput.open(filename,foutput.app);
	if (!foutput.is_open())
	{
		cout << "Schedule of class does not exist";
		return;
	}
	Course* cur = inputCourse();
	foutput << endl<<endl;
	foutput << cur->ID << endl;
	foutput << cur->name << endl;
	foutput << cur->className << endl;
	foutput << cur->lecturerUsername << endl;
	foutput << cur->lecturerName << endl;
	foutput << cur->lecturerDegree << endl;
	foutput << cur->lecturerGender << endl;
	foutput << cur->startDate.month << " " << cur->startDate.day << " " << cur->startDate.year << endl;
	foutput << cur->endDate.month << " " << cur->endDate.day << " " << cur->endDate.year << endl;
	foutput << cur->daysOfWeek << endl;
	foutput << cur->startHour << " " << cur->startMin << endl;
	foutput << cur->endHour << " " << cur->endMin << endl;
	foutput << cur->room;
	foutput.close();
	cout << "Add successfully";
}

void savetxtCourse(ofstream& foutput, Course*& courseHead)
{
	Course* cur = courseHead;
	while (cur != NULL)
	{
		foutput << cur->ID << endl;
		foutput << cur->name << endl;
		foutput << cur->className << endl;
		foutput << cur->lecturerUsername << endl;
		foutput << cur->lecturerName << endl;
		foutput << cur->lecturerDegree << endl;
		foutput << cur->lecturerGender << endl;
		foutput << cur->startDate.month << " " << cur->startDate.day << " " << cur->startDate.year << endl;
		foutput << cur->endDate.month << " " << cur->endDate.day << " " << cur->endDate.year << endl;
		foutput << cur->daysOfWeek << endl;
		foutput << cur->startHour << " " << cur->startMin << endl;
		foutput << cur->endHour << " " << cur->endMin << endl;
		foutput << cur->room;
		if (cur->next == NULL)
			break;
		foutput << endl << endl;
		cur = cur->next;
	}
}

void editCourse(ifstream& finput, ofstream& foutput, Semester* semesterHead, Course*& courseHead)
{
	int checkYear, checkTerm;
	cout << "Enter academic years: ";
	cin >> checkYear;
	cout << "Enter semester: ";
	cin >> checkTerm;
	Semester* check = semesterHead;
	if (semesterHead == NULL)
	{
		cout << "Semester does not exist" << endl;
		return;
	}
	while (true)
	{
		if (semesterHead->year == checkYear && semesterHead->term == checkTerm)
			break;
		if (semesterHead->next == NULL)
		{
			cout << "Semester does not exist" << endl;
			return;
		}
		semesterHead = semesterHead->next;
	}
	char* className = new char[10];
	cout << "Enter class: ";
	cin.ignore();
	cin.get(className, 10, '\n');

	string filename;
	filename += to_string(checkYear);
	filename += "-";
	filename += to_string(checkYear + 1);
	filename += "-HK";
	filename += to_string(checkTerm);
	filename += "-Schedule-";
	filename += className;
	filename += ".txt";
	finput.open(filename);
	if (!finput.is_open())
	{
		cout << "Schedule of class does not exist";
		return;
	}
	courseHead = new Course;
	readCourse(finput, courseHead);
	Course* cur = courseHead;
	cout << "List of course: ";
	while (cur != NULL)
	{
		cout << cur->ID << ", ";
		cur = cur->next;
	}
	cur = courseHead;
	char* temp = new char[10];
	cout <<endl<< "Please choose a course to edit: ";
	cin.ignore();
	cin.get(temp, 10, '\n');
	cin.ignore();
	while (cur != NULL && strcmp(temp,cur->ID)!=0)
		cur = cur->next;
	cout << "Input Course ID: ";
	cin.get(cur->ID, 10, '\n');
	cin.ignore();
	cout << "Input course name: ";
	cin.get(cur->name, 100, '\n');
	cin.ignore();
	cout << "Input class name: ";
	cin.get(cur->className, 10, '\n');
	cin.ignore();
	cout << "Input lecturer username: ";
	cin.get(cur->lecturerUsername, 10, '\n');
	cin.ignore();
	cout << "Input lecturer name: ";
	cin.get(cur->lecturerName, 50, '\n');
	cin.ignore();
	cout << "Input lecturer degree: ";
	cin.get(cur->lecturerDegree, 10, '\n');
	cin.ignore();
	cout << "Input lecturer gender: ";
	cin.get(cur->lecturerGender, 10, '\n');
	cout << "Input Course's start day: ";
	cin >> cur->startDate.day;
	cout << "Input Course's start month: ";
	cin >> cur->startDate.month;
	cout << "Input Course's start year: ";
	cin >> cur->startDate.year;
	cout << "Input Course's end day: ";
	cin >> cur->endDate.day;
	cout << "Input Course's end month: ";
	cin >> cur->endDate.month;
	cout << "Input Course's end year: ";
	cin >> cur->endDate.year;
	cin.ignore();
	char* tempDay = new char[4];
	cout << "Input day in weeks: ";
	cin.get(tempDay, 4, '\n');
	if (strcmp(tempDay, "MON") == 0)
		cur->daysOfWeek = 2;
	else if (strcmp(tempDay, "TUE") == 0)
		cur->daysOfWeek = 3;
	else if (strcmp(tempDay, "WED") == 0)
		cur->daysOfWeek = 4;
	else if (strcmp(tempDay, "THU") == 0)
		cur->daysOfWeek = 5;
	else if (strcmp(tempDay, "FRI") == 0)
		cur->daysOfWeek = 6;
	else if (strcmp(tempDay, "SAT") == 0)
		cur->daysOfWeek = 7;
	else if (strcmp(tempDay, "SUN") == 0)
		cur->daysOfWeek = 8;
	cout << "Input course's start hour: ";
	cin >> cur->startHour;
	cout << "Input course's start min: ";
	cin >> cur->startMin;
	cout << "Input course's end hour: ";
	cin >> cur->endHour;
	cout << "Input course's end min: ";
	cin >> cur->endMin;
	cin.ignore();
	cout << "Input room: ";
	cur->room = new char[10];
	cin.get(cur->room, 10, '\n');
	cout << "Edited successfully!" << endl;
	delete[]temp;
	finput.close();
	foutput.open(filename);
	savetxtCourse(foutput, courseHead);
	foutput.close();
}


void readCourse(ifstream& finput, Course*& courseHead)
{
	Course* cur = courseHead;
	while (!finput.eof())
	{
		cur->ID = new char[10];
		cur->name = new char[100];
		cur->className = new char[10];
		cur->lecturerUsername = new char[10];
		cur->lecturerName = new char[50];
		cur->lecturerDegree = new char[10];
		cur->lecturerGender = new char[10];
		cur->room = new char[10];
		finput.get(cur->ID, 10, '\n');
		finput.ignore();
		finput.get(cur->name, 100, '\n');
		finput.ignore();
		finput.get(cur->className, 10, '\n');
		finput.ignore();
		finput.get(cur->lecturerUsername, 10, '\n');
		finput.ignore();
		finput.get(cur->lecturerName, 50, '\n');
		finput.ignore();
		finput.get(cur->lecturerDegree, 10, '\n');
		finput.ignore();
		finput.get(cur->lecturerGender, 10, '\n');
		finput >> cur->startDate.month;
		finput >> cur->startDate.day;
		finput >> cur->startDate.year;
		finput >> cur->endDate.month;
		finput >> cur->endDate.day;
		finput >> cur->endDate.year;
		finput >> cur->daysOfWeek;
		finput >> cur->startHour;
		finput >> cur->startMin;
		finput >> cur->endHour;
		finput >> cur->endMin;
		finput.ignore();
		finput.get(cur->room, 10, '\n');
		if (finput.eof())
			break;
		finput.ignore();
		
		while (finput.get() != '\n');
		
		cur->next = new Course;
		cur = cur->next;
		
	}
}

void removeCourse(Course*& courseHead)
{
	Course* cur = courseHead;
	cout << "List of course: ";
	while (cur != NULL)
	{
		cout << cur->ID << ", ";
		cur = cur->next;
	}
	cur = courseHead;
	char* temp = new char[10];
	cout << endl << "Please choose a course to remove: ";
	cin.ignore();
	cin.get(temp, 10, '\n');
	cin.ignore();
	while (cur != NULL && strcmp(temp, cur->ID) != 0)
		cur = cur->next;
	if (cur == courseHead)
	{
		courseHead = courseHead->next;
		delete cur;
		cout << "Removed successfully";
		return;
	}
	Course* prev = courseHead;
	while (prev->next != NULL && prev->next != cur)
	{
		prev->next = cur->next;
		delete cur;
		cout << "Removed successfully";
		return;
	}
}

void readStudentCourse(ifstream& finput, Student*& studentHead)
{
	Student* cur = studentHead;
	while (!finput.eof())
	{
		cur->name = new char[100];
		cur->className = new char[10];
		finput >> cur->ID;
		finput.ignore();
		finput.get(cur->name, 100, '\n');
		finput >> cur->doB.year;
		finput >> cur->doB.month;
		finput >> cur->doB.day;
		finput.ignore();
		finput.get(cur->className, 10, '\n');
		finput >> cur->status;
		for (int i = 0; i < 4; ++i)
		{
			finput >> cur->grade[i];
		}
		for (int i = 0; i < 10; ++i)
		{
			finput.ignore(100, ' ');
			finput >> cur->attend[i];
		}
		if (finput.eof())
			break;
		finput.ignore(100, '\n');
		cur->next = new Student;
		cur = cur->next;
	}
}

void saveStudentCourse(ofstream& foutput, Student* studentHead)
{
	Student* cur = studentHead;
	while (cur!=NULL)
	{
		foutput << cur->ID<<endl;
		foutput << cur->name << endl;
		foutput << cur->doB.year << " " << cur->doB.month << " " << cur->doB.day  << endl;
		foutput << cur->className << endl;
		foutput << cur->status << endl;
		for (int i = 0; i < 4; ++i)
		{
			foutput << cur->grade[i]<<endl;
		}
		for (int i = 0; i < 10; ++i)
		{
			foutput << "Week" << i + 1 << " " << cur->attend[i];
			if (i == 9 && cur->next == NULL)
				break;
			foutput << endl;
			if (i == 9)
				foutput << endl;
		}
		cur = cur->next;
	}
}

void removeStudentCourse(ifstream& finput,ofstream& foutput,Course*& courseHead, Semester* semesterHead,Student*& studentHead)
{
	int checkYear, checkTerm;
	cout << "Enter academic years: ";
	cin >> checkYear;
	cout << "Enter semester: ";
	cin >> checkTerm;
	Semester* check = semesterHead;
	if (semesterHead == NULL)
	{
		cout << "Semester does not exist" << endl;
		return;
	}
	while (semesterHead->year != checkYear && semesterHead->term != checkTerm)
	{
		if (semesterHead->next == NULL)
		{
			cout << "Semester does not exist" << endl;
			return;
		}
		semesterHead = semesterHead->next;
	}
	char* className = new char[10];
	cout << "Enter class: ";
	cin.ignore();
	cin.get(className, 10, '\n');
	char* courseName = new char[10];
	cout << "Enter course ID: ";
	cin.ignore();
	cin.get(courseName, 10, '\n');
	string filename;
	filename += to_string(checkYear);
	filename += "-";
	filename += to_string(checkYear + 1);
	filename += "-HK";
	filename += to_string(checkTerm);
	filename += "-";
	filename += className;
	filename += "-";
	filename += courseName;
	filename += "-Student.txt";
	finput.open(filename);
	if (!finput.is_open())
	{
		cout << "file not found.";
		return;
	}
	emptyStudent(studentHead);
	studentHead = new Student;
	readStudentCourse(finput, studentHead);
	finput.close();
	cout << "Please input Student ID you want to delete: ";
	int temp;
	cin >> temp;
	Student* cur = studentHead;
	while (cur != NULL && cur->ID != temp)
		cur = cur->next;
	if (cur == NULL)
	{
		cout << "Student not found" << endl;
		return;
	}
	if (cur == studentHead)
	{
		studentHead = studentHead->next;
		delete cur;
		cout << "Deleted successfully!";
		return;
	}
	Student* prev = studentHead;
	while (prev->next != NULL && prev->next != cur)
		prev = prev->next;
	prev->next = cur->next;
	delete cur;
	foutput.open(filename);
	saveStudentCourse(foutput, studentHead);
	foutput.close();
}

void addStudentCourse(ifstream& finput, ofstream& foutput, Student*& studentHead, Semester* semesterHead)
{
	char* className = new char[10];
	cout << "Enter student's class: ";
	cin.ignore();
	cin.get(className, 10, '\n');
	string filename;
	filename = "Student-";
	filename += className;
	filename += ".txt";
	finput.open(filename);
	if (!finput.is_open())
	{
		cout << "Class does not exist." << endl;
		return;
	}
	studentHead = new Student;
	Student* curStu = studentHead;
	while (!finput.eof())
	{
		curStu->password = new char[100];
		curStu->name = new char[100];
		curStu->className = new char[10];
		finput >> curStu->ID;
		finput.ignore();
		finput.get(curStu->password, 100, '\n');
		finput.ignore();
		finput.get(curStu->name, 100, '\n');
		finput >> curStu->doB.month;
		finput >> curStu->doB.day;
		finput >> curStu->doB.year;
		finput.ignore();
		finput.get(curStu->className, 10, '\n');
		finput >> curStu->status;
		finput.ignore(1000, '\n');
		if (finput.eof())
			break;
		curStu->next = new Student;
		curStu = curStu->next;

	}
	finput.close();
	char* temp = new char[20];
	cout << "Please input the year of course: ";
	int tempYear;
	cin >> tempYear;
	filename = "";
	filename += to_string(tempYear);
	filename += "-";
	filename += to_string(tempYear + 1);
	filename += "-";
	cin.ignore();
	cout << "Please input semester: ";
	cin.get(temp, 20, '\n');
	filename += "HK";
	filename += temp;
	cout << "Please input course's class: ";
	cin.ignore();
	cin.get(temp, 20, '\n');
	filename += "-";
	filename += temp;
	cout << "Please input course's ID: ";
	cin.ignore();
	cin.get(temp, 20, '\n');
	filename += "-";
	filename += temp;
	filename += "-Student.txt";
	foutput.open(filename, foutput.app);
	if (!foutput.is_open())
	{
		cout << "Class does not exist." << endl;
		return;
	}
	cout << "Input student ID to add: ";
	int tempID;
	cin >> tempID;
	Student* cur = studentHead;
	while (cur != NULL && cur->ID != tempID)
	{
		cur = cur->next;
		if (cur->next == NULL)
		{
			cout << "Student not found.";
			return;
		}
	}
	foutput << endl;
	foutput << cur->ID << endl;
	foutput << cur->name << endl;
	foutput << cur->doB.month << " " << cur->doB.day << " " << cur->doB.year << endl;
	foutput << cur->className << endl;
	foutput << cur->status << endl;
	foutput << "-1" << endl << "-1" << endl << "-1" << endl << "-1" << endl;
	for (int i = 0; i < 9; ++i)
		foutput << "Week" << i + 1 << " -1" << endl;
	foutput << "Week10 -1" << endl << endl;
	foutput.close();
	delete[]temp;
	cout << "Added Successfully";
}

void emptyStudent(Student*& studentHead)
{
	Student* temp;
	while (studentHead != NULL)
	{
		temp = studentHead;
		studentHead = studentHead->next;
		delete[]temp->name;
		delete[]temp->className;
		delete temp;
	}
}
void emptyCourse(Course*& courseHead)
{
	Course* temp;
	while (courseHead != NULL)
	{
		temp = courseHead;
		courseHead = courseHead->next;
		delete[]temp->ID;
		delete[]temp->name;
		delete[]temp->className;
		delete[]temp->lecturerUsername;
		delete[]temp->lecturerName;
		delete[]temp->lecturerDegree;
		delete[]temp->lecturerGender;
		delete[]temp->room;
		delete temp;
	}
}

void emptySemester(Semester*& semesterHead)
{
	Semester* temp;
	while (semesterHead != NULL)
	{
		temp = semesterHead;
		semesterHead = semesterHead->next;
		delete temp;
	}
}