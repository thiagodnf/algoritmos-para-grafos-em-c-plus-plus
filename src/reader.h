/**
 * @file reader.h
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

#ifndef READER_H
#define READER_H

#include <cstring>
#include <iostream>
#include <fstream>
#include <cstdlib>

#include "graph.h"

using namespace std;

class Reader{
public:
    Reader();
    static Graph* fromTXTorG(string fileName);
private:
    static bool isValidFileName(string fileName);
    static bool isValidHeader(string line);
    static bool isValidEdge(string line,int size);
};

#endif // READER_H
