#include <iostream>
#include "Sbase.h"

int main() {
	Sfile f("file.txt");
	Skey k;
	Sbase* q = new Squeue(5);

	Freq* diap = new Freq();

	diap->Calc(*q);

	std::cout << *diap;

	return 0;
}