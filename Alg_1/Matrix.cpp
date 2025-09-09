#include <iostream>
#include "Matrix.h"

int** CreateMatrix(int n) {
	int** matrix = new int* [n];
	for (int i = 0; i < n; i++) {
		matrix[i] = new int[n];
	}
	return matrix;
}
void FillMatrixRandom(int** matrix, int n, int rangeStart, int rangeEnd) {
	std::random_device randomDevice;
	std::mt19937_64 generator(randomDevice());
	std::uniform_int_distribution<int> distribution(rangeStart, rangeEnd);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) matrix[i][j] = 0;
			else matrix[i][j] = distribution(generator);
		}
	}
}
void FillMatrix(int** matrix, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				matrix[i][j] = 0;
			}
			else {
				std::cin >> matrix[i][j];
			}
		}
	}
}
void PrintMatrix(int** matrix, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << matrix[i][j] << ' ';
		}
		std::cout << '\n';
	}
}
void DeleteMatrix(int** matrix, int n) {
	for (int i = 0; i < n; i++) {
		delete matrix[i];
	}
	delete matrix;
}