#include "string.h"

string String::trim(string s){
	s.erase(0, s.find_first_not_of(' ')); //prefixing spaces
	s.erase(s.find_last_not_of(' ')+1);   //surfixing spaces
	s.erase(0, s.find_first_not_of('\t')); //prefixing spaces
	s.erase(s.find_last_not_of('\t')+1);   //surfixing spaces
	return s;
}

char* String::convertStringToChar(string s){
	char *a = new char[s.size()+1];
	a[s.size()]=0;
	memcpy(a,s.c_str(),s.size());
	return a;
}

vector<string> String::split(string command,const char* delimiter){
	char * pch = NULL;
  	pch = strtok (convertStringToChar(command),delimiter);

	vector<string> result;

	while (pch != NULL){
		string s(pch);
		result.push_back(s);
		pch = strtok (NULL, delimiter);
	}
	return result;
}

bool String::endsWith(string s,string end){
	if (s.length() >= end.length()) {
        return (0 == s.compare (s.length() - end.length(), end.length(), end));
    } else {
        return false;
    }
}



