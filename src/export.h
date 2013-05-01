#ifndef EXPORT_H
#define EXPORT_H

#include <fstream>

#include "graph.h"

class Export
{
public:
    Export();
    static void toDot(Graph* graph);
    static void fromVectorToGraphFile(string fileName,Graph* graph,int* vector);
};

#endif // EXPORT_H
