#include <iostream>
template <typename T>

class Queue{	
	private:
	struct element{
		T obj;
		struct element* next = NULL;
	};
	
	struct element* head = NULL;
	
	public:
	int lenght = 0;
	
	Queue(){// Constructor of 0 obj
		head = NULL; // hacerla usando 'Stack<T> newList;'
		lenght = 0;
	}
	
	Queue(T obj){// Constructor of 1 obj
		head = (struct element*) malloc(sizeof(struct element));
		head -> obj = obj;
		lenght = 1;
	}
	
	void push(T obj){
		if(lenght == 0){
			head = (struct element*) malloc(sizeof(struct element));
			head -> obj = obj;
		}else{
			struct element* aux = head;
			while(aux -> next != NULL) aux = aux -> next;
			aux -> next = (struct element*) malloc(sizeof(struct element));
			aux -> next -> obj = obj;
		}
		lenght++;
	}
	
	T pop(){
		if(lenght == 0) throw std::runtime_error("The queue is empty.");
		T res = head -> obj;
		head = head -> next;
		lenght--;
		return res;
	}
	
	T see(){
		if(lenght == 0) throw std::runtime_error("The queue is empty.");
		return head -> obj;
	}
	
	bool isEmpty(){
		return lenght == 0;
	}
	
	void clear(){ // elimina todo el queue
		head = NULL;
		lenght = 0;
	}
	
	void print(){ // Imprime el queue solo si T es imprimible
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
