/**
 * @file bfs.h
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
#ifndef BFS_H
#define BFS_H

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include "graph.h"

using namespace std;

class BFS{
public:
    BFS(Graph* g);
    void run(int vertex);
private:
	
	static int WHITE;
    static int GRAY;
    static int BLACK;
	Graph* graph;
};

#endif // BFS_H
