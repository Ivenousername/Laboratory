#pragma once
#include <random>
int** CreateMatrix(int n);

void FillMatrixRandom(int** matrix, int n, int rangeStart=1, int rangeEnd=20);

void FillMatrix(int** matrix, int n);

void PrintMatrix(int** matrix, int n);

void DeleteMatrix(int** matrix, int n);
