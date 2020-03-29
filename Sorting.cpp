#include <iostream>
#include "Sorting_Aux.cpp"

#ifdef _WIN32
	#include <windows.h>
	void sleep(int milliseconds){
		Sleep(milliseconds);
	}
#else
	#include <unistd.h>
	void sleep(int milliseconds){
		usleep(milliseconds * 1000); // takes microseconds
	}
#endif

using namespace std;

void printVector(const vector<int>& vec){
	int i;
	cout << "[";
	for(i = 0 ; i<vec.size()-1 ; i++){
		cout << vec[i] << " , ";
	}
	cout << vec[i] << "]" << endl;
}

void bubbleSort(vector<int>& vec, bool op = true){
	int aux;
	for(int i = 0 ; i<vec.size() ; i++){
		for(int j = i ; j<vec.size()-1 ; j++){
			if(vec[j] > vec[j+1]){
				aux = vec[j];
				vec[j] = vec[j+1];
				vec[j+1] = aux;
			}
		}
	}
}

void bubbleVisualSort(vector<int>& vec, bool op = true){
	printVector(vec);
	int aux;
	for(int i = 0 ; i<vec.size() ; i++){
		for(int j = i ; j<vec.size()-1 ; j++){
			if(vec[j] > vec[j+1]){
				aux = vec[j];
				vec[j] = vec[j+1];
				vec[j+1] = aux;
			}
			printVector(vec);
			if(op) sleep(500);
		}
	}
	function();
}

// void insertionSort(vector<int>& vec, bool op = true)

// void insertionVisualSort(vector<int>& vec, bool op = true)

// void selectionSort(vector<int>& vec, bool op = true)

// void selectionVisualSort(vector<int>& vec, bool op = true)

// void mergeSort(vector<int>& vec, bool op = true)

// void mergeVisualSort(vector<int>& vec, bool op = true)

// void quickSort(vector<int>& vec, bool op = true)

// void quickVisualSort(vector<int>& vec, bool op = true)

// void heapSort(vector<int>& vec, bool op = true)

// void heapVisualSort(vector<int>& vec, bool op = true)

// void countingSort(vector<int>& vec, bool op = true)

// void countingVisualSort(vector<int>& vec, bool op = true)

// void bucketSort(vector<int>& vec, bool op = true)

// void bucketVisualSort(vector<int>& vec, bool op = true)

// void radixSort(vector<int>& vec, bool op = true)

// void radixVisualSort(vector<int>& vec, bool op = true) 
