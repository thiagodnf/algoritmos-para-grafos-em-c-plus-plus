#include "priorityqueue.h"

void priorityqueue::add(int element,int priority){
    elementVector.push_back(element);
    priorityVector.push_back(priority);

    sort();
}

/**
 * Retorna o elemento com menor prioridade e remove
 * */
int priorityqueue::pop(){
    if(empty()){
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

void priorityqueue::setPriority(int element,int priority){
	for(unsigned int i=0;i<elementVector.size();i++){
		if(elementVector[i] == element){
			priorityVector[i] = priority;
		}
	}
	
	sort();
}

/**
 * O método de ordenação utilizado é o BubbleSort simples onde a verificação
 * é feita atravéz da prioridade.
 */
void priorityqueue::sort(){
    for(unsigned int i=0;i<priorityVector.size();i++){
        for(unsigned int j=0;j<priorityVector.size()-1;j++){
            if(priorityVector[j] > priorityVector[j+1]){
                int auxPri = priorityVector[j];
                priorityVector[j] = priorityVector[j+1];
                priorityVector[j+1] = auxPri;

                int auxEle = elementVector[j];
                elementVector[j] = elementVector[j+1];
                elementVector[j+1] = auxEle;
            }
        }
    }
}

int priorityqueue::get(int position){
	if(empty() || position < 0 || position >= size()){
		return -1;
	}
	
	return elementVector[position];
}

