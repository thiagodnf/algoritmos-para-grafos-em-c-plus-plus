#include "export.h"

Export::Export(){
}

/**
 * Exporta o grafo graph passado como parametro para o formato .dot onde você
 * pode posteriormente utilizar o Graphviz para plotar em um .png.
 */
void Export::toDot(Graph* graph){
    if(graph == NULL){
        Console::print("ERRO: Por favor, leia um arquivo antes. Use 'read <filename.g> | <filename.txt>'");
        return;
    }

    ofstream myFile;

    Graph* g = graph->clone();
    vector<string> subGraph;
    vector<string> subGraphDir;

    //Inicialmente, separamos as arestas das direcionadas e das não-direcionadas.
    for(int i=0;i<g->size;i++){
        for(int j=0;j<g->size;j++){
            if(g->adjacencyMatrix[i][j] != 0){
                if(g->adjacencyMatrix[j][i] != 0){
                    subGraph.push_back(string(Strings::convertIntToString(i+1)+"->"+Strings::convertIntToString(j+1)+";"));
                    g->adjacencyMatrix[j][i] = 0;
                }else{
                    subGraphDir.push_back(string(Strings::convertIntToString(i+1)+"->"+Strings::convertIntToString(j+1)+";"));
                }
                g->adjacencyMatrix[i][j] = 0;
            }
        }
    }

    //Com a separação feita, as arestas serão agora escritas no arquivo.
    myFile.open ("out/example.dot");
    myFile<<"digraph{"<<endl<<"\t";
    for(int i=0;i<g->size;i++){
        myFile<<i+1<<";";
    }
    myFile<<endl;
	
	//Inicialmente, as arestas não-direcionadas
    myFile<<"\t"<<"subgraph dig {"<<endl<<"\t";
    myFile<<"\t"<<"edge [dir=none, color=black]"<<endl;
    for(unsigned int i=0;i<subGraph.size();i++){
        myFile<<subGraph[i]<<endl;
    }
    myFile<<"\t"<<"}"<<endl<<endl;

    //Logo após, somente as arestas direcionadas serão escritas
    myFile<<"\t"<<"subgraph g {"<<endl<<"\t";
    for(unsigned int i=0;i<subGraphDir.size();i++){
        myFile<<subGraphDir[i]<<endl;
    }
    myFile<<"\t"<<"}"<<endl<<"}"<<endl;
	
    myFile.close();
}

void Export::fromVectorToGraphFile(string fileName,Graph* graph,int* vector){
	if(graph == NULL || graph->size == 0){
		Console::print("ERRO: Por favor, leia um arquivo antes. Use 'read <filename.g> | <filename.txt>'");
		return;
	}
	
	if(fileName.empty()){
		Console::print("ERRO: Por favor, escreva o nome do arquivo de saída'");
		return;
	}
	
    ofstream file;
    file.open (Strings::convertStringToChar(string("out/")+fileName));

    //Cria o cabeçalho do arquivo
    file<<Strings::convertIntToString(graph->size)<<endl;

    //Cria as arestas do grafo. Nesse caso, ele cria tanto a aresta indo como
	//voltando, ou seja, x->y e y->x
    for(int i=1;i<graph->size;i++){
        string start = Strings::convertIntToString(i+1);
        string end = Strings::convertIntToString(vector[i]+1);
        double value = graph->adjacencyMatrix[i][vector[i]];
        string valueString = Strings::convertIntToString(value);
        file<<start<<" "<<end<<" "<<valueString<<endl;
		
		start = Strings::convertIntToString(vector[i]+1);
		end = Strings::convertIntToString(i+1);
		value = graph->adjacencyMatrix[vector[i]][i];
        valueString = Strings::convertIntToString(value);
		file<<start<<" "<<end<<" "<<valueString<<endl;
    }
    file.close();
	
	Console::print("Sucesso! Veja o arquivo de saida em out/"+fileName);
}
