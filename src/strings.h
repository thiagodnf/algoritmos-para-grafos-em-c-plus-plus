/**
 * @file strings.h
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
