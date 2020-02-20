#include <iostream>
template <typename T>

class linkedList{
	
	private:
	struct element{
		T obj;
		struct element* next = NULL;
	};
	
	struct element* head = NULL;
	
	public:
	int lenght = 0;
	
	linkedList(){// Constructor of 0 obj
		head = NULL; // hacerla usando 'linkedList<T> newList;'
		lenght = 0;
	}
	
	linkedList(T obj){// Constructor of 1 obj
		head = (struct element*) malloc(sizeof(struct element));
		head -> obj = obj;
		lenght = 1;
	}
	
	void add(T obj){// agrega en el ultimo lugar de la lista
		struct element* aux = head;
		if(aux == NULL){
			head = (struct element*) malloc(sizeof(struct element));
			head -> obj = obj;
		}else{
			while(aux -> next != NULL) aux = aux -> next;
			aux -> next = (struct element*) malloc(sizeof(struct element));
			aux -> next -> obj = obj;
		}
		lenght++;
	}
	
	void add(T obj, int index){
		if(index < 0 || index > lenght) throw std::runtime_error("Invalid Index.");
		struct element* aux = head;
		if(index == 0){
			aux = (struct element*) malloc(sizeof(struct element));
			aux -> obj = obj;
			aux -> next = head;
			head = aux;
		}else{
			while(index != 1){
				aux = aux -> next;
				index--;
			}
			struct element* newElement = (struct element*) malloc(sizeof(struct element));
			newElement -> obj = obj;
			newElement -> next = aux -> next;
			aux -> next = newElement;
		}
		lenght++;
	}
	
	T get(int index){
		if(index < 0 || index >= lenght) throw std::runtime_error("Invalid Index.");
		struct element* aux = head;
		while(index != 0){
			aux = aux -> next;
			index--;
		}
		return aux -> obj;
	}
	
	void set(int index, T obj){
		if(index < 0 || index >= lenght) throw std::runtime_error("Invalid Index.");
		struct element* aux = head;
		while(index != 0){
			aux = aux -> next;
			index--;
		}
		aux -> obj = obj;
	}
	
	void swap(int index1, int index2){
		if(index1 < 0 || index1 >= lenght) throw std::runtime_error("Invalid Index1.");
		if(index2 < 0 || index2 >= lenght) throw std::runtime_error("Invalid Index2.");
		if(index1 != index2){
			struct element* aux1 = head;
			struct element* aux2 = head;
			while(index1 != 0 || index2 != 0){
				if(index1 != 0){
					aux1 = aux1 -> next; 
					index1--;
				}
				if(index2 != 0){
					aux2 = aux2 -> next;
					index2--;
				}
			}
			T objTemp = aux1 -> obj;
			aux1 -> obj = aux2 -> obj;
			aux2 -> obj = objTemp;
		}
	}
	
	T pop(){		
		if(lenght <= 0) throw std::runtime_error("There are no elements in the list.");
		T obj = head -> obj;
		struct element* aux = head;
		if(head -> next == NULL){
			obj = head -> obj;
			head = NULL;
		}else{
			while(aux -> next -> next != NULL){
				aux = aux -> next;
			}
			obj = aux -> next -> obj;
			aux -> next  = NULL;
		}
		lenght--;
		return obj;
	}
	
	T popFirst(){
		if(lenght <= 0) throw std::runtime_error("There are no elements in the list.");
		T obj = head -> obj;
		obj = head -> obj;
		if(head -> next == NULL){
			head = NULL;
		}else{
			head = head -> next;
		}
		lenght--;
		return obj;
	}
	
	bool remove(T obj, bool all = false){
		bool res = false;
		struct element* aux = head;
		while(aux == head && aux != NULL && (all == true || res == false)){
			if(aux -> obj == obj){
				head = aux -> next;	
				lenght--;
				res = true;
			}
			aux = aux -> next;
		}
		aux = head;
		while(aux != NULL && aux -> next != NULL && (all == true || res == false)){
			if(aux -> next -> obj == obj){
				if(all == true){
					struct element* newPoint = aux -> next -> next;
					while(newPoint != NULL && newPoint -> obj == obj){
						lenght--;
						newPoint = newPoint -> next;
					}
					aux -> next = newPoint;
				}else{
					aux -> next = aux -> next -> next;
				}
				lenght--;
				res = true;
			}
			aux = aux -> next;
		}
		return res;
	}
	
	T removeAt(int index){
		if(index < 0 || index >= lenght) throw std::runtime_error("Invalid Index.");
		T obj;
		struct element* aux = head;
		if(index == 0){
			obj = head -> obj;
			head = head -> next;
			
		}else{
			while(index != 1){
				aux = aux -> next;
				index--;
			}
			obj = aux -> next -> obj;
			aux -> next = aux -> next -> next;
		}
		lenght--;
		return obj;
	}
	
	int indexOf(T obj){
		int res = 0;
		struct element* aux = head;
		while(aux != NULL && aux -> obj != obj){
			res++;
			aux = aux -> next;
		}
		return res == lenght ? -1 : res;
	}
	
	bool isEmpty(){
		return lenght == 0;
	}
	
	void clear(){ // elimina toda la lista
		head = NULL;
		lenght = 0;
	}
	
	void print(){ // Imprime la lista solo si T es imprimible
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


