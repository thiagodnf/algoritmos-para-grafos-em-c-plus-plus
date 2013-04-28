#include "console.h"

void Console::print(const char* s){
	cout<<endl;
	cout<<"\t"<<s<<endl;
	cout<<endl;
}

void Console::print(string s){
	print(String::convertStringToChar(s));
}

void Console::print(int value){
	char*  c = new char[value];
	sprintf(c, "%d", value);
	print(c);
}