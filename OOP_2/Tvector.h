#pragma once
#include <iostream>
#include <initializer_list>

template < typename T> class Tvector
{
	T* array;
	int len;

public:
	Tvector(int len=1) : len(len), array(new T[len]) {
		
	}
	Tvector(const Tvector& other) :len(other.len){
		array = new T[len];
		for (int i = 0; i < len; i++) {
			array[i] = other.array[i];
		}
	}
	Tvector(std::initializer_list<T> list) : len(list.size()) {
		array = new T[len];
		int i = 0;
		for (const T& val : list) {
			array[i++] = val;
		}
	}
	~Tvector() {
		delete[] array;
	}
	void setLength(int new_len) {
		T* new_array = new T[new_len]();
		int temp = 0;
		if (new_len > len) temp = len;
		else temp = new_len;
		for (int i = 0; i < temp; i++) {
			new_array[i] = array[i];
		}
		delete[] array;
		array = new_array;
		len = new_len;
	}
	Tvector& operator=(const Tvector& other) {
		delete[] array;
		len = other.len;
		array = new T[len];
		for (int i = 0; i < len; i++) {
			array[i] = other.array[i];
		}
	}
	void operator+=(const Tvector& other) { 
		if (len == other.len) {
			for (int i = 0; i < len; i++) {
				array[i] += other.array[i];
			};
			return;
		}
		exit(1) ;
	}
	T& operator[](int i) {
		if (i < len && i>=0) {
			return array[i];
		}
		exit(1) ;
	}
	friend std::ostream& operator<<(std::ostream& os, const Tvector& vec) {
		if (vec.len == 0) {
			os << "NULL";
			return os;
		}

		os << vec.array[0];
		for (int i = 1; i < vec.len; ++i) {
			os << " " << vec.array[i];
		}
		return os;
	}

	friend std::istream& operator>>(std::istream& is, Tvector& vec) {
		for (int i = 0; i < vec.len; ++i) {
			is >> vec.array[i];
		}
		return is;
	}

	void Print() {
		std::cout << '{' << *this << '}';
	}

};
