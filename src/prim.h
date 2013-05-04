/**
 * @file prim.h
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

#ifndef PRIM_H
#define PRIM_H

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include "graph.h"
#include "export.h"

using namespace std;

class Prim{
public:
    Prim(Graph* g);
    void run(string fileName);
private:
	
	Graph* graph;
};

#endif // PRIM_H
