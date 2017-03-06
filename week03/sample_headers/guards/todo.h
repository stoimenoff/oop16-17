#ifndef __TODO_H__
#define __TODO_H__

struct Task
{
	char title[25];
	double priority;
};

Task create_todo(const char* title, double priority = 5);

#endif
