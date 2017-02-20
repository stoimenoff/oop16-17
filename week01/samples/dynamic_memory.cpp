#include <iostream>
using namespace std;

void memory()
{
	/* Локален масив в стека на main фунцкията.
		Ще бъде изтрит когато фунцкията приключи. */
	int stackArray[20];
	/* Указател към памет в heap-a.
		Понеже само самият указател е локален за функцията, само той ще
		бъде изтрит, когато тя приключи. "Сочената" от него памет
		трябва да се освободи "ръчно".
		*/
	int* heapArray = new int[20];

	delete[] heapArray;
}

int* allocate_array(unsigned int size)
{
	return new int[size];
}

int main()
{
	memory();

	int *arr = allocate_array(100);

	return 0;
	/* Класически memory leak - заделената от allocate_array памет в heap-a
		не се освобождава.
	*/
}
