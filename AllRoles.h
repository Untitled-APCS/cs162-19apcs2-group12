//
// Created by Duc An Chu on 5/26/20.
//

#ifndef CS162_19APCS2_GROUP12_ALLROLES_H
#define CS162_19APCS2_GROUP12_ALLROLES_H

#include "Optimization.h"
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

using namespace std;

void logIn(string &username, int &type);

void showMenu();

void viewProfileInfo(string &username, int type);

void changePassword(string &username, int type);

void logOut(string &username, int &type);

void unsigedCharToHexString(unsigned char *key, int keyLen, string &ans);

string getHashedPassword(string password);

#endif //CS162_19APCS2_GROUP12_ALLROLES_H
