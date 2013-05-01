#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <iostream>
#include <vector>

using namespace std;

class priorityqueue
{
public:
        void add(int element,int priority);
        int pop();
        int size();
        bool empty();
        bool contains(int element);
    private:
        void sort();

        vector<int> elementVector;
        vector<int> priorityVector;
};

#endif // PRIORITYQUEUE_H
