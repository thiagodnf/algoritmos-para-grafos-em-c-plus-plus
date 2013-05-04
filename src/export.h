/**
 * @file export.h
 * @author  Thiago Nascimento
 * @version 1.0
 *
 * @section LICENSE
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details at
 * http://www.gnu.org/copyleft/gpl.html
 * 
 */

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
