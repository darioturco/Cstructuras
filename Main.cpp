
#include <iostream>
#include "linkedList.cpp"
#include "doubleList.cpp"

using namespace std;

struct datos{
	int num;
	int can;
};

int main(){
	// Lugar para hacer pruebas con los archivos nuevos
	doubleList<int> newList;
	newList.addLast(10);
	newList.addLast(20);
	newList.addLast(30);
	newList.addLast(40);
	newList.addLast(50);
	
	cout << newList.lenght << endl;
	newList.print();
	
	newList.add(100, 1);
	
	newList.print();
	newList.printBack();
	cout << newList.lenght << endl;
	
	return 0;
}
