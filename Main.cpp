#include <iostream>
#include "linkedList.cpp"


using namespace std;

struct datos{
	int num;
	int can;
};

int main(){
	
	linkedList<int> newList(1);
	
	newList.add(30);
	newList.add(10);
	newList.add(50);
	newList.add(30);
	newList.add(40);
	newList.add(30);
	newList.add(30);
	newList.add(30);
	newList.add(300);
	
	cout << newList.lenght << endl;
	
	//newList.clear();
	//cout << newList.get(9) << endl;
	
	cout << newList.lenght << endl;
	newList.print();
	
	return 0;
}
