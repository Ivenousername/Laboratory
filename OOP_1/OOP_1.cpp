#include "СStr.h"

int main()
{
	CStrArray arr(10);

	arr += new CStr();
	cout << arr;
	arr += new CStr("Hello World");
	*arr[0] = *arr[1];
	arr += new CStr("Allo World");
	arr += new CStr();
	arr += new CStr();
	arr += new CStr();
	arr += new CStr(*arr[3]);
	cout << *arr[0];
	cout << "The array: " << arr << endl;
	arr.sort_len();
	cout << "Array sorted by length: " << arr << endl;
	cout << "Sorted by content: " << arr.check_sort() << endl;
	arr.sort_content();
	cout << "Array sorted by content : " << arr << endl;
	cout << "Sorted by content: " << arr.check_sort() << endl;
}
