#include <iostream>
#include "Tvector.h"
#include "Tmatrix.h"
#include "C:\Users\anond\source\repos\Laboratory\OOP_1\СStr.cpp"
int main()
{
	/*Tvector<int> vec1 = { 1,2,3,4,5 };
	Tvector<int> vec2(vec1);
	vec1.setLength(8);
	vec2.setLength(3);
	Tvector<int> vec3;
	std::cin >> vec3;
	vec1[2] = 10;
	vec1.Print();
	vec2.Print();
	vec3.Print();
	vec1 += vec2;
	vec1.Print();

	Tvector<std::string> str_vec = { "hello "};
	Tvector<std::string> str_vec1 = { "world"};
	str_vec += str_vec1;
	str_vec.Print();

	Tvector <char> char_vec = { 'h','e','l','l','o'};
	char_vec += char_vec;
	char_vec.Print();

	Tvector <CStr> cstr_vec;
	Tvector <CStr> cstr_vec1(cstr_vec);
	cstr_vec[0] = "hello";
	cstr_vec1[0] = "world";
	cstr_vec += cstr_vec1;
	cstr_vec.Print();*/




	std::cout << "Enter the first: ";
	Tmatrix<int> mat1(2, 3);
	std::cin >> mat1;
	std::cout <<  mat1;

	Tmatrix<int> mat2(2, 3);
	std::cout << "Enter the second: ";
	std::cin >> mat2;
	std::cout << mat2;

	mat1 += mat2; 
	std::cout << "Result: \n" << mat1
		<< "________________\n" <<
		mat1[0];

}
