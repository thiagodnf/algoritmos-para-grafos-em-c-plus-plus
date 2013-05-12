/**
 * @file dfs.h
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
#ifndef DFS_H
#define DFS_H

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include "graph.h"

using namespace std;

class DFS{
public:
    DFS(Graph* g);
    void run(int vertex);
	
private:
	void dfs(int position,vector<int>* answer);
	
	static int WHITE;
    static int GRAY;
    static int BLACK;
	
	int* color;
	Graph* graph;
};

#endif // DFS_H
