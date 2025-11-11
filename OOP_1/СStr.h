#pragma once
#pragma warning(disable:4996)
#include <iostream>
#include <cstring>ee
#include <cstdlib>
#include <random>
#include <chrono>
using namespace std;
class CStr
{
	char* string;
	char* generate(int length);
public:
	CStr();
	CStr(const char* str);
	CStr(int length);
	CStr(const CStr& obj);
	~CStr();
	CStr& operator=(CStr& obj);
	CStr& operator=(const char* str);
	CStr operator+(CStr& obj);
	CStr& operator+=(CStr& obj);
	bool operator>(CStr& obj);
	char& operator[](int index);
	int len() const;
	friend ostream& operator<<(ostream& stream, CStr& obj);
	friend istream& operator>>(istream& stream, CStr& obj);
};

class CStrArray
{
	CStr** arr;
	int capacity, size;
public:
	CStrArray(int cap);
	CStrArray& operator+=(CStr* obj);
	~CStrArray();
	CStr* operator[](int index);
	void sort_content();
	void sort_len();
	bool check_sort();
	friend ostream& operator<<(ostream& stream, CStrArray& obj);
};


