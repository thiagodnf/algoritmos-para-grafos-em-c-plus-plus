#include "export.h"

void Export::toDot(Graph* graph){
	if(graph == NULL){
		Console::print("ERROR: Please, read a file. Use 'read <filename.g> | <filename.txt>'");
		return;
	}
	
	ofstream myFile;
	
	Graph* g = graph->clone();
	vector<string> subGraph;
	vector<string> subGraphDir;
	
	//Separate data before write to file
	for(int i=0;i<g->size;i++){
		for(int j=0;j<g->size;j++){
			if(g->adjacencyMatrix[i][j] != 0){
				if(g->adjacencyMatrix[j][i] != 0){
					subGraph.push_back(string(String::convertIntToString(i+1)+"->"+String::convertIntToString(j+1)+";"));
					g->adjacencyMatrix[j][i] = 0;
				}else{
					subGraphDir.push_back(string(String::convertIntToString(i+1)+"->"+String::convertIntToString(j+1)+";"));
				}
				g->adjacencyMatrix[i][j] = 0;
			}
		}
	}
	
	//Now, the vectors will be write in the file
	myFile.open ("out/example.dot");
	myFile<<"digraph{"<<endl<<"\t";
	for(int i=0;i<g->size;i++){
		myFile<<i+1<<";";
	}
	myFile<<endl;
	myFile<<"\t"<<"subgraph dig {"<<endl<<"\t";
	myFile<<"\t"<<"edge [dir=none, color=black]"<<endl;
	for(unsigned int i=0;i<subGraph.size();i++){
		myFile<<subGraph[i]<<endl;
	}
	myFile<<"\t"<<"}"<<endl;
	
	myFile<<endl;
	myFile<<"\t"<<"subgraph g {"<<endl<<"\t";
	for(unsigned int i=0;i<subGraphDir.size();i++){
		myFile<<subGraphDir[i]<<endl;
	}
	myFile<<"\t"<<"}"<<endl;
	myFile<<"}"<<endl;
	myFile.close();
}