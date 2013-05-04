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
	void dfs(int position);
	
	static int WHITE;
    static int GRAY;
    static int BLACK;
	
	int* color;
	Graph* graph;
};

#endif // DFS_H
