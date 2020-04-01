#include <iostream>

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
	cout << "[";
	if(vec.size() != 0){
		int i;
		for(i = 0 ; i<vec.size()-1 ; i++){
			cout << vec[i] << " , ";
		}
		cout << vec[i];
	}
	cout << "]" << endl;
}

//Cambiar el swap de tres lineas por la funcion swap de la libreria vector

void bubbleSort(vector<int>& vec, bool op = true){//menor a mayor
	int aux;
	for(int i = 0 ; i<vec.size() ; i++){
		for(int j = 0 ; j<vec.size()-1 ; j++){
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
		for(int j = 0 ; j<vec.size()-1 ; j++){
			if(vec[j] > vec[j+1]){
				aux = vec[j];
				vec[j] = vec[j+1];
				vec[j+1] = aux;
			}
			printVector(vec);
			if(op) sleep(500);
		}
	}
}

void insertionSort(vector<int>& vec, bool op = true){//menor a mayor
	int aux;
	for(int i = 1 ; i<vec.size() ; i++){
		for(int j = i ; j>0 && vec[j] < vec[j-1] ; j--){
			aux = vec[j];
			vec[j] = vec[j-1];
			vec[j-1] = aux;
		}
	}
}

void insertionVisualSort(vector<int>& vec, bool op = true){
	int aux;
	for(int i = 1 ; i<vec.size() ; i++){
		for(int j = i ; j>0 && vec[j] < vec[j-1] ; j--){
			aux = vec[j];
			vec[j] = vec[j-1];
			vec[j-1] = aux;
			printVector(vec);
			if(op) sleep(500);
		}
	}
}

void selectionSort(vector<int>& vec, bool op = true){
	if(vec.size() != 0){
		int min, aux;
		for(int i = 0 ; i<vec.size()-1 ; i++){
			min = i;
			for(int j = i+1 ; j<vec.size() ; j++){
				if(vec[j] < vec[min]) min = j;
			}
			aux = vec[min];
			vec[min] = vec[i];
			vec[i] = aux;
		}
	}
}

void selectionVisualSort(vector<int>& vec, bool op = true){
	if(vec.size() != 0){
		int min, aux;
		for(int i = 0 ; i<vec.size()-1 ; i++){
			min = i;
			for(int j = i+1 ; j<vec.size() ; j++){
				if(vec[j] < vec[min]) min = j;
			}
			aux = vec[min];
			vec[min] = vec[i];
			vec[i] = aux;
			printVector(vec);
			if(op) sleep(500);
		}
	}
}

void mergeSort(vector<int>& vec, bool op = true, int in = 0, int fin = -1){
	if(fin == -1) fin = vec.size();
	if(fin - in > 1){
		mergeSort(vec, op, in, in+(fin - in)/2);
		mergeSort(vec, op, in+(fin - in)/2, fin);
		vector<int> mergeList(fin - in);
		for(int i = 0 ; i<mergeList.size() ; i++){
			mergeList[i] = vec[in+i];
		}
		int l1 = 0;
		int l2 = mergeList.size()/2;
		for(int i = in ; i < fin && l1 < mergeList.size()/2 ; i++){
			if(l2 >= mergeList.size() || mergeList[l1] < mergeList[l2]){
				vec[i] = mergeList[l1];
				l1++;
			}else{
				vec[i] = mergeList[l2];
				l2++;
			}
		}
	}
}

void mergeVisualSort(vector<int>& vec, bool op = true, int in = 0, int fin = -1){
	if(fin == -1) fin = vec.size();
	if(fin - in > 1){
		mergeVisualSort(vec, op, in, in+(fin - in)/2);
		mergeVisualSort(vec, op, in+(fin - in)/2, fin);
		printVector(vec);
		if(op) sleep(500);
		vector<int> mergeList(fin - in);
		for(int i = 0 ; i<mergeList.size() ; i++){
			mergeList[i] = vec[in+i];
		}
		int l1 = 0;
		int l2 = mergeList.size()/2;
		for(int i = in ; i < fin && l1 < mergeList.size()/2 ; i++){
			if(l2 >= mergeList.size() || mergeList[l1] < mergeList[l2]){
				vec[i] = mergeList[l1];
				l1++;
			}else{
				vec[i] = mergeList[l2];
				l2++;
			}
		}
	}
}

void quickSort(vector<int>& vec, bool op = true, int in = 0, int fin = -1){//menor a mayor
	if(fin == -1) fin = vec.size()-1;
	if(vec.size() >= 2 && fin-in >= 1){
		int aux;
		int pivot = fin;
		int der = in;
		int izq = fin-1;
		if(fin-in == 1 && vec[der] > vec[pivot]){
			aux = vec[der];
			vec[der] = vec[pivot];
			vec[pivot] = aux;
		}else{
			while(der < izq){
				while(der < fin && vec[der] <= vec[pivot]) der++;
				while(izq > in && vec[izq] > vec[pivot]) izq--;
				if(der < izq){
					aux = vec[der];
					vec[der] = vec[izq];
					vec[izq] = aux;
				}else{
					aux = vec[der];
					vec[der] = vec[pivot];
					vec[pivot] = aux;
				}
			}
			if(fin > der){
				quickSort(vec, op, in, der);
			}else{
				quickSort(vec, op, in, der-1);
			}
			if(in < der+1) quickSort(vec, op, der+1, fin);
		}
	}
}

void quickVisualSort(vector<int>& vec, bool op = true, int in = 0, int fin = -1){
	if(fin == -1) fin = vec.size()-1;
	if(vec.size() >= 2 && fin-in >= 1){
		int aux;
		int pivot = fin;
		int der = in;
		int izq = fin-1;
		if(fin-in == 1 && vec[der] > vec[pivot]){
			aux = vec[der];
			vec[der] = vec[pivot];
			vec[pivot] = aux;
		}else{
			while(der < izq){
				while(der < fin && vec[der] <= vec[pivot]) der++;
				while(izq > in && vec[izq] > vec[pivot]) izq--;
				if(der < izq){
					aux = vec[der];
					vec[der] = vec[izq];
					vec[izq] = aux;
				}else{
					aux = vec[der];
					vec[der] = vec[pivot];
					vec[pivot] = aux;
				}
			}
			printVector(vec);
			if(op) sleep(500);
			if(fin > der){
				quickSort(vec, op, in, der);
			}else{
				quickSort(vec, op, in, der-1);
			}
			if(in < der+1) quickSort(vec, op, der+1, fin);
		}
	}
}

void heapify(vector<int>& vec, int nod, int limit){
	int aux;
	int max = nod;
	int izq = 2*nod+1;
	int der = 2*nod+2;
	if(izq < vec.size() && izq < limit && vec[izq] > vec[max]) max = izq;
	if(der < vec.size() && der < limit && vec[der] > vec[max]) max = der;
	if(max != nod){
		aux = vec[max];
		vec[max] = vec[nod];
		vec[nod] = aux;
		heapify(vec, max, limit);
	}
}

void heapSort(vector<int>& vec, bool op = true){//ordena numeros naturales de menor a mayor
	if(vec.size() >= 2){
		int aux;
		for(int i = vec.size()/2-1 ; i>=0 ; i--){
			heapify(vec, i, vec.size());	
		}
		for(int i = vec.size()-1 ; i>=0 ; i--){
			aux = vec[0];
			vec[0] = vec[i];
			vec[i] = aux;
			heapify(vec, 0, i);
		}
	}
}

void heapVisualSort(vector<int>& vec, bool op = true){
	if(vec.size() >= 2){
		int aux;
		for(int i = vec.size()/2-1 ; i>=0 ; i--){
			heapify(vec, i, vec.size());	
		}
		printVector(vec);
		if(op) sleep(500);
		for(int i = vec.size()-1 ; i>=0 ; i--){
			aux = vec[0];
			vec[0] = vec[i];
			vec[i] = aux;
			heapify(vec, 0, i);
			printVector(vec);
			if(op) sleep(500);
		}
	}
}

void countingSort(vector<int>& vec, bool op = true){
	if(vec.size() > 1){
		int max = vec[0];
		for(int i = 1 ; i<vec.size() ; i++){
			if(vec[i] > max) max = vec[i];
		}
		vector<int> counting(max, 0);
		for(int i = 0 ; i<vec.size() ; i++){
			counting[vec[i]-1] += 1;
		}
		int cont = 0;
		int num = 0;
		for(int i = 0 ; i<counting.size(); i++){
			num = i+1;
			for(int j = 0 ; j<counting[i]; j++){
				vec[cont] = num;
				cont++;
			}
		}

	}
}

void bucketSort(vector<int>& vec, bool op = true){//ordena numeros naturales de menor a mayor
	if(vec.size() > 1){
		int b = 2;
		int max = vec[0];
		for(int i = 1 ; i<vec.size() ; i++){
			if(vec[i] > max) max = vec[i];
		}
		vector<vector<int>> bucket(max/b+1);
		for(int i = 0 ; i<vec.size() ; i++){
			bucket[vec[i]/b].push_back(vec[i]);
		}
		for(int i = 0 ; i<bucket.size() ; i++){
			heapSort(bucket[i]);
		}
		int cont = 0;
		for(int i = 0 ; i<bucket.size() ; i++){
			for(int j = 0 ; j<bucket[i].size() ; j++){
				vec[cont] = bucket[i][j];
				cont++;
			}
			
		}
	} 
}

// void radixSort(vector<int>& vec, bool op = true)

// void dualSort(vector<vector<int>>& vec, bool op = true) // ordena un vector de vectores de 2 elementos, por el elemento uno y si empatan por el segundo elemento 

// void multiSort(vector<vector<int>>& vec, bool op = true) // ordena un vector de vectores de n elementos, por el elemento uno y si empatan por el segundo elemento y si empatan por el tercero, asi esta el n elemento 

// void crossSort(vector<int>& vec, vector<int>& keys, bool op = true) //