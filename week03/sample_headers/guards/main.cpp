#include <iostream>

#include "todo.h"
#include "todoprint.h"

using std::cout;
using std::endl;

int main()
{
	Task todos[] = {create_todo("Baba", 4), create_todo("Dyado", 2)};
	unsigned int n = sizeof(todos) / sizeof(todos[0]);

	print_todos(todos, n);
	return 0;
}
