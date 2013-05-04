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
