#pragma once
#include <iostream>
int* firstPermutation(int n);
bool nextPermutation(int* currentPerm, int n);

int pathWeight(int** matrix, int* permutation, int n);

void printPermutation(int* currentPermutation, int n);

void BruteForce(int** matrix, int n);
