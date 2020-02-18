#include <iostream>
template <typename T>

class linkedList{
	
	public:
	
	struct element{
		T obj;
		struct element* next = NULL;
	};
	
	struct element* pri = NULL;
	int lenght = 0;
	
	linkedList(){// Constructor of 0 obj
		pri = NULL; // hacerla usando 'linkedList<T> newList;'
		lenght = 0;
	}
	
	linkedList(T obj){// Constructor of 1 obj
		pri = (struct element*) malloc(sizeof(struct element));
		pri -> obj = obj;
		lenght = 1;
	}
	
	void add(T obj){// falta hacer add with index
		struct element* aux = pri;
		if(aux == NULL){
			pri = (struct element*) malloc(sizeof(struct element));
			pri -> obj = obj;
			lenght = 1;
		}else{
			while(aux -> next != NULL) aux = aux -> next;
			aux -> next = (struct element*) malloc(sizeof(struct element));
			aux -> next -> obj = obj;
			lenght++;
		}
	}
	
	void print(){
		struct element* aux = pri;
		std::cout << "[";
		while(aux != NULL && aux -> next!= NULL){
			std::cout << aux -> obj << ", ";
			aux = aux -> next;
		}
		if(aux != NULL) std::cout << aux -> obj;
		std::cout << "]" << std::endl;
	}
	
	T get(int index){
		if(index < 0 || index >= lenght) throw std::runtime_error("Invalid Index.");
		struct element* aux = pri;
		while(index != 0){
			aux = aux -> next;
			index--;
		}
		return aux -> obj;
	}
	
	void set(int index, T obj){
		if(index < 0 || index >= lenght) throw std::runtime_error("Invalid Index.");
		struct element* aux = pri;
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
			struct element* aux1 = pri;
			struct element* aux2 = pri;
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
	
	bool remove(T obj, bool all = false){
		bool res = false;
		struct element* aux = pri;
		while(aux == pri && aux != NULL && (all == true || res == false)){
			if(aux -> obj == obj){
				pri = aux -> next;	
				lenght--;
				res = true;
			}
			aux = aux -> next;
		}
		aux = pri;
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
		struct element* aux = pri;
		if(index == 0){
			obj = pri -> obj;
			pri = pri -> next;
			
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
	
	T pop(){
		T obj;
		struct element* aux = pri;
		if(pri != NULL){
			if(pri -> next == NULL){
				obj = pri -> obj;
				pri = NULL;
			}else{
				while(aux -> next -> next != NULL){
					aux = aux -> next;
				}
				obj = aux -> next -> obj;
				aux -> next  = NULL;
			}
			lenght--;
		}
		return obj;
	}
	
	T popFirst(){
		T obj;
		if(pri != NULL){
			obj = pri -> obj;
			if(pri -> next == NULL){
				pri = NULL;
			}else{
				pri = pri -> next;
			}
			lenght--;
		}
		return obj;
	}
	
	int indexOf(T obj){
		int res = 0;
		struct element* aux = pri;
		while(aux != NULL && aux -> obj != obj){
			res++;
			aux = aux -> next;
		}
		return res == lenght ? -1 : res;
	}
	
	void clear(){ // elimina toda la lista
		pri = NULL;
		lenght = 0;
	}
	
};


