//
// Created by Duc An Chu on 5/26/20.
//

#include "AllRoles.h"

void logIn() {
    cout << "done";
}

void viewProfileInfo() {

}

void changePassword() {

}

void logOut() {

}

string getHashedPassword(string password) {
    //hashing password using PBKDF2 with 10000 iterations of HMAC-SHA256

    const int keyLen = 50;
    string ans;

    cppcrypto::hmac hmac(cppcrypto::sha256(), password);
    unsigned char *key = new unsigned char [keyLen];
    pbkdf2(hmac, (const unsigned char*)"Untitled_APCS_2020", 18, 20000, key, sizeof(unsigned char) * keyLen);

    unsigedCharToHexString(key, keyLen, ans);
    delete [] key;
    return ans;
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

void logInMenu() {
    cout << "Great to see you back! Have a nice day.\n";
    cout << "[any + enter] Login you account so that we can identify you, or\n";
    cout << "[ `  + enter] Exit the program if this is a mistake.\n";

    char keyPress = cin.get();
    cin.clear();

    if (keyPress != '`') {
        cout << endl;
        logIn();
    }
}

void logo() { // █
    cout << "\n";
    cout << " ██     ██   ███   ██   ████████   ██   ████████   ██        ███████   █████ \n";
    cout << " ██     ██   ████  ██      ██      ██      ██      ██        ██        ██  ██\n";
    cout << " ██     ██   ██ ██ ██      ██      ██      ██      ██        ███████   ██   ██\n";
    cout << "  ██   ██    ██  ████      ██      ██      ██      ██        ██        ██  ██ \n";
    cout << "    ███      ██   ███      ██      ██      ██      ███████   ███████   █████   \n";
    cout << "\n";
}