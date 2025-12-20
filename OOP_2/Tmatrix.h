#pragma once
#include "Tvector.h"
template <typename T> class Tmatrix
{
	int rows, columns;
	Tvector<T>* vectors;
public:
	Tmatrix(int rows=1, int columns=1) : rows(rows), columns(columns), vectors(new Tvector<T>[rows]){
		for (int i = 0; i < rows; i++) {
			vectors[i].setLength(columns);
		}
	}
	Tmatrix(const Tmatrix& other) : rows(other.rows), columns(other.columns) {
		vectors = new Tvector<T>[rows];
		for (size_t i = 0; i < rows; ++i) {
			vectors[i] = other.vectors[i];
		}
	}
	~Tmatrix() {
		delete[] vectors;
	}
	Tmatrix& operator=(const Tmatrix& other) {
		if (this == &other) {
			return *this;
		}
		delete[] vectors;
		rows = other.rows;
		columns = other.columns;
		vectors = new Tvector<T>[rows];
		for (size_t i = 0; i < rows; ++i) {
			vectors[i] = other.vectors[i];
		}
		return *this;
	}
	Tmatrix& operator+=(const Tmatrix& other) {
		if (rows != other.rows || columns != other.columns) {
			exit(1);
		}
		for (int i = 0; i < rows; ++i) {
			vectors[i] += other.vectors[i];
		}
		return *this;
	}
	Tvector<T>& operator[](int index) {
		if (index < 0 || index >= rows) {
			exit(1);
		}
		return vectors[index];
	}
	friend std::ostream& operator<<(std::ostream& os, const Tmatrix& mat) {
		for (int i = 0; i < mat.rows; ++i) {
			os << mat.vectors[i] << std::endl;
		}
		return os;
	}
	friend std::istream& operator>>(std::istream& is, Tmatrix& mat) {
		for (int i = 0; i < mat.rows; ++i) {
			is >> mat.vectors[i];
		}
		return is;
	}
};

