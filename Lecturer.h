#include "Engine.h"
#include "AllRoles.h"

void staff_4_1();

void staff_4_2();

void staff_4_3();

void staff_4_4();

void staff_4_5();

bool checkStaff_4_1();

bool checkStaff_4_2();

bool checkStaff_4_3();

bool checkStaff_4_4();

bool checkStaff_4_5();

void lecturer_1_();
void lecturer_2_();
void lecturer_3_();
void lecturer_4_();
void lecturer_5_();
void lecturer_6_();
void lecturer_7_();

bool checklecturer_1(string* s, int n);
bool checklecturer_2(string* s, int n);
bool checklecturer_3(string* s, int n);
bool checklecturer_4(string* s, int n);
bool checklecturer_5(string* s, int n);
bool checklecturer_6(string* s, int n);
bool checklecturer_7(string* s, int n);

// Activities:
bool isPermissible(string courseID);
void printCourse(CourseNode* node, int&index);
void printStudent(StudentNode* node, int &index);
void printArray(int* arr, int n);
void printScoreboard(StudentList llist, CourseStudentList llist2);
void saveCSV(CourseStudentList llist, string filePath);

