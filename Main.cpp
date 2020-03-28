#include <iostream>
#include "linkedList.cpp"
#include "doubleList.cpp"
#include "Stack.cpp"
#include "Queue.cpp"
#include "Disjoint.cpp"
#include "Binary_Tree.cpp"
#include "Binary_Search_Tree.cpp"

using namespace std;

struct datos{
	int num;
	int can;
};

int main(){
	// Lugar para hacer pruebas con los archivos nuevos
	BinarySearchTree<int> Binary(20);
	//cout << Binary.lenght << endl;

	Binary.addNode(10);
	Binary.addNode(5);
	Binary.addNode(15);
	Binary.addNode(1);
	Binary.addNode(40);
	Binary.addNode(35);
	Binary.addNode(60);
	Binary.addNode(50);
	Binary.addNode(70);

	cout << Binary.findMin() << endl;

	Binary.print();
	Binary.preorder();
	Binary.inorder();
	Binary.posorder();

	//cout << Binary.lenght << endl;
	cout << "Funciona" << endl;
	

	return 0;
}
