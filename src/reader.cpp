#include "reader.h"

Reader::Reader(){
}

/**
 * Método responsável por validar o nome do arquivo bem como as extensões
 * suportadas pelo programa
 */
bool Reader::isValidFileName(string fileName){
    if(fileName.size() == 0){
        Console::print("ERRO: Por favor, selecione um arquivo");
        return false;
    }

    if( ! Strings::endsWith(fileName,".g") && ! Strings::endsWith(fileName,".txt")){
        Console::print("ERRO: Por favor, selecione um arquivodo tipo <*.txt> or <*.g>");
        return false;
    }

    return true;
}

/**
 * Método usado para validar a primeira linha do arquivo contendo
 * informações sobre o grafo.
 */
bool Reader::isValidHeader(string line){
    int size = atoi(line.c_str());

    if(size <= 0){
        Console::print("ERRO: O cabeçalho deve ser um inteiro > 0 e não pode ter letras");
        return false;
    }

    return true;
}

/**
 * Método utilizado para validar as aretas escritas no arquivo.
 * Nesse caso, a aresta será composta pelo vertice inicial, vertice final
 * e peso da arestas (ambas as informações devem está separadas por "espaço"
 */
bool Reader::isValidEdge(string line,int size){
    vector<string> v = Strings::split(line," ");

    if(v.size() != 3){
        Console::print("ERRO: O arquivo não está no formato. Linha: '"+line+"'");
        return false;
    }

    int startNode = atoi(v[0].c_str());
    int destinationNode = atoi(v[1].c_str());
    int value = atoi(v[2].c_str());

    if(startNode <= 0 || startNode > size || destinationNode <= 0 || destinationNode > size || value <= 0){
        Console::print("ERRO: O arquivo não está no formato. Linha: '"+line+"'");
        return false;
    }

    return true;
}

/**
 * Método utilizado para ler uma instância que deverá ter a extensão .g ou .txt
 */
Graph* Reader::fromTXTorG(string fileName){
    if( ! isValidFileName(fileName)){
        return NULL;
    }

    ifstream myReadFile;
    Graph* graph = NULL;

    myReadFile.open(Strings::convertStringToChar(fileName));

    if (myReadFile.is_open()) {
        string line;

        //Ler o cabeçalho do arquivo contendo informações sobre 
		//a quantidade de vertices
        getline(myReadFile,line);

        if( ! isValidHeader(line)){
            return NULL;
        }

        int size = atoi(line.c_str());
        graph = new Graph(size);

        //Ler as arestas do grafo
        while ( ! myReadFile.eof()) {
            getline(myReadFile,line);

            if( ! line.empty()){
                if( ! isValidEdge(line,size)){
                    return NULL;
                }

                vector<string> v = Strings::split(line," ");

                int startNode = atoi(v[0].c_str());
                int destinationNode = atoi(v[1].c_str());
                int value = atoi(v[2].c_str());

                graph->adjacencyMatrix[startNode-1][destinationNode-1] = value;
            }
        }
    }else{
        Console::print("ERRO: O arquivo '"+fileName+"' não foi encontrado");
    }

    myReadFile.close();

    return graph;
}
