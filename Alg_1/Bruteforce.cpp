#include "Bruteforce.h"


bool nextPermutation(int* currentPerm, int n) {
	int i = n - 2;
	while (0 < i < n && currentPerm[i] >= currentPerm[i + 1]) {
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