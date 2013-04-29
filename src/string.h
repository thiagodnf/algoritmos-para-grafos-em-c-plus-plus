#ifndef STRINGUTIL_H_
#define STRINGUTIL_H_

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

class String {

	public:
		static string trim(string s);
		static string convertIntToString(int value);
		static char* convertStringToChar(string s);
		static vector<string> split(string command,const char* delimiter = " ");  
		static bool endsWith(string s,string end);
 };
 
 #endif /* STRINGUTIL_H_ */
