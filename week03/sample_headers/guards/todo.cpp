#include "todo.h"
#include <cstring>

Task create_todo(const char* title, double priority)
{
	Task todo;

	unsigned int length = strlen(title);
	for (int i = 0; i < length; ++i)
		todo.title[i] = title[i];
	todo.title[length] = '\0';

	todo.priority = priority;
	return todo;
}
