//
// Created by Duc An Chu on 5/26/20.
//

#ifndef CS162_19APCS2_GROUP12_OPTIMIZATION_H
#define CS162_19APCS2_GROUP12_OPTIMIZATION_H

#include <Engine/stdc++.h>
#include <filesystem>
#include "DateTime.h"
#include "AppLocation.h"

#define userTitle getTitle(user::fullName, user::type, user::gender)

#define STUDENT 0
#define LECTURER 1
#define STAFF 2

#define MALE 1
#define FEMALE 0

#define ENTER (char) 13
#define ESC (char) 27

#define EXITCODE(n) {exitProgram(n); return;}
#define EXITCODE_V(n, return_value) {exitProgram(n); return return_value;}

using namespace std;

//string fileLocation;
//string staffListLocation;

struct user {
    static string ID;
    static int type;
    static string workspace;
    static string fullName;
    static int gender;
};

void normalize(string &s);

void normalizeFullName(string &s);

int DamerauLevenshteinDistance(string s1, string s2);

double similarity(string s1, string s2);

double suitability(string s1, string s2);

string getFirstName(string fullName);

string getTitle(string fullName, int type, int gender);

bool isStrongPassword(string password);

string getGreeting();

void exitProgram(int code);

#endif //CS162_19APCS2_GROUP12_OPTIMIZATION_H
