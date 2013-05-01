#ifndef STRINGS_H
#define STRINGS_H

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

class Strings
{
public:
    Strings();
    static string trim(string s);
    static string convertIntToString(int value);
    static char* convertStringToChar(string s);
    static vector<string> split(string command,const char* delimiter = " ");
    static bool endsWith(string s,string end);
};

#endif // STRINGS_H
