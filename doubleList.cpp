#include <iostream>
template <typename T>

class doubleList{
	
	private:
	
	struct element{
		T obj;
		struct element* next = NULL;
		struct element* prev = NULL;
	};
	
	struct element* head = NULL;
	struct element* tail = NULL;
	
	public:
	int lenght = 0;
	
	doubleList(){// Constructor of 0 obj
		head = NULL; // hacerla usando 'linkedList<T> newList;'
		tail = NULL;
		lenght = 0;
	}
	
	doubleList(T obj){// Constructor of 1 obj
		head = (struct element*) malloc(sizeof(struct element));
		head -> obj = obj;
		tail = head;
		lenght = 1;
	}
	
	void addFirst(T obj){
		struct element* newElement = (struct element*) malloc(sizeof(struct element));
		newElement -> obj = obj;
		if(lenght == 0){
			head = newElement;
			tail = newElement;
		}else{
			newElement -> next = head;
			head -> prev = newElement;
			head = newElement;
		}
		lenght++;
	}
	
	void addLast(T obj){
		struct element* newElement = (struct element*) malloc(sizeof(struct element));
		newElement -> obj = obj;
		if(lenght == 0){
			head = newElement;
			tail = newElement;
		}else{
			newElement -> prev = tail;
			tail -> next = newElement;
			tail = newElement;
		}
		lenght++;
	}
	
	void add(T obj, int index){
		if(index < 0 || index > lenght) throw std::runtime_error("Invalid Index.");
		struct element* newElement = (struct element*) malloc(sizeof(struct element));
		newElement -> obj = obj;
		if(index == 0){
			if(lenght == 0){
				head = newElement;
				tail = newElement;
			}else{
				newElement -> next = head;
				head -> prev = newElement;
				head = newElement;
			}
		}else{
			if(index == lenght){
				newElement -> prev = tail;
				tail -> next = newElement;
				tail = newElement;
			}else{
				struct element* aux = head;
				if(index < lenght/2){
					aux = head;
					while(index != 1){
						aux = aux -> next;
						index--;
					}
				}else{
					aux = tail;
					while(index != lenght){
						aux = aux -> prev;
						index++;
					}
				}
				newElement -> next = aux -> next;
				aux -> next = newElement;
				newElement -> prev = aux;
				newElement -> next -> prev = newElement;
			}
		}
		lenght++;
	}
	
	T get(int index){
		if(index < 0 || index >= lenght) throw std::runtime_error("Invalid Index.");
		struct element* aux;
		if(index < lenght/2){
			aux = head;
			while(index != 0){
				aux = aux -> next;
				index--;
			}
		}else{
			aux = tail;
			while(index != lenght-1){
				aux = aux -> prev;
				index++;
			}
		}
		return aux -> obj;
	}
	
	void set(int index, T obj){
		if(index < 0 || index >= lenght) throw std::runtime_error("Invalid Index.");
		struct element* aux;
		if(index < lenght/2){
			aux = head;
			while(index != 0){
				aux = aux -> next;
				index--;
			}
		}else{
			aux = tail;
			while(index != lenght-1){
				aux = aux -> prev;
				index++;
			}
		}
		aux -> obj = obj;
	}
	
	void swap(int index1, int index2){
		if(index1 < 0 || index1 >= lenght) throw std::runtime_error("Invalid Index1.");
		if(index2 < 0 || index2 >= lenght) throw std::runtime_error("Invalid Index2.");
		if(index1 != index2){
			struct element* aux1;
			struct element* aux2;
			if(index1 < lenght/2){
				aux1 = head;
				while(index1 != 0){
					aux1 = aux1 -> next;
					index1--;
				}
			}else{
				aux1 = tail;
				while(index1 != lenght-1){
					aux1 = aux1 -> prev;
					index1++;
				}
			}
			if(index2 < lenght/2){
				aux2 = head;
				while(index2 != 0){
					aux2 = aux2 -> next;
					index2--;
				}
			}else{
				aux2 = tail;
				while(index2 != lenght-1){
					aux2 = aux2 -> prev;
					index2++;
				}
			}
			T objaux = aux1 -> obj;
			aux1 -> obj = aux2 -> obj;
			aux2 -> obj = objaux;
		}
	}
	
	T pop(){
		if(lenght <= 0) throw std::runtime_error("There are no elements in the list.");
		T obj;
		struct element* aux = tail;
		tail = aux -> prev;
		if(tail == NULL){
			head = NULL;
		}else{
			tail -> next = NULL;
			obj = aux -> obj;
		}
		lenght--;
		return obj;
	}
	
	T popFirst(){
		if(lenght <= 0) throw std::runtime_error("There are no elements in the list.");
		T obj;
		struct element* aux = head;
		head = aux -> next;
		if(head == NULL){
			tail = NULL;
		}else{
			head -> prev = NULL;
			obj = aux -> obj;
		}
		lenght--;
		return obj;
	}
	
	bool remove(T obj, bool all = false){
		bool res = false;
		struct element* aux = head;
		
		while(aux == head && aux != NULL && (all == true || res == false)){
			if(aux -> obj == obj){
				popFirst();
				res = true;
			}
			aux = aux -> next;
		}
		aux = head;
		while(aux != NULL && aux -> next != NULL && (all == true || res == false)){
			if(aux -> next -> obj == obj){
				aux -> next = aux -> next -> next;
				if(aux -> next == NULL){
					tail = aux;
				}else{
					aux -> next -> prev = aux;
				}
				lenght--;
				res = true;
			}
			if(all == false || (aux -> next != NULL && aux -> next -> obj != obj)) aux = aux -> next;
		}
		return res;
	}
	
	T removeAt(int index){
		if(index < 0 || index >= lenght) throw std::runtime_error("Invalid Index.");
		T obj;
		struct element* aux;
		if(lenght == 1){
			obj = head -> obj;
			head = NULL;
			tail = NULL;
		}else{
			if(index == 0){
				obj = head -> obj;
				head = head -> next;
				head -> prev = NULL;
			}else{
				if(index == lenght-1){
					obj = tail -> obj;
					tail = tail -> prev;
					tail -> next = NULL;
				}else{
					if(index < lenght/2){
						aux = head;
						while(index != 0){
							aux = aux -> next;
							index--;
						}
					}else{
						aux = tail;
						while(index != lenght-1){
							aux = aux -> prev;
							index++;
						}
					}
					obj = aux -> obj;
					aux -> next -> prev = aux -> prev;
					aux -> prev -> next = aux -> next;
				}
			}
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
		tail = NULL;
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
	
	void printBack(){// solo para pruebas
		struct element* aux = tail;
		std::cout << "[";
		while(aux != NULL && aux -> prev!= NULL){
			std::cout << aux -> obj << ", ";
			aux = aux -> prev;
		}
		if(aux != NULL) std::cout << aux -> obj;
		std::cout << "]" << std::endl;
	}
	
};
