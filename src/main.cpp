#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include "graph.cpp"
#include "string.cpp"
#include "reader.cpp"

Graph* graph = NULL;

void init(){
	cout<<endl;
	cout<<"\t Universidade Estadual do Ceara"<<endl;
	cout<<"\t Mestrado Academico em Ciencia da Computacao"<<endl;
	cout<<"\t Projeto de Analise de Algoritmo 2013.1"<<endl;
	cout<<"\t Equipe:"<<endl;
	cout<<"\t\t Robert Marinho:"<<endl;
	cout<<"\t\t Thiago Nascimento:"<<endl;
	cout<<endl;
	cout<<"\t Para ver comandos disponiveis, digite:"<<endl;
	cout<<"\t\t help:"<<endl;
	cout<<endl;
}

void help(){
	cout<<endl;
	cout<<"\t read <filename.g> | <filename.txt> \t Ler um arquivo contendo um grafo"<<endl;
	cout<<"\t print \t Imprimir na tela matriz de adjacencias"<<endl;
	cout<<"\t dfs <vertice> \t Executar algoritmo DFS iniciando no vertice <vertice>"<<endl;
	cout<<endl;
}

void clear(){
	delete graph;
	graph = NULL;
}

void print(){
	if(graph != NULL){
		graph->printMatrixToScreen();
	}else{
		cout<<endl<<"\t ERROR: Please, read a file."<<endl<<endl;
	}
}

void read(string fileName){
	graph = Reader::fromTXTorG(fileName);
}

void dfs(int position){
	if(graph != NULL){
		graph->depthFirstSearch(position);
	}else{
		cout<<endl<<"\t ERROR: Please, read a file."<<endl<<endl;
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
		cout<<endl<<"\t ERROR: Invalid Command"<<endl<<endl;
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

