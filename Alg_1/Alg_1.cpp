#include <iostream>
#include "Matrix.h"
#include "Bruteforce.h"
#include <chrono>
int main()
{
	using namespace std;
	chrono::high_resolution_clock::time_point timeStart = std::chrono::high_resolution_clock::now();
	int n;
	cin >> n;
	int** matrix = CreateMatrix(n);
	FillMatrixRandom(matrix, n);
	PrintMatrix(matrix, n);

	BruteForce(matrix, n);

	chrono::high_resolution_clock::time_point timeEnd = std::chrono::high_resolution_clock::now();

	chrono::duration<double> duration = timeEnd - timeStart;
	cout << duration.count() << " seconds" << std::endl;
}