#ifndef GRAPH_H_
#define GRAPH_H_

#include <iostream>
#include <queue>
#include "console.h"
#include "string.h"

using namespace std;

class Graph {
	public:
		double** adjacencyMatrix;
		int size;
		
		Graph(int size);
		~Graph();
		void init();
		void printMatrixToScreen();
		void depthFirstSearch(int vertex);
		void breadthFirstSearch(int vertex);
		Graph* clone();
	private:
		void dfs(int position,int* marked);
 };
 
 #endif /* GRAPH_H_ */
