#ifndef READER_H
#define READER_H

#include <cstring>
#include <iostream>
#include <fstream>
#include <cstdlib>

#include "graph.h"

using namespace std;

class Reader{
public:
    Reader();
    static Graph* fromTXTorG(string fileName);
private:
    static bool isValidFileName(string fileName);
    static bool isValidHeader(string line);
    static bool isValidEdge(string line,int size);
};

#endif // READER_H
