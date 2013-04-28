#ifndef CONSOLE_H_
#define CONSOLE_H_

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

class Console {

public:
	static void print(string s);
	static void print(const char* s);
};
 
 #endif /* CONSOLE_H_ */
