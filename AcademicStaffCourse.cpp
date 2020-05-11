#include<iostream>
using namespace std;
#include<fstream>
#include"AcademicStaffCourse.h"
#include<string>


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
		cout << semesterHead->year<<"-"<<semesterHead->next+1<<endl;
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
			cout << "Semester does not exist"<<endl;
			return;
		}
		semesterHead = semesterHead->next;
	}
	char* className = new char[10];
	cout << "Enter class: ";
	cin.ignore();
	cin.get(className, 10, '\n');
	
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
			char* tempDate = new char[3];
			finput.ignore();
			finput.get(tempDate, 3, '/');
			cur->startDate.day=atoi(tempDate);
			finput.ignore();
			finput.get(tempDate, 3, '/');
			cur->startDate.month = atoi(tempDate);
			finput.ignore();
			finput.get(tempDate, 3, ',');
			cur->startDate.year = atoi(tempDate);
			finput.ignore();
			finput.get(tempDate, 3, '/');
			cur->endDate.day = atoi(tempDate);
			finput.ignore();
			finput.get(tempDate, 3, '/');
			cur->endDate.month = atoi(tempDate);
			finput.ignore();
			finput.get(tempDate, 3, ',');
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
	string filename;
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
		foutput << cur->startDate.year << " " << cur->startDate.month << " "<<cur->startDate.day << endl;
		foutput << cur->endDate.year << " " << cur->endDate.month << " " << cur->endDate.day << endl;
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
	foutput << cur->ID << endl;
	foutput << cur->name << endl;
	foutput << cur->className << endl;
	foutput << cur->lecturerUsername << endl;
	foutput << cur->lecturerName << endl;
	foutput << cur->lecturerDegree << endl;
	foutput << cur->lecturerGender << endl;
	foutput << cur->startDate.year << " " << cur->startDate.month << " " << cur->startDate.day << endl;
	foutput << cur->endDate.year << " " << cur->endDate.month << " " << cur->endDate.day << endl;
	foutput << cur->daysOfWeek << endl;
	foutput << cur->startHour << " " << cur->startMin << endl;
	foutput << cur->endHour << " " << cur->endMin << endl;
	foutput << cur->room << endl << endl;
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
		foutput << cur->startDate.year << " " << cur->startDate.month << " " << cur->startDate.day << endl;
		foutput << cur->endDate.year << " " << cur->endDate.month << " " << cur->endDate.day << endl;
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
		finput >> cur->startDate.year;
		finput >> cur->startDate.month;
		finput >> cur->startDate.day;
		finput >> cur->endDate.year;
		finput >> cur->endDate.month;
		finput >> cur->endDate.day;
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
	cout << endl << "Please choose a course to removed: ";
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