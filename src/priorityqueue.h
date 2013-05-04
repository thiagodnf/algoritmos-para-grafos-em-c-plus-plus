/**
 * @file priorityqueue.h
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

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <iostream>
#include <vector>

using namespace std;

class priorityqueue{
public:
        void add(int element,int priority);
        int pop();
        int size();
        bool empty();
        bool contains(int element);
		void setPriority(int element,int priority);
		int get(int position);
    private:
        void sort();

        vector<int> elementVector;
        vector<int> priorityVector;
};

#endif // PRIORITYQUEUE_H
