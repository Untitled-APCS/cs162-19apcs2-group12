//
// Created by Duc An Chu on 5/26/20.
//

#ifndef CS162_19APCS2_GROUP12_OPTIMIZATION_H
#define CS162_19APCS2_GROUP12_OPTIMIZATION_H

#include <bits/stdc++.h>
#include <filesystem>
#include "DateTime.h"
#include "AppLocation.h"

#include "cppcrypto/sha256.h"
#include "cppcrypto/hmac.h"
#include "cppcrypto/portability.h"
#include "cppcrypto/crypto_hash.h"
#include "cppcrypto/pbkdf2.h"
#include "cppcrypto/cpuinfo.h"
#include "cppcrypto/alignedarray.h"
//Sources: http://cppcrypto.sourceforge.net/
//https://neurotechnics.com/tools/pbkdf2-test
//https://asecuritysite.com/encryption/PBKDF2z

#define userTitle getTitle(user::fullName, user::type, user::gender)

#define STUDENT 0
#define LECTURER 1
#define STAFF 2

#define MALE 1
#define FEMALE 0

#define SKIP 1
#define REPLACE 2
#define SKIP_ALL 3
#define REPLACE_ALL 4

#define ENTER (char) 13
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
    static string password;
    static int gender;
    //
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

void unsigedCharToHexString(unsigned char *key, int keyLen, string &ans);

string getHashedPassword(string password);

string getCheckInCode(string semesterID, string classID, string courseID, int week);

void exitProgram(int code);

#endif //CS162_19APCS2_GROUP12_OPTIMIZATION_H
