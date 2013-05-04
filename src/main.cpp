/**
 * @file main.cpp
 * @author  Thiago Nascimento
 * @version 1.0
 *
 * @section LICENSE
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details at
 * http://www.gnu.org/copyleft/gpl.html
 *
 * @section DESCRIPTION
 *
 * Classe principal do programa
 */

#include <iostream>
#include "console.h"
#include "graph.h"
#include "export.h"
#include "reader.h"
#include "dijkstra.h"
#include "prim.h"
#include "bfs.h"
#include "dfs.h"

using namespace std;

Graph* graph = NULL;

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
        Console::print("ERROR: Please, read a file. Use 'read <filename.g> | <filename.txt>'");
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
	if(graph != NULL){
        Export::toDot(graph);
    }else{
		Console::print("ERROR: Please, read a file. Use 'read <filename.g> | <filename.txt>'");
	}
}

/**
 * Classe utilizada para executar o algoritmo Depth-First Search no
 * grafo carregado pelo usuario. Para executar esse algoritmo, você deve
 * obrigatoriamente passar um vertice inicial.
 */
void dfs(int vertex){
    if(graph != NULL){
		DFS* dfs = new DFS(graph);
        dfs->run(vertex);
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
		BFS* bfs = new BFS(graph);
        bfs->run(vertex);
    }else{
        Console::print("ERROR: Please, read a file. Use 'read <filename.g> | <filename.txt>'");
    }
}

/**
 * Método responsável por executar o algoritmo de PRIM em um grafo previamente carregado
 */
void mst(string fileName){
    if(graph != NULL){
		Prim* p = new Prim(graph);
		p->run(fileName);
    }else{
        Console::print("ERROR: Please, read a file. Use 'read <filename.g> | <filename.txt>'");
    }
}

void dijkstra(int startVertex,int endVertex){
	if(graph != NULL){
		Dijkstra* d = new Dijkstra(graph);
        d->run(startVertex-1,endVertex-1);
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
            Console::help();
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
        }else if(v[0] == "mst"){
            mst(v[1]);
        }else{
            wrong = true;
        }
    }else if(v.size() == 3){
		if(v[0] == "sp"){
           dijkstra(atoi(v[1].c_str()),atoi(v[2].c_str()));
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
    return Strings::trim(command);
}

int main()
{
    Console::init();

	//O laço será encerrado quando o comando "exit" for digitado pelo usuário.
	while(true){
		string command = waitUserCommand();

		//Comando vazios não devem ser tratados e um novo comando deve ser solicitado
		if(command.size() == 0){
			continue;
		}

		//Quebramos a string digitada pelo usuario para validar a sua entrada.
		vector<string> v = Strings::split(command);

		//Com os comando disponíveis, alguma ação será tomada
		doSomething(v);
	}
	return 0;
}
