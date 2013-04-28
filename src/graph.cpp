#include "graph.h"

Graph::Graph(int size){
	this->size = size;
	this->adjacencyMatrix = new double*[size];
	
	for(int i=0;i<size;i++){
		this->adjacencyMatrix[i] = new double[size];
	}
	
	init();
}

void Graph::init(){
	if(adjacencyMatrix != NULL){
		for(int i=0;i<size;i++){
			for(int j=0;j<size;j++){
				adjacencyMatrix[i][j] = 0;
			}
		}
	}
}

Graph::~Graph(){
	for(int i=0;i<size;i++){
		delete adjacencyMatrix[i];
	}
	delete adjacencyMatrix;
}

void Graph::printMatrixToScreen(){
	if(adjacencyMatrix != NULL){
		cout<<endl;
		for(int i=0;i<size;i++){
			for(int j=0;j<size;j++){
				cout<<adjacencyMatrix[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}else{
		cout<<endl<<"    ERROR: Please, read a file."<<endl<<endl;
	}
}

void Graph::depthFirstSearch(int position){
	if(position <= 0 || position > size){
		cout<<endl<<"    ERROR in DFS: position should be between 1 and "<<size<<endl<<endl;
	}else{
		int* marked = new int[size];
		for(int i=0;i<size;i++){
			marked[i] = 0;
		}
		
		cout<<endl;
		dfs(position-1,marked);
		cout<<endl<<endl;
	}
}

void Graph::dfs(int position,int* marked){
	cout<<position+1<<" ";
	marked[position] = 1;
	for(int j=0;j<size;j++){
		if(adjacencyMatrix[position][j] != 0){
			if(marked[j] == 0){
				dfs(j,marked);
			}
		}
	}
}

Graph* Graph::clone(){
	Graph* g = new Graph(size);
	
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			g->adjacencyMatrix[i][j] = adjacencyMatrix[i][j];
		}
	}
	
	return g;
}


