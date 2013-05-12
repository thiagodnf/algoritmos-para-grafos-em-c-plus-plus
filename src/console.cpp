/**
 * @file console.cpp
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
 * Classe responsável por centralizar a impressão no console
 */

#include "console.h"

Console::Console(){
}

void Console::print(const char* s){
    cout<<endl;
    cout<<"\t"<<s<<endl;
    cout<<endl;
}

void Console::print(string s){
    print(Strings::convertStringToChar(s));
}

void Console::print(int value){
    char*  c = new char[value];
    sprintf(c, "%d", value);
    print(c);
}

void Console::print(int* v,int size){
	cout<<endl<<"\t";
	for(int i=0;i<size;i++){
		cout<<v[i]<<" ";
	}
	cout<<endl<<endl;
}

void Console::print(int value, vector<int> answer){
    cout<<endl;
    cout<<"\t"<<value<<endl;
	cout<<"\t";
	for(unsigned int i=0;i<answer.size();i++){
		cout<<answer[i]<<" ";
	}
	cout<<endl<<endl;
}

void Console::print(vector<int> answer){
    int* a = new int[answer.size()];
    
    for(unsigned int i=0;i<answer.size();i++){
        a[i] = answer[i];
    }
    print(a,(int)answer.size());
}

/**
 * Imprime na tela o cabeçalho do programa com informações sobre o autor
 * ou por exemplo o nome da instituição
 */
void Console::init(){
    cout<<endl;
    cout<<"\t Universidade Estadual do Ceara"<<endl;
    cout<<"\t Mestrado Academico em Ciencia da Computacao"<<endl;
    cout<<"\t Projeto de Analise de Algoritmo 2013.1"<<endl;
    cout<<"\t Autor: Thiago Nascimento"<<endl;
    cout<<endl;
    cout<<"\t Precisa de ajuda? Digite 'help'"<<endl;
    cout<<endl;
}

/**
 * Imprime na tela os comandos diponíveis no sistema.
 */
void Console::help(){
    cout<<endl;
	cout<<"\t"<<"todot"<<setw(74)<<"Imprimir no arquivo texto o grafo lido no formato DOT"<<endl;
	cout<<"\t"<<"help"<<setw(63)<<"Imprimir na tela os comandos disponíveis"<<endl;
	cout<<"\t"<<"print"<<setw(61)<<"Imprimir na tela a matriz de adjacencias"<<endl;
	cout<<"\t"<<"exit"<<setw(41)<<"Sair da aplicação"<<endl;
	cout<<"\t"<<"clear"<<setw(64)<<"Limpar da memória o ultimo grafo carregado"<<endl;
	cout<<"\t"<<"read <filename.(g|txt)>"<<setw(35)<<"Ler um arquivo contendo um grafo"<<endl;
	cout<<"\t"<<"dfs <vertex>"<<setw(67)<<"Executar algoritmo DFS iniciando no vertice <vertice>"<<endl;
	cout<<"\t"<<"bfs <vertex>"<<setw(67)<<"Executar algoritmo BFS iniciando no vertice <vertice>"<<endl;
	cout<<"\t"<<"mst <filename>"<<setw(96)<<"Imprime no arquivo texto a árvore gerada mínima iniciando pelo vertice <vertice>"<<endl;
	cout<<"\t"<<"sp <start> <end>"<<setw(63)<<"Imprime na tela o menor caminho de <start> até <end>"<<endl;
    cout<<endl;
	
}
