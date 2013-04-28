#ifndef READER_H_
#define READER_H_

#include <fstream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include "console.cpp"

class Reader {

public:
	static Graph* fromTXTorG(string fileName);
	
private:
	static bool isValidFileName(string fileName);
	static bool isValidHeader(string line);
	static bool isValidEdge(string line,int size);
		
	
 };
 
 #endif /* READER_H_ */
