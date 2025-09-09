#pragma once
#include <random>
int** CreateMatrix(int n);

void FillMatrixRandom(int** matrix, int n, int rangeStart, int rangeEnd);

void FillMatrix(int** matrix, int n);

void PrintMatrix(int** matrix, int n);

void DeleteMatrix(int** matrix, int n);
