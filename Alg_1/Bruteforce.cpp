#include "Bruteforce.h"
#include "Matrix.h"
int* firstPermutation(int n) {
	int* perm = new int[n];
	for (int i = 0; i < n; i++) {
		perm[i] = i;
	}
	return perm;
}
bool nextPermutation(int* currentPerm, int n) {
	int i = n - 2;
	while (0 < i && i < n && currentPerm[i] >= currentPerm[i + 1]) {
		i--;
	}
	if (i < 0) return false;

	int j = n - 1;
	while (i < j && currentPerm[i] >= currentPerm[j]) {
		j--;
	}
	std::swap(currentPerm[i], currentPerm[j]);
	int left = i + 1;
	int right = n- 1;
	while (right > left) {
		std::swap(currentPerm[left], currentPerm[right]);
		left++;
		right--;
	}
	return true;
}

int pathWeight(int** matrix, int* permutation, int n) {
	int weight = 0;
	for (int i = 0; i < n-1; i++) {
		weight += matrix[permutation[i]][permutation[i + 1]];
	}
	weight += matrix[permutation[n - 1]][permutation[0]];
	return weight;
}
void printPermutation(int* currentPermutation, int n) {
	std::cout << "Best permutation: ";
	for (int i = 0; i < n; i++)
		std::cout << currentPermutation[i] << ' ';
	std::cout << currentPermutation[0] << std::endl;
}
void BruteForce(int** matrix, int n) {

	int* currentPermutation = firstPermutation(n);
	int* bestPermutation = new int[n];
	int bestWeight = INT16_MAX;
	int currentWeight;
	do {
		currentWeight = pathWeight(matrix, currentPermutation, n);
		if (currentWeight < bestWeight) {
			for (int i = 0; i < n; i++) {
				bestPermutation[i] = currentPermutation[i];
			}
			bestWeight = currentWeight;
		}

	} while (nextPermutation(currentPermutation, n));



	printPermutation(bestPermutation, n);
	std::cout << "ABSOLUTE BEST COOLEST WEIGHT: " << bestWeight<< std::endl;
	
	delete[] currentPermutation;
	delete[] bestPermutation;


}