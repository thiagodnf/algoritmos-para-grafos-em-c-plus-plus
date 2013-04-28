#include "reader.h"

bool Reader::isValidFileName(string fileName){
	if(fileName.size() == 0){
		Console::print("ERROR: Please, select a file");
		return false;
	}
	
	if( ! String::endsWith(fileName,".g") && ! String::endsWith(fileName,".txt")){
		Console::print("ERROR: Please, select a file <*.txt> or <*.g>");
		return false;
	}
	
	return true;
}

bool Reader::isValidHeader(string line){
	int size = atoi(line.c_str());
	
	if(size <= 0){
		Console::print("ERROR: The Header should be an Integer > 0 and no letter");
		return false;
	}
	
	return true;
}

bool Reader::isValidEdge(string line,int size){
	vector<string> v = String::split(line," ");
	
	if(v.size() != 3){
		Console::print("ERROR: File is not in the format");
		return NULL;
	}
	
	int startNode = atoi(v[0].c_str());
	int destinationNode = atoi(v[1].c_str());
	int value = atoi(v[2].c_str());

	if(startNode <= 0 || startNode > size || destinationNode <= 0 || destinationNode > size || value <= 0){
		Console::print("ERROR: File is not in the format. Line: '"+line+"'");
		return NULL;
	}

	return true;
}

Graph* Reader::fromTXTorG(string fileName){
	if( ! isValidFileName(fileName)){
		return NULL;
	}

	ifstream myReadFile;
	Graph* graph = NULL;
	
 	myReadFile.open(String::convertStringToChar(fileName));
	
	if (myReadFile.is_open()) {
		string line;
		
		//Read Header
		getline(myReadFile,line);
		
		if( ! isValidHeader(line)){
			return NULL;
		}
		
		int size = atoi(line.c_str());
		graph = new Graph(size);
		
		//Read Edges
		while ( ! myReadFile.eof()) {
			//Read line
			getline(myReadFile,line);
			
			if(line.size() != 0){
				if(! isValidEdge(line,size)){
					return NULL;
				}
				
				vector<string> v = String::split(line," ");
				
				int startNode = atoi(v[0].c_str());
				int destinationNode = atoi(v[1].c_str());
				int value = atoi(v[2].c_str());
				
				graph->adjacencyMatrix[startNode-1][destinationNode-1] = value;
			}
		}
	}else{
		Console::print("ERROR: File '"+fileName+"' not found");
	}
	
	myReadFile.close();
	
	return graph;
}



