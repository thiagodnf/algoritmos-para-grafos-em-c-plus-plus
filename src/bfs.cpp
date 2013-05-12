#include "bfs.h"

int BFS::WHITE = 1;
int BFS::GRAY = 2;
int BFS::BLACK = 3;

BFS::BFS(Graph* g){
	this->graph = g;
}

/*
 * Executa o algoritmo Breadth-First Search
 */
void BFS::run(int vertex){
	//Validação necessária para que o usuario não digite um vertice que
    //não exista
    if(vertex <= 0 || vertex > graph->size){
        Console::print("ERROR no algoritmo BFS: O vertice deve está entre 1 e "+Strings::convertIntToString(graph->size));
        return;
    }

    //Cria um vetor para marcar todos os vertices que foram visitados
    int* color = new int[graph->size];
    for(int i=0;i<graph->size;i++){
        color[i] = WHITE;
    }
    queue<int> q;
    q.push(vertex-1);
    color[vertex-1] = GRAY;
    vector<int> answer; 
    
    while ( ! q.empty()){
        int v = q.front(); q.pop();
        answer.push_back(v+1);
        //Percorre todos os vertices adjacentes a V que ainda não foram marcados
        for(int j=0;j<graph->size;j++){
            if(graph->adjacencyMatrix[v][j] != 0){
                if(color[j] == WHITE){
                    color[j] = GRAY;
                    q.push(j);
                }
            }
        }
        color[v] = BLACK;
    }
    
    Console::print(answer);
}
