#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

void initialize_array(int[], int);
int * shuffle_array(const int[], int);
void print_array(const int[], int);
int * createOddArray(const int[], int, int &);
int * createEvenArray(const int[], int, int &);
void array_war(int*, int, int*, int);
void sort_array(int*, int);

int main() {
	int arraySize, evenSize = 0, oddSize = 0;

	srand(time(NULL));

	startover:
	cout << "Please enter the size of the array: ";
	cin >> arraySize;
	if (arraySize > 52 || arraySize < 1 || cin.fail()) {
		cout << "Please enter a number between 1-52" << endl;
		cin.clear();
		cin.ignore(100,'\n');
		goto startover;
	}
	int * initialArray = new int[arraySize];
	cout << "Original array is: ";
	initialize_array(initialArray, arraySize);	//initialize array
	print_array(initialArray, arraySize);
	cout << "\nShuffled array is: ";
	int * shuffledArray = shuffle_array(initialArray, arraySize);	//shuffle array
	delete[] initialArray;
	print_array(shuffledArray, arraySize);
	cout << "\nAfter call to createOddArray, oddArray is:   ";
	int * oddArray = createOddArray(shuffledArray, arraySize, oddSize);		//odd array
	print_array(oddArray, oddSize);
	cout << "\nAfter call to createEvenArray, evenArray is: ";
	int * evenArray = createEvenArray(shuffledArray, arraySize, evenSize);		//even array
	print_array(evenArray, evenSize);
	delete[] shuffledArray;
	cout << "\nArrayFight winners were:\t\t     ";
	array_war(evenArray, evenSize, oddArray, oddSize);		//even and odd array comparison
	delete[] evenArray;
	delete[] oddArray;
	return 0;
}

void swap(int &a, int &b) {		// swaps two ints a and b
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void initialize_array(int array[], int n) {		//initializes the array as an array of sequential whole numbers beginning at 0
	for (int i = 0; i < n; i++){
		array[i] = i;
	}
}

int * shuffle_array(const int array[], int n) {		//shuffles array so that the elements aren't in sequential order
	int * shuffleTemp = new int[n];
	for (int i = 0; i < n; i++) {
		shuffleTemp[i] = array[i];
	}
	for (int i = n - 1; i >= 1; i--) {
		int j = rand() % n;
		swap(shuffleTemp[i], shuffleTemp[j]);
	}
	return shuffleTemp;
}

void print_array(const int array[], int n) {	//prints array
	cout << "[";
	for (int i = 0; i < n; i++){
		cout << array[i];
		if (i != n-1) cout << ' ';
	}
	cout << "]";
}

int * createOddArray(const int array[], int n, int &m) {	//splits array input and returns array with only the odd number elements
	for (int i = 0; i < n; i++) {
		if (array[i] % 2 == 1) {
			m++;
		}
	}
	int * oddTemp = new int[m];
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (array[i] % 2 == 1) {
			oddTemp[count] = array[i];
			count++;
		}
	}
	return oddTemp;
}

int * createEvenArray(const int array[], int n, int &m) {	//splits array input and returns array with only the even number elements
	for (int i = 0; i < n; i++) {
		if (array[i] % 2 == 0) {
			m++;
		}
	}
	int * evenTemp = new int[m];
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (array[i] % 2 == 0) {
			evenTemp[count] = array[i];
			count++;
		}
	}
	return evenTemp;
}

void array_war(int * evenArray, int evenSize, int * oddArray, int oddSize) {	//compares elements of similar index in two arrays; stores the higher of the two values at that index in arrayWar with the same index
	int largestSize, smallestSize;
	if (evenSize > oddSize) {
		largestSize = evenSize;
		smallestSize = oddSize;
	} else {
		largestSize = oddSize;
		smallestSize = evenSize;
	}
	int * arrayWar = new int [largestSize];
	for (int i = 0; i < smallestSize; i++) {
		if (evenArray[i] > oddArray[i]) {
			arrayWar[i] = evenArray[i];
		} else {
			arrayWar[i] = oddArray[i];
		}
	}
	for (int i = smallestSize; i < largestSize; i++) {	//if one array overhangs another array (i.e. one array is longer than the other) the longer array wins by default
		if (evenSize == largestSize) {
		arrayWar[i] = evenArray[i];
		} else {
			arrayWar[i] = oddArray[i];
		}
	}
	print_array(arrayWar, largestSize);
	cout << "\nSorted ArrayFight winners were:\t\t     ";
	sort_array(arrayWar, largestSize);
	delete[] arrayWar;
}

void sort_array(int * array, int n) {	//selection sort
	int min;
	for (int i = 0; i < n; i++) {
		min = i;
		for (int j = i+1; j < n; j++) {
			if (array[j] < array[min]) {
				min = j;
			}
		}
		if (min != i) {
			swap(array[min], array[i]);
		}
	}
	print_array(array, n);
}
