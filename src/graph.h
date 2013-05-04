/**
 * @file graph.h
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

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <cstring>
#include <queue>

#include "console.h"
#include "priorityqueue.h"

using namespace std;

class Graph
{
public:
    double** adjacencyMatrix;
    int size;

    Graph(int size);
    ~Graph();
    void init();
    void printMatrixToScreen();
    Graph* clone();
private:
    
    static int WHITE;
    static int GRAY;
    static int BLACK;
};

#endif // GRAPH_H
