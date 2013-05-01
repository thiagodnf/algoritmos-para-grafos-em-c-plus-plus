#include "priorityqueue.h"

void priorityqueue::add(int element,int priority){
    elementVector.push_back(element);
    priorityVector.push_back(priority);

    sort();
}


int priorityqueue::pop(){
    if(elementVector.size() == 0){
        return -1;
    }

    int value = elementVector[0];
    elementVector.erase (elementVector.begin());
    priorityVector.erase (priorityVector.begin());
    return value;
}

int priorityqueue::size(){
    return elementVector.size();
}

bool priorityqueue::empty(){
    return elementVector.size() == 0;
}

bool priorityqueue::contains(int element){
    for(unsigned int i=0;i<elementVector.size();i++){
        if(elementVector[i] == element){
            return true;
        }
    }
    return false;
}

void priorityqueue::sort(){
    for(unsigned int i=0;i<priorityVector.size();i++){
        for(unsigned int j=0;j<priorityVector.size()-1;j++){
            if(priorityVector[j] > priorityVector[j+1]){
                int a = priorityVector[j];
                priorityVector[j] = priorityVector[j+1];
                priorityVector[j+1] = a;

                int b = elementVector[j];
                elementVector[j] = elementVector[j+1];
                elementVector[j+1] = b;
            }
        }
    }
}

