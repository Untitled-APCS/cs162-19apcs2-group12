//
// Created by Duc An Chu on 5/26/20.
//

#ifndef CS162_19APCS2_GROUP12_ALLROLES_H
#define CS162_19APCS2_GROUP12_ALLROLES_H

#include <bits/stdc++.h>
#include "Optimization.h"

using namespace std;

void login(string &Username, int &type);

void showMenu();

void viewProfileInfo(string &username, int type);

void changePassword(string &username, int type);

void logOut(string &username, int &type);

#endif //CS162_19APCS2_GROUP12_ALLROLES_H
