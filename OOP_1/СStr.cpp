#include "СStr.h"

char* CStr::generate(int length)
{
	random_device rd;
	mt19937 generator(rd());
	uniform_int_distribution<int> distribution(0, 25);
	if (length < 1) length = 1;
	if (length > 20) length = 20;
	char* s = new char[length + 1];
	for (int i = 0; i < length; i++)
		s[i] = 'a' + distribution(generator);
	s[length] = '\0';
	return s;
}

CStr::CStr()
{
	random_device rd;
	mt19937 generator(rd());
	uniform_int_distribution<int> distribution(0, 19);
	int len = 1+ distribution(generator);
	string = generate(len);
}

CStr::CStr(const char* str)
{
	string = new char[strlen(str) + 1];
	strcpy(string, str);
}

CStr::CStr(int length)
{
	srand(time(NULL));
	string = generate(length);
}

CStr::CStr(const CStr& other)
{
	string = new char[strlen(other.string) + 1];
	strcpy(string, other.string);
}

CStr::~CStr()
{
	delete[] string;
}

CStr& CStr::operator=(CStr& other)
{
	if (this != &other)
	{
		delete[] string;
		string = new char[strlen(other.string) + 1];
		strcpy(string, other.string);
	}
	return *this;
}

CStr& CStr::operator=(const char* str)
{
	delete[] string;
	string = new char[strlen(str) + 1];
	strcpy(string, str);
	return *this;
}

CStr CStr::operator+(CStr& other)
{
	int newlen = strlen(string) + strlen(other.string);
	char* temp = new char[newlen + 1];
	strcpy(temp, string);
	strcat(temp, other.string);
	CStr result(temp);
	delete[] temp;
	return result;
}

CStr& CStr::operator+=(CStr& other)
{
	int newlen = strlen(string) + strlen(other.string);
	char* temp = new char[newlen + 1];
	strcpy(temp, string);
	strcat(temp, other.string);
	delete[] string;
	string = temp;
	return *this;
}

bool CStr::operator>(CStr& other)
{
	return strcmp(string, other.string) > 0;
}

char& CStr::operator[](int index)
{
	return string[index];
}

int CStr::len() const
{
	return strlen(string);
}

ostream& operator<<(ostream& stream, CStr& other)
{
	stream << other.string;
	return stream;
}

istream& operator>>(istream& stream, CStr& other)
{
	char buffer[256];
	stream >> buffer;
	other = buffer;
	return stream;
}




CStrArray::CStrArray(int cap)
{
	capacity = cap;
	size = 0;
	arr = new CStr * [capacity];
	for (int i = 0; i < capacity; i++)
		arr[i] = nullptr;
}

CStrArray& CStrArray::operator+=(CStr* other)
{
	if (size < capacity)
	{
		arr[size++] = other;
	}
	return *this;
}

CStrArray::~CStrArray()
{
	delete[] arr;
}

CStr* CStrArray::operator[](int index)
{
	if (index >= 0 && index < size)
		return arr[index];
	return nullptr;
}

void CStrArray::sort_content()
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (*arr[i] > *arr[j])
			{
				CStr* temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void CStrArray::sort_len()
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr[i]->len() > arr[j]->len())
			{
				CStr* temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

bool CStrArray::check_sort()
{
	for (int i = 0; i < size - 1; i++)
	{
		if (*arr[i] > *arr[i + 1])
			return false;
	}
	return true;
}

ostream& operator<<(ostream& stream, CStrArray& obj)
{
	for (int i = 0; i < obj.size; i++)
	{
		stream << *obj.arr[i] << (i == obj.size - 1 ? "" : ", ");
	}
	return stream;
}