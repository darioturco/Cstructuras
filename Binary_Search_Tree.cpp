#include <iostream>
template <typename T>

class BinarySearchTree{
	private:
	struct Node{
		T value;
		struct Node* right = NULL;
		struct Node* left = NULL;
	};

	struct Node* head = NULL;
	
	public:
	int lenght = 0;// cuenta la cantidad de nodos
	
	BinarySearchTree(){
		head = (struct Node*) malloc(sizeof(struct Node));
		lenght = 0;
	}
	
	BinarySearchTree(T obj){
		head = (struct Node*) malloc(sizeof(struct Node));
		head -> value = obj;
		lenght = 1;
	}

	void addNode(T obj){
		if(lenght == 0){
			head -> value = obj;
		}else{
			struct Node* nod = head;
			while(nod != NULL){
				if(nod -> value < obj){
					if(nod -> right == NULL){
						nod -> right = (struct Node*) malloc(sizeof(struct Node));
						nod -> right -> value = obj;
						nod = NULL;
					}else{
						nod = nod -> right;
					}
				}else{
					if(nod -> left == NULL){
						nod -> left = (struct Node*) malloc(sizeof(struct Node));
						nod -> left -> value = obj;
						nod = NULL;
					}else{
						nod = nod -> left;
					}
				}
			}
		}
		lenght++;
	}

	//bool removeNode(T obj)

	//T removeHead()

	bool findNode(T obj){
		if(lenght == 0) return false;
		struct Node* nod = head;
		bool res = false;
		while(nod != NULL){
			if(nod -> value == obj){
				res = true;
				nod = NULL;
			}else{
				if(nod -> value < obj){
					nod = nod -> right;
				}else{
					nod = nod -> left;
				}	
			}	
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

	int getHeight(){
		if(lenght == 0) return 0;
		return getHeightNode(head);
	}

	T findMax(){
		if(lenght == 0) throw std::runtime_error("The tree is empty.");
		return findMaxAux(head);
	}

	T findMin(){
		if(lenght == 0) throw std::runtime_error("The tree is empty.");
		return findMinAux(head);
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

	int getHeightNode(struct Node* nod){
		if(nod == NULL) return 0;
		return 1 + max(getHeightNode(nod -> left), getHeightNode(nod -> right));
	}

	int max(int n1, int n2){
		if(n1 > n2){
			return n1;
		}else{
			return n2;
		}
	}

	T findMaxAux(struct Node* nod){
		if(nod -> right == NULL){
			return nod -> value; 
		}else{
			return findMaxAux(nod -> right);
		}
	}

	T findMinAux(struct Node* nod){
		if(nod -> left == NULL){
			return nod -> value; 
		}else{
			return findMinAux(nod -> left);
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
