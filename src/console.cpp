#include "console.h"

Console::Console()
{
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

void Console::init(){
    cout<<endl;
    cout<<"\t Universidade Estadual do Ceara"<<endl;
    cout<<"\t Mestrado Academico em Ciencia da Computacao"<<endl;
    cout<<"\t Projeto de Analise de Algoritmo 2013.1"<<endl;
    cout<<"\t By Thiago Nascimento"<<endl;
    cout<<endl;
    cout<<"\t Precisa de ajuda? Digite 'help'"<<endl;
    cout<<endl;
}

void Console::help(){
    cout<<endl;
    cout<<"\t read <filename.g> | <filename.txt> \t Ler um arquivo contendo um grafo"<<endl;
    cout<<"\t print \t Imprimir na tela matriz de adjacencias"<<endl;
    cout<<"\t dfs <vertice> \t Executar algoritmo DFS iniciando no vertice <vertice>"<<endl;
    cout<<endl;
}
