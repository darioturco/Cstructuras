
#include <iostream>
#include "linkedList.cpp"


using namespace std;

struct datos{
	int num;
	int can;
};

int main(){
	// Lugar para hacer pruebas con los archivos nuevos
	linkedList<int> newList(20);
	
	newList.add(30);
	newList.add(10);
	newList.add(50);
	newList.add(30);
	newList.add(30);
	newList.add(30);
	newList.add(30);
	
	cout << newList.lenght << endl;
	
	newList.add(40, 8);
	//cout << newList.get(9) << endl;
	
	cout << newList.lenght << endl;
	newList.print();
	
	return 0;
}
