#include "graph.h"

int Graph::WHITE = 1;
int Graph::GRAY = 2;
int Graph::BLACK = 3;
/**
 * Construtor da Classe
 */
Graph::Graph(int size){
    this->size = size;
    this->adjacencyMatrix = new double*[size];

    for(int i=0;i<size;i++){
        this->adjacencyMatrix[i] = new double[size];
    }

    init();
}

/**
 * Inicia os valores  da matriz para impedir que o programa
 * capture alguma sujeira na hora da execução
 */
void Graph::init(){
    if(adjacencyMatrix != NULL){
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                adjacencyMatrix[i][j] = 0;
            }
        }
    }
}

/**
 * Destrutor da Classe
 */
Graph::~Graph(){
    for(int i=0;i<size;i++){
        delete adjacencyMatrix[i];
    }
    delete adjacencyMatrix;
}

/**
 * Imprime da tela a matriz de adjancencias
 */
void Graph::printMatrixToScreen(){
    if(adjacencyMatrix == NULL){
        Console::print("ERROR: Please, read a file. Use 'read <filename.g> | <filename.txt>'");
        return;
    }
    cout<<endl<<"\t";
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            cout<<adjacencyMatrix[i][j]<<" ";
        }
        cout<<endl<<"\t";
    }
    cout<<endl;
}

/**
 * Cria um novo objeto baseado nos dados do atual. Ao final do proceso, será criado um
 * novo grafo idêntico nas Arestas e Vértices.
 */
Graph* Graph::clone(){
    Graph* g = new Graph(size);

    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            g->adjacencyMatrix[i][j] = adjacencyMatrix[i][j];
        }
    }

    return g;
}


