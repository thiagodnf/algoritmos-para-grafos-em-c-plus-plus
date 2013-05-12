/**
 * @file console.h
 * @author  Thiago Nascimento
 * @version 1.0
 *
 * @section LICENSE
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details at
 * http://www.gnu.org/copyleft/gpl.html
 * 
 */

#ifndef CONSOLE_H
#define CONSOLE_H

#include <iostream>
#include <cstdio>
#include <iomanip>
#include "strings.h"

using namespace std;

class Console{
public:
    Console();
    static void print(int value);
    static void print(string s);
    static void print(const char* s);
	static void print(int* v,int size);
	static void print(int value,int* v,int size);
	static void print(vector<int> answer);
    static void init();
    static void help();
};

#endif // CONSOLE_H
