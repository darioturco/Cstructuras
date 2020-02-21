#include <iostream>
template <typename T>

class Stack{	
	private:
	struct element{
		T obj;
		struct element* next = NULL;
	};
	
	struct element* head = NULL;
	
	public:
	int lenght = 0;
	int max = -1;
	
	Stack(){// Constructor of 0 obj
		head = NULL; // hacerla usando 'Stack<T> newList;'
		lenght = 0;
	}
	
	Stack(T obj){// Constructor of 1 obj
		head = (struct element*) malloc(sizeof(struct element));
		head -> obj = obj;
		lenght = 1;
	}
	
	Stack(T obj, int m){// Constructor of 1 obj
		head = (struct element*) malloc(sizeof(struct element));
		head -> obj = obj;
		max = m;
		lenght = 1;
	}
	
	void push(T obj){
		if(max > 0 && lenght >= max) throw std::runtime_error("The stack is full.");
		struct element* newElement = (struct element*) malloc(sizeof(struct element));
		newElement -> obj = obj;
		newElement -> next = head;
		head = newElement;
		lenght++;
	}
	
	T pop(){
		if(lenght == 0) throw std::runtime_error("The stack is empty.");
		T res = head -> obj;
		head = head -> next;
		lenght--;
		return res;
	}
	
	T see(){
		if(lenght == 0) throw std::runtime_error("The stack is empty.");
		return head -> obj;
	}
	
	bool isEmpty(){
		return lenght == 0;
	}
	
	bool isFull(){
		return (max > 0 && max == lenght);
	}
	
	void clear(){ // elimina todo el stack
		head = NULL;
		lenght = 0;
	}
	
	void print(){ // Imprime el stack solo si T es imprimible
		struct element* aux = head;
		std::cout << "[";
		while(aux != NULL && aux -> next!= NULL){
			std::cout << aux -> obj << ", ";
			aux = aux -> next;
		}
		if(aux != NULL) std::cout << aux -> obj;
		std::cout << "]" << std::endl;
	}
	
};
