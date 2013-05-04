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
