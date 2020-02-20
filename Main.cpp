
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
	doubleList<int> newList(0);
	//newList.addLast(10);
	
	cout << newList.lenght << endl;
	newList.print();
	
	newList.removeAt(0);
	
	newList.print();
	newList.printBack();
	cout << newList.lenght << endl;
	
	return 0;
}
