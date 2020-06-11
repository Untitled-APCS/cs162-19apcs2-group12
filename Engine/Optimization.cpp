//
// Created by Duc An Chu on 5/26/20.
//

#include "Optimization.h"

string user::ID;
int user::type = -1;
string user::workspace = "/";
string user::fullName;
int user::gender = -1;

void normalize(string &s) {
    //Convert string to lowercase and remove space
    string ans;

    for (int i = 0; i<s.length(); i++)
        if (s[i] != ' ') {
            if (s[i] >= 'A' && s[i] <= 'Z')
                s[i] += 'a' - 'A';
            ans.push_back(s[i]);
        }

    s = ans;
}

void normalizeFullName(string &s) {
    s += " ";
    string ans, r;
    int n = s.length();

    for (int i = 0; i<n; i++)
        if (s[i] == ' ') {
            if (r != "") {
                ans.push_back(toupper(r[0]));
                for (int j = 1; j < r.length(); j++)
                    ans.push_back(tolower(r[j]));
                ans.push_back(' ');

                r.clear();
            }
        } else
            r.push_back(s[i]);

    ans.pop_back();
    s = ans;
}

int DamerauLevenshteinDistance(string s1, string s2) {
    //Using Dynamic Programming to compute the Damerau-Levenshtein distance betw/ two strings
    //The Levenshtein distance is the least number of steps to transform string s1 to s2
    //Each step must be one of these:
    //  + Delete one char in s1
    //  + Insert one char into s2
    //  + Change one char in s1 into another char
    //  + Swap two consecutive chars of s1
    //Uppercase and lowercase chars are treated equally
    
    //Initialization
    normalize(s1);
    normalize(s2);
    int m = s1.length(), n = s2.length();
    s1 = " " + s1; s2 = " " + s2;
    int inf = numeric_limits<int>::max() / 100;

    int **L = new int* [m + 1];
    for (int i = 0; i<=m; i++) {
        L[i] = new int[n + 1];
        for (int j = 0; j<=n; j++) {
            L[i][j] = inf;
            if (i == 0) L[i][j] = j;
            if (j == 0) L[i][j] = i;
        }
    }

    //DP
    for (int i = 1; i<=m; i++)
        for (int j = 1; j<=n; j++) {
            L[i][j] = min(L[i][j],
                      min(L[i - 1][j] + 1, //Delete s1[i] in s1
                      min(L[i][j - 1] + 1, //Insert s2[j] at the end of s2[1..j-1]
                          L[i - 1][j - 1] +
                          (s1[i] == s2[j] ? 0 : 1)))); //Change s1[i] into s2[j]

            if (i > 1 && j > 1 && s1[i] == s2[j-1] && s1[i-1] == s2[j]) //Swap s1[i] and s1[j]
                L[i][j] = min(L[i][j], L[i-2][j-2] + 1);
        }

//    for (int i = 0; i<=m; i++) {
//        for (int j = 0; j<=n; j++) cout << L[i][j] << " ";
//        cout << endl;
//    }
                          
    int ans = L[m][n];
    for (int i = 0; i<=m; i++)
        delete [] L[i];
    delete [] L;

    return ans;
}

double similarity(string s1, string s2) { // 0 <= similarity <= 1
    return 1  - (double) DamerauLevenshteinDistance(s1, s2)
             / ((double) max(s1.length(), s2.length()));
}

double suitability(string s1, string s2) { //0 <= suitability <= 1; 1 if s1 contains s2 or s2 contains s1
    double DLD = DamerauLevenshteinDistance(s1, s2);
    if (DLD == 0) return numeric_limits<double>::max();

    return abs((double) s1.length() - s2.length()) / DLD;
}

string getFirstName(string fullName) {
    normalizeFullName(fullName);
    int n = fullName.length() - 1;
    string ans;

    while (n > 0 && fullName[n] != ' ')
        ans.push_back(fullName[n--]);

    reverse(ans.begin(), ans.end());
    return ans;
}

string getTitle(string fullName, int type, int gender) {
    if (type == STUDENT) return getFirstName(fullName);
    return (gender == MALE ? "Mr. ": "Mrs. ") + getFirstName(fullName);
}

bool isStrongPassword(string password) {
    if (password.length() < 8) return false;

    bool lower = false, upper = false,
         special = false, forbidden = false, number = false;

    for (int i = 0; i<password.size(); i++) {
        if (password[i] >= 'a' && password[i] <= 'z')
            lower = true;
        else if (password[i] >= 'A' && password[i] <= 'Z')
            upper = true;
        else
            special = true;

        if (password[i] == '`')
            forbidden = true;
    }

    return (lower && upper && special && !forbidden);
}

string getGreeting() {
    Time cur;

    int h = cur.h;

    if (h >= 6 && h < 12)
        return "Good morning, ";
    else if (h >= 12 && h < 17)
        return "Good afternoon, ";
    else if (h >= 17 && h < 20)
        return "Good evening, ";
    else
        return "Good night, ";
}

string getHashedPassword(string password) {
    //hashing password using PBKDF2 with 10000 iterations of HMAC-SHA256

//    const int keyLen = 50;
//    string ans;
//
//    cppcrypto::hmac hmac(cppcrypto::sha256(), password);
//    unsigned char *key = new unsigned char [keyLen];
//    pbkdf2(hmac, (const unsigned char*)"Untitled_APCS_2020", 18, 20000, key, sizeof(unsigned char) * keyLen);
//
//    unsigedCharToHexString(key, keyLen, ans);
//    delete [] key;
//    return ans;

//    const unsigned int keyLen = 50;
//    unsigned char key[keyLen];
//    const char *pass = password.c_str();
//    PKCS5_PBKDF2_HMAC(pass, keyLen, (const unsigned char*)"Untitled_APCS_2020", 18, 20000, EVP_sha256(), keyLen, key);
////    for (unsigned int i = 0; i < sizeof(key); i++)
////    {
////        sprintf(hexResult + (i * 2), "%02x", 255 & digest[i]);
////        binResult[i] = digest[i];
////    };
//
//    for (int i = 0; i<keyLen; i++)
//        cout << key[i] << endl;

    return password;
}

void unsigedCharToHexString(unsigned char *key, int keyLen, string &ans) {
    //convert base-256 to hexadecimal

    char *digit = new char [16];
    for (int i = 0; i<10; i++) digit[i] = i + '0';
    for (int i = 10; i<16; i++) digit[i] = i - 10 + 'A';

    ans.resize(2*keyLen);
    for (int i = 0; i<keyLen; i++) {
        ans[2*i] = digit[(int) key[i] % 16];
        ans[2*i+1] = digit[(int) key[i] / 16];
    }
}

string getCheckInCode(string semesterID, string classID, string courseID, int week) {
    normalize(semesterID);
    normalize(classID);
    normalize(courseID);

    string ans = getHashedPassword(semesterID + classID + courseID + to_string(week));
    ans.erase(6, ans.length() - 6);
    return ans;
}

void exitProgram(int code) {
    cout << "\n\nOops! Something went wrong. The program will be terminated. If not, please close the program and restart "
         << "it later, or the system files would be damaged. (Exit code: "<< code << ") [enter]\n";

    char keyPress = cin.get();
    fflush(stdin);
    cout << "\n\n";
}
