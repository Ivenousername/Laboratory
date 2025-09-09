// Alg_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Matrix.h"
#include "Bruteforce.h"
#include <chrono>
int main()
{
	using namespace std;
	chrono::high_resolution_clock::time_point timeStart = std::chrono::high_resolution_clock::now();
	int n = 6;
	int* currentPerm = new int[n] {6,5,4,3,1,2};
	nextPermutation(currentPerm, n);

	for (int i = 0; i < n; i++) {
		cout << currentPerm[i] << ' ';
	}
	cout << endl;


	chrono::high_resolution_clock::time_point timeEnd = std::chrono::high_resolution_clock::now();

	chrono::duration<double> duration = timeEnd - timeStart;
	cout << duration.count() << " seconds" << std::endl;
}