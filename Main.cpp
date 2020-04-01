#include <iostream>
#include <vector>
#include "linkedList.cpp"
#include "doubleList.cpp"
#include "Stack.cpp"
#include "Queue.cpp"
#include "Disjoint.cpp"
#include "Binary_Tree.cpp"
#include "Binary_Search_Tree.cpp"
#include "Sorting.cpp"

using namespace std;

struct datos{
	int num;
	int can;
};

int main(){

	vector<int> vec = vector<int>();
	//vec = {10,8,2,9,5,3,10};
	//vec = {1,2,3,4,5,6,7,8,9};
	//vec = {9,8,7,6,5,4,3,2,1};
	vec = {7,15,20,8,40,54,22,81,31,62,10,15,34,6,1,50,43,71,61,31};
	//vec = {5,5,6,5,5,5};
	//vec = {8,10,5,3,5,6};
	//vec = {1,2};
	//vec = {2,1};
	//vec = {};
	//vec = {5};
	//vec = {1,5,7,4,8,6,9,2,3};
	//vec = {3,2,5,4};
	//vec = {8,9,2,3,5};
	//vec = {5,6,7,8,9,0,1,2,3,4};

	//printVector(vec);

	mergeVisualSort(vec, true);

	printVector(vec);	

	// Lugar para hacer pruebas con los archivos nuevos
	/*BinarySearchTree<int> Binary;
	Binary.addNode(30);
	Binary.addNode(20);
	Binary.addNode(8);
	Binary.addNode(2);
	Binary.addNode(22);
	Binary.addNode(25);
	Binary.addNode(40);
	Binary.addNode(50);
	Binary.addNode(70);

	Binary.print();
	Binary.preorder();
	Binary.inorder();
	Binary.posorder();*/

	//cout << Binary.lenght << endl;
	//cout << "Funciona" << endl;

	return 0;
}
