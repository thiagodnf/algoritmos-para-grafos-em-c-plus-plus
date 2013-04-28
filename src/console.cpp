#include "console.h"

void Console::print(string s){
	cout<<endl;
	cout<<"\t"<<s<<endl;
	cout<<endl;
}

void Console::print(string s){
	print(String::convertStringToChar(fileName));
}