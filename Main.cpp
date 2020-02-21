
#include <iostream>
#include "linkedList.cpp"
#include "doubleList.cpp"
#include "Stack.cpp"

using namespace std;

struct datos{
	int num;
	int can;
};

int main(){
	// Lugar para hacer pruebas con los archivos nuevos
	Stack<int> newStack;
	
	cout << newStack.lenght << endl;

	newStack.push(5);
	newStack.push(4);
	newStack.push(3);
	newStack.push(2);
	
	cout << newStack.pop() << endl;
	cout << newStack.pop() << endl;
	cout << newStack.pop() << endl;
	cout << newStack.pop() << endl;
	
	
	newStack.print();
	cout << newStack.lenght << endl;
	
	return 0;
}
