#include <iostream>
template <typename T>

class Disjoint{
	private:
	struct set{
		T head;
		linkedList<T> childs;
		
	};
	
	linkedList<struct set*> listSet;
	
	public:
	int lenght = 0;// cuenta la cantidad de sets
	
	Disjoint(){
		
	}
	
	void addSet(T elem){
		struct set* newSet = (struct set*) malloc(sizeof(struct set));;
		newSet -> head = elem;
		listSet.add(newSet);
	}
	
	//void addElement(int index, int elem){}
	
	//void removeSet(int index){}
	
	//void join(int set1, int set2){}
	
	//bool areJoined(int set1, int set2){}
	
	//int findSet(T obj){}
	
	//bool isEmpty(){}
	
	//void clear(){}
	
	//void printSet(int index){}
	
	//void print(){}
	
};
