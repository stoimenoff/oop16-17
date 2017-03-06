#include <iostream>
#include "todoprint.h"
using std::cout;
using std::endl;
void print_todos(Task* todos, unsigned int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << todos[i].title << " - " << todos[i].priority << endl;
	}
}
