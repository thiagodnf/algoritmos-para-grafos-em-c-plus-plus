#include "prim.h"

Prim::Prim(Graph* g){
	this->graph = g;
}

/*
 * Executa o algoritmo
 */
void Prim::run(string fileName){
	double* key = new double[graph->size];
    int* pi = new int[graph->size];
    priorityqueue* q = new priorityqueue();

    //Uma forma de representar u.key = infinito,
    //será somado todos os pesos de todas as aretas
    double sum = 0;
    for(int i=0;i<graph->size;i++){
        for(int j=0;j<graph->size;j++){
            sum += graph->adjacencyMatrix[i][j];
        }
    }
    //Inicialização das variáveis
    for(int i=0;i<graph->size;i++){
        key[i] = sum;
        pi[i] = -1;
    }
    //Para montar a arvore geradora mínima, o algoritmo
    //sempre irá iniciar pelo vertice 1 (ou 0).
    key[0] = 0;

    //Durante a execução do algoritmo, todos os vértices
    // que não estão na árvore estarão em uma fila de prioridade Q-min,
    //com base no atributo chave (Key).
    for(int i=0;i<graph->size;i++){
        q->add(i,key[i]);
    }

    //Para cada vértice v, o atributo key[v] é o peso mínimo de qualquer
    //aresta ligando v a algum vértice da árvore gerada
    while( ! q->empty()){
        int u = q->pop();
        for(int v=0;v<graph->size;v++){
            if(graph->adjacencyMatrix[u][v] != 0){
                if(q->contains(v) && graph->adjacencyMatrix[u][v] < key[v]){
                    pi[v] = u;
                    key[v] = graph->adjacencyMatrix[u][v];
                }
            }
        }
    }
    //No final do processo, o atributo pi[v] nomeia o pai de v na árvore.
    //Ou seja, se pi[2] = 1 então, o pai de 2 é 1 que está na árvore
	
	//Depois de encontrar a arvore, o resultado
    //será salvo em um arquivo de texto especificado pelo usuario
    Export::fromVectorToGraphFile(fileName,graph,pi);
}
