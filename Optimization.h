//
// Created by Duc An Chu on 5/26/20.
//

#ifndef CS162_19APCS2_GROUP12_OPTIMIZATION_H
#define CS162_19APCS2_GROUP12_OPTIMIZATION_H

#include <bits/stdc++.h>
#define STUDENT 0
#define LECTURER 1
#define STAFF 3
#define MALE 0
#define FEMALE 1

using namespace std;

struct global {
    static string username;
    static int type;
    static string workspace;
};

void normalize(string &s);

void normalizeFullName(string &s);

int DamerauLevenshteinDistance(string s1, string s2);

double similarity(string s1, string s2);

string getFirstName(string fullName);

string getTitle(string fullName, int type, int gender);

bool isStrongPassword(string password);

#endif //CS162_19APCS2_GROUP12_OPTIMIZATION_H
