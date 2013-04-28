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

Graph* Reader::fromTXTorG(string fileName){
	if( ! isValidFileName(fileName)){
		return NULL;
	}

	ifstream myReadFile;
	Graph* graph = NULL;
	
 	myReadFile.open(String::convertStringToChar(fileName));
	
	if (myReadFile.is_open()) {
		string line;
		getline(myReadFile,line);
		
		int size = atoi(line.c_str());
		graph = new Graph(size);
		
		while ( ! myReadFile.eof()) {
			getline(myReadFile,line);
			if(line.size() != 0){
				vector<string> v = String::split(line," ");
				if(v.size() != 3){
					cout<<endl<<"\tERROR: File is not in the format"<<endl<<endl;	
					break;
				}
				
				int startNode = atoi(v[0].c_str())-1;
				int destinationNode = atoi(v[1].c_str())-1;
				int value = atoi(v[2].c_str());
				
				if(startNode < 0 || startNode > size || destinationNode < 0 || destinationNode > size){
					cout<<endl<<"\tERROR: File is not in the format"<<endl<<endl;	
					break;
				}
				
				graph->adjacencyMatrix[startNode][destinationNode] = value;
			}
		}
	}else{
		cout<<endl<<"\tERROR: File '"<<fileName<<"' not found"<<endl<<endl;
	}
	
	myReadFile.close();
	
	return graph;
}



