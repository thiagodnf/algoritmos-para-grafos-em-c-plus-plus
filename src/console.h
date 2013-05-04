#ifndef CONSOLE_H
#define CONSOLE_H

#include <iostream>
#include <cstdio>
#include "strings.h"

using namespace std;

class Console{
public:
    Console();
    static void print(int value);
    static void print(string s);
    static void print(const char* s);
	static void print(int* v,int size);
    static void init();
    static void help();
};

#endif // CONSOLE_H
