#include <iostream>
template <typename T>

class BinaryTree{
	private:
	struct Node{
		T value;
		struct Node* right = NULL;
		struct Node* left = NULL;
		int nodeNum = 1;
	};

	struct Node* head = NULL;
	
	public:
	int lenght = 0;// cuenta la cantidad de nodos
	
	BinaryTree(){// el prmer elemento es el numero 1
		head = (struct Node*) malloc(sizeof(struct Node));
		head -> nodeNum = 1;
		lenght = 0;
	}
	
	BinaryTree(T obj){
		head = (struct Node*) malloc(sizeof(struct Node));
		head -> value = obj;
		head -> nodeNum = 1;
		lenght = 1;

	}
	
	void addNode(T obj){
		lenght++;
		if(lenght == 1){
			head -> value = obj;
		}else{
			addNodeAux(obj, lenght, head);	
		}
		
	}

	T popNode(){
		if(lenght == 0) throw std::runtime_error("The tree is empty.");
		if(lenght == 1){
			T res = head -> value;
			head = (struct Node*) malloc(sizeof(struct Node));;
			lenght = 0;
			return res;
		}else{
			int l = lenght/2;
			return popNodeAux(lenght/2, l, head);	
		}
	}

	T getNode(int pos){
		if(pos <= 0 || pos > lenght) throw std::runtime_error("Invalid index.");
		return getNodeAux(pos, pos, head);	
	}

	void setNode(T val, int pos){
		if(pos <= 0 || pos > lenght) throw std::runtime_error("Invalid index.");
		setNodeAux(val, pos, pos, head);
	}

	int findNode(T obj){
		int res = -1;
		int cont = 1;
		Queue<struct Node*> TList;
		struct Node* aux;
		if(lenght > 0) TList.push(head);
		while(TList.lenght != 0 && res == -1){
			aux = TList.pop();
			if(aux -> left != NULL) TList.push(aux -> left);
			if(aux -> right != NULL) TList.push(aux -> right);
			if(aux -> value == obj) res = cont;
			cont++;
		}
		return res;
	}
	
	bool isEmpty(){
		return lenght == 0;
	}
	
	void clear(){
		head = (struct Node*) malloc(sizeof(struct Node));
		lenght = 0; 
	}
	
	void print(){ //BFS
		int cont = 2, limite = 2;
		Queue<struct Node*> TList;
		struct Node* aux;
		if(lenght > 0) TList.push(head);
		while(TList.lenght != 0){
			aux = TList.pop();
			std::cout << aux -> value << "  ";
			if(aux -> left != NULL) TList.push(aux -> left);
			if(aux -> right != NULL) TList.push(aux -> right);
			if(cont == limite){
				limite *= 2;
				std::cout << std::endl;
			}
			cont++;
		}
		std::cout << std::endl;
	}

	void preorder(){
		std::cout << "[ ";
		if(head != NULL) preorderAux(head);
		std::cout << "]" << std::endl;
	}

	void inorder(){
		std::cout << "[ ";
		if(head != NULL) inorderAux(head);
		std::cout << "]" << std::endl;
	}
	
	void posorder(){
		std::cout << "[ ";
		if(head != NULL) posorderAux(head);
		std::cout << "]" << std::endl;
	}

	private:

	int segundoBit(int& num){
		int mask = 1;
		int aux = num >> 2;
		while(mask <= aux) mask *= 2;
		int res = (mask & num) != 0;
		num -= mask; 
		return res;
	}

	void addNodeAux(T& obj, int pos, struct Node* nod){
		if(nod -> left == NULL || nod -> right == NULL){
			struct Node* newNode; //inserta el nodo
			if(nod -> left == NULL){
				nod -> left = (struct Node*) malloc(sizeof(struct Node));
				newNode = nod -> left;
			}else{
				if(nod -> right == NULL){
					nod -> right = (struct Node*) malloc(sizeof(struct Node));
					newNode = nod -> right;
				}
			}
			newNode -> value = obj;
			newNode -> nodeNum = lenght; 
		}else{
			if(segundoBit(pos) == 0){ //izquierda
				addNodeAux(obj, pos, nod -> left);
			}else{ //derecha
				addNodeAux(obj, pos, nod -> right);
			}
		}
	}

	T popNodeAux(int truePos, int& pos, struct Node* nod){
		if(truePos == nod -> nodeNum){
			lenght--;
			T res;
			if(nod -> right == NULL){
				res = nod -> left -> value;
				nod -> left = NULL;
			}else{
				res = nod -> right -> value;
				nod -> right = NULL;
			}
			return res;
		}else{
			if(segundoBit(pos) == 0){ //izquierda
				return popNodeAux(truePos, pos, nod -> left);
			}else{ //derecha
				return popNodeAux(truePos, pos, nod -> right);
			}
		}
	}

	T getNodeAux(int truePos, int& pos, struct Node* nod){
		if(truePos == nod -> nodeNum) return nod -> value;
		if(segundoBit(pos) == 0){ //izquierda
			return getNodeAux(truePos, pos, nod -> left);
		}else{ //derecha
			return getNodeAux(truePos, pos, nod -> right);
		}
	}

	void setNodeAux(T val, int truePos, int& pos, struct Node* nod){
		if(truePos == nod -> nodeNum){
			nod -> value = val;
		}else{
			if(segundoBit(pos) == 0){ //izquierda
				setNodeAux(val, truePos, pos, nod -> left);
			}else{ //derecha
				setNodeAux(val, truePos, pos, nod -> right);
			}		
		}
	}

	void preorderAux(struct Node* nod){
		std::cout << nod -> value << " ";
		if(nod -> left != NULL) preorderAux(nod -> left);
		if(nod -> right != NULL) preorderAux(nod -> right);
	}

	void inorderAux(struct Node* nod){
		if(nod -> left != NULL) inorderAux(nod -> left);
		std::cout << nod -> value << " ";
		if(nod -> right != NULL) inorderAux(nod -> right);
	}

	void posorderAux(struct Node* nod){
		if(nod -> left != NULL) posorderAux(nod -> left);
		if(nod -> right != NULL) posorderAux(nod -> right);
		std::cout << nod -> value << " ";
	}
};
