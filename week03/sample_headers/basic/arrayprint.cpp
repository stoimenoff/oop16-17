#include <iostream>

using std::cout;
using std::endl;

void print_array(int* arr, unsigned int size)
{
	for (int i = 0; i < size; ++i)
		cout << arr[i] << ((i != size - 1) ? " " : "");
}
