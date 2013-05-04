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
    void depthFirstSearch(int vertex);
    Graph* clone();
private:
    void dfs(int position,int* color);

    static int WHITE;
    static int GRAY;
    static int BLACK;
};

#endif // GRAPH_H
