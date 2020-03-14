#include <iostream>
#include "linkedList.cpp"
#include "doubleList.cpp"
#include "Stack.cpp"
#include "Queue.cpp"
#include "Disjoint.cpp"
#include "Binary_Tree.cpp"

using namespace std;

struct datos{
	int num;
	int can;
};

int main(){
	// Lugar para hacer pruebas con los archivos nuevos
	BinaryTree<int> Binary(1);
	//cout << Binary.lenght << endl;

	Binary.addNode(2);
	Binary.addNode(3);
	Binary.addNode(4);
	Binary.addNode(5);
	
	Binary.popNode();
	Binary.popNode();
	Binary.popNode();
	Binary.popNode();
	Binary.popNode();

	Binary.addNode(30);
	//cout << Binary.findNode(5) << endl;
	
	//cout << Binary.getNode(1) << endl;
	//Binary.setNode(40, 1);
	Binary.print();
	

	//cout << Binary.lenght << endl;
	cout << "Funciona" << endl;
	

	return 0;
}
