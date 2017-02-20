#include <iostream>
#include <typeinfo>
using namespace std;

void test_sizeof(int *array, unsigned int size)
{
	cout << sizeof(array) << endl; // 8, защото е просто указател
}

int main()
{
	cout << typeid(int).name() << endl;
	cout << typeid(int const).name() << endl;
	cout << endl;

	cout << typeid(int *).name() << endl;
	cout << typeid(int const *).name() << endl;
	cout << typeid(int * const).name() << endl;
	cout << typeid(int const * const).name() << endl;
	cout << endl;

	cout << typeid(int&).name() << endl;
	cout << typeid(int const&).name() << endl;
	cout << endl;

	int arrayOfFive[5] = {1, 2, 3, 4, 5};
	int arrayOfThree[3] = {1, 2, 3};

	int *intPointer;

	cout << typeid(arrayOfFive).name() << endl; // A5_i
	cout << typeid(arrayOfThree).name() << endl; // A3_i
	cout << typeid(intPointer).name() << endl; // Pi
	cout << endl;

	cout << sizeof(arrayOfFive) << endl; // 20 = 5 * 4 байта
	cout << sizeof(arrayOfThree) << endl; // 12 = 3 * 4 байта
	cout << sizeof(intPointer) << endl; // 8, защото е просто указател
	cout << endl;

	test_sizeof(arrayOfFive, 5);

	// arrayOfThree++; - нелегално
	int *b = arrayOfThree;
	b++; // ок, защото е просто указател

	// Бонус - за тези, на които им се гледат още по-грозни неща:
	// Какво е това - int (*monsterFromHell) [20] ?

	return 0;
}
