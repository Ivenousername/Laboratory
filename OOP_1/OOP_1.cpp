#include "СStr.h"

int main()
{
	CStrArray arr(10);

	arr += new CStr();
	arr += new CStr("Hello World");
	arr += new CStr("Allo World");
	arr += new CStr();
	arr += new CStr();
	cout << "The array: " << arr << endl;
	arr.sort_len();
	cout << "Array sorted by length: " << arr << endl;
	cout << "Sorted by content: " << static_cast<bool>(arr.check_sort()) << endl;
	arr.sort_content();
	cout << "Array sorted by content : " << arr << endl;
	cout << "Sorted by content: " << static_cast<bool>(arr.check_sort()) << endl;
	//В функции main нужно создать объект CStrArray с массивом заданной длины, 
	//	создать и добавить в массив несколько объектов CStr, провести сортировку по содержимому(с проверкой) 
	//	и длине строк и вывести отсортированные массивы.
}
