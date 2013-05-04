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
