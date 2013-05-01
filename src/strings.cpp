#include "strings.h"

Strings::Strings()
{
}

string Strings::trim(string s){
    s.erase(0, s.find_first_not_of(' ')); //prefixing spaces
    s.erase(s.find_last_not_of(' ')+1);   //surfixing spaces
    s.erase(0, s.find_first_not_of('\t')); //prefixing spaces
    s.erase(s.find_last_not_of('\t')+1);   //surfixing spaces
    return s;
}

char* Strings::convertStringToChar(string s){
    char *a = new char[s.size()+1];
    a[s.size()]=0;
    memcpy(a,s.c_str(),s.size());
    return a;
}

string Strings::convertIntToString(int value){
    char*  c = new char[value];
    sprintf(c, "%d", value);
    return string(c);
}

vector<string> Strings::split(string command,const char* delimiter){
    char * pch = NULL;
    pch = strtok (convertStringToChar(command),delimiter);

    vector<string> result;

    while (pch != NULL){
        result.push_back(string(pch));
        pch = strtok (NULL, delimiter);
    }
    return result;
}

/**
 * This method returns true if the character sequence represented by the argument
 * is a suffix of the character sequence represented by s; false otherwise.
 */
bool Strings::endsWith(string s,string suffix){
    if (s.length() >= suffix.length()) {
        return (0 == s.compare (s.length() - suffix.length(), suffix.length(), suffix));
    } else {
        return false;
    }
}
