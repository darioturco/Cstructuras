
#include <iostream>
#include "linkedList.cpp"
#include "doubleList.cpp"
#include "Stack.cpp"
#include "Queue.cpp"

using namespace std;

struct datos{
	int num;
	int can;
};

int main(){
	// Lugar para hacer pruebas con los archivos nuevos
	Queue<int> newQueue;
	
	cout << newQueue.lenght << endl;
	
	newQueue.push(0);
	newQueue.push(1);
	newQueue.push(2);
	newQueue.push(3);
	newQueue.push(4);
	
	cout << newQueue.pop() << endl;
	cout << newQueue.pop() << endl;
	cout << newQueue.pop() << endl;
	cout << newQueue.pop() << endl;
	cout << newQueue.pop() << endl;
	
	newQueue.print();
	cout << newQueue.lenght << endl;
	
	return 0;
}
