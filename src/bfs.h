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
