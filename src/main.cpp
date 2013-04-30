#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include "graph.cpp"
#include "string.cpp"
#include "reader.cpp"
#include "export.cpp"

Graph* graph = NULL;

/**
 * Imprime na tela o cabeçalho do programa com informações sobre o autor
 * ou por exemplo o nome da instituição
 */
void init(){
	Console::init();
}

/**
 * Imprime na tela os comandos diponíveis no sistema.
 */
void help(){
	Console::help();
}

/**
 * Elimina o grafo atual da seção
 */
void clear(){
	delete graph;
	graph = NULL;
}

/**
 * Imprime na tela a matriz de adjancencia do grafo que foi carregado pelo usuario
 */ 
void print(){
	if(graph != NULL){
		graph->printMatrixToScreen();
	}else{
		Console::print("ERROR: Please, read a file.");
	}
}

/**
 * Ler um arquivo do tipo .txt ou .g com informações sobre o grafo.
 * Para isso, a chamada deve ser "read <filename.(txt|g)>
 */
void read(string fileName){
	graph = Reader::fromTXTorG(fileName);
}

/**
 * Exporta o grafo atual para o formato .dot onde pode ser utilizado o programa Graphviz para 
 * gerar o .png do grafico.
 */
void toDot(){
	Export::toDot(graph);
}

/**
 * Classe utilizada para executar o algoritmo Depth-First Search no 
 * grafo carregado pelo usuario. Para executar esse algoritmo, você deve
 * obrigatoriamente passar um vertice inicial.
 */
void dfs(int vertex){
	if(graph != NULL){
		graph->depthFirstSearch(vertex);
	}else{
		Console::print("ERROR: Please, read a file. Use 'read <filename.g> | <filename.txt>'");
	}
}

/**
 * Classe utilizada para executar o algoritmo Breadth-First Search no 
 * grafo carregado pelo usuario. Para executar esse algoritmo, você deve
 * obrigatoriamente passar um vertice inicial.
 */
void bfs(int vertex){
	if(graph != NULL){
		graph->breadthFirstSearch(vertex);
	}else{
		Console::print("ERROR: Please, read a file. Use 'read <filename.g> | <filename.txt>'");
	}
}

/**
 * Metodo responsável por tratar todas as opções disponíveis no sistema.
 */
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
		}else if(v[0] == "todot"){
			toDot();
		}else{
			wrong = true;
		}
	}else if(v.size() == 2){
		if(v[0] == "read"){
			read(v[1]);
		}else if(v[0] == "dfs"){
			dfs(atoi(v[1].c_str()));
		}else if(v[0] == "bfs"){
			bfs(atoi(v[1].c_str()));
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

/**
 * Método responsável por exibir o cursor e aguardar algum comando do usuário
 */
string waitUserCommand(){
	string command = "";
	cout<<">> ";
	getline(cin, command);
	
	//Todo e qualquer entrada do usuario deve ser tratada
	return String::trim(command);
}

int main(){
	init();
	
	//O laço será encerrado quando o comando "exit" for digitado pelo usuário.
	while(true){
		string command = waitUserCommand();
		
		//Comando vazios não devem ser tratados e um novo comando deve ser solicitado
		if(command.size() == 0){
			continue;	
		}
		
		//Quebramos a string digitada pelo usuario para validar a sua entrada.
		vector<string> v = String::split(command);	
		
		//Com os comando disponíveis, alguma ação será tomada
		doSomething(v);
	}
	return 0;
}

