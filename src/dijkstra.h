/**
 * @file dijkstra.h
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
#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include "graph.h"

using namespace std;

class Dijkstra{
public:
    Dijkstra(Graph* g);
    void run(int startVertex,int endVertex);
private:
	int extractmin(priorityqueue* q,int* d);
	void relax(int u,int v);
	void initializeSingleSource(int startVertex);
	int w(int u,int v);
	
	Graph* graph;
	int* d;
	int* pi;
	vector<int> S;
};

#endif // DIJKSTRA_H
