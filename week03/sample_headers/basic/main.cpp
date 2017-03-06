// #include <iostream>
// using std::cout;
// using std::endl;

#include "arrayprint.cpp"
#include "baba.cpp"

int main()
{
	int numbers[] = {1, 2, 3, 4, 5};
	unsigned int n = sizeof(numbers) / sizeof(numbers[0]);

	print_array(numbers, n);
	cout << endl;
	print_baba();
	return 0;
}
