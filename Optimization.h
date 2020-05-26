//
// Created by Duc An Chu on 5/26/20.
//

#ifndef CS162_19APCS2_GROUP12_OPTIMIZATION_H
#define CS162_19APCS2_GROUP12_OPTIMIZATION_H

#include <bits/stdc++.h>
#define STUDENT 0
#define LECTURER 1
#define STAFF 3

using namespace std;

void normalize(string s);

int LevenshteinDistance(string s1, string s2);

double similarity(string s1, string s2);

string getFirstName(string fullName);

string getTitle(int type, int gender);

#endif //CS162_19APCS2_GROUP12_OPTIMIZATION_H
