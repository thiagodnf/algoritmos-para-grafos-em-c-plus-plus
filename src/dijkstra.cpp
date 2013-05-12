#include "dijkstra.h"

Dijkstra::Dijkstra(Graph* g){
	this->graph = g;
}

/*
 * INITIALIZE-SINGLE-SOURCE(G,s)
 * */
void Dijkstra::initializeSingleSource(int startVertex){
	d = new int[graph->size];
	pi = new int[graph->size];
	
	for(int i=0;i<graph->size;i++){
		d[i] = 99999999;
		pi[i] = -1;
	}
	
	d[startVertex] = 0;
}

/*
 * Executa o algoritmo
 */
void Dijkstra::run(int startVertex,int endVertex){
	initializeSingleSource(startVertex);
	
	priorityqueue* q = new priorityqueue();
	for(int i=0;i<graph->size;i++){
        q->add(i,d[i]);
    }
    
    while( ! q->empty()){
		int u = extractmin(q,d);
		S.push_back(u);
		for(int v=0;v<graph->size;v++){
			if(graph->adjacencyMatrix[u][v] != 0){
				relax(u,v);
			}
		}
	}
	
	//Monta a sequencia de vertices
	vector<int> ans;
	int end = endVertex;
	ans.push_back(end+1);
	while (pi[end] != -1) {
		ans.push_back(pi[end]+1);
		end = pi[end];
	}
	
	//Imprime na tela a resposta
    vector<int> answer;
	int pathSize = d[endVertex];
	int size = (int) ans.size();
	for(int i=size-1;i>=0;i--){
    	answer.push_back(ans[i]);
	}
	
	Console::print(pathSize,answer);	
}

/**
 * Extrai da fila de prioridade o vertice que possui a menor distancia
 */
int Dijkstra::extractmin(priorityqueue* q,int* d){
	for(int i=0;i<q->size();i++){
		q->setPriority(q->get(i),d[q->get(i)]);
	}
	return q->pop();
}

int Dijkstra::w(int u,int v){
	return graph->adjacencyMatrix[u][v];
}

void Dijkstra::relax(int u,int v){
	if(d[v] > d[u]+w(u,v)){
		d[v] = d[u]+w(u,v);
		pi[v] = u;
	}
}
