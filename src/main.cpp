#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include "graph.cpp"
#include "string.cpp"
#include "reader.cpp"

Graph* graph = NULL;

void init(){
	Console::init();
}

void help(){
	Console::help();
}

void clear(){
	delete graph;
	graph = NULL;
}

void print(){
	if(graph != NULL){
		graph->printMatrixToScreen();
	}else{
		Console::print("ERROR: Please, read a file.");
	}
}

void read(string fileName){
	graph = Reader::fromTXTorG(fileName);
}

void dfs(int position){
	if(graph != NULL){
		graph->depthFirstSearch(position);
	}else{
		Console::print("ERROR: Please, read a file. Use 'read <filename.g> | <filename.txt>'");
	}
}

void doSomething(vector<string> v){
	bool wrong = false;

	if(v.size() == 1){
		if(v[0] == "clear"){
			clear();
		}else if(v[0] == "exit"){
			exit(EXIT_SUCCESS);
		}else if(v[0] == "print"){
			print();
		}else if(v[0] == "help"){
			help();
		}else{
			wrong = true;
		}
	}else if(v.size() == 2){
		if(v[0] == "read"){
			read(v[1]);
		}else if(v[0] == "dfs"){
			dfs(atoi(v[1].c_str()));
		}else{
			wrong = true;
		}
	}else{
		wrong = true;
	}
	
	if(wrong){
		Console::print("ERROR: Invalid Command");
	}
}

string waitUserCommand(){
	string command = "";
	cout<<">> ";
	getline(cin, command);
	
	return String::trim(command);
}

int main(){
	init();
	
	while(true){
		string command = waitUserCommand();
		
		if(command.size() == 0){
			continue;	
		}
		
		vector<string> v = String::split(command);	
		
		doSomething(v);
	}
	return 0;
}

