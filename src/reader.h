#ifndef READER_H_
#define READER_H_

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include "console.cpp"

using namespace std;

class Reader {

public:
	static Graph* fromTXTorG(string fileName);
	
private:
	static bool isValidFileName(string fileName);
		
	
 };
 
 #endif /* READER_H_ */
