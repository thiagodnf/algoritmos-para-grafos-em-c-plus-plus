#ifndef READER_H_
#define READER_H_

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

class Reader {

	public:
		static Graph* fromTXT(string fileName);
		
 };
 
 #endif /* READER_H_ */
