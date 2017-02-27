#include <iostream>

using std::cout;
using std::cin;
using std::endl;

const int MAX_TITLE_SIZE = 24;
const int MAX_DESCRIPTION_SIZE = 300;

struct Task
{
	char title[MAX_TITLE_SIZE];
	double priority;
	char description[MAX_DESCRIPTION_SIZE];
};

void print_task(Task task)
{
	cout << task.title << endl;
	cout << task.priority << endl;
	cout << task.description << endl;
}

Task read_task()
{
	Task task;
	cin.getline(task.title, MAX_TITLE_SIZE);
	cin >> task.priority;
	cin.ignore();
	cin.getline(task.description, MAX_DESCRIPTION_SIZE);
	return task;
}

Task* read_tasks(unsigned int& size)
{
	unsigned int n;
	cin >> n;
	cin.ignore();
	size = n;
	Task *tasks = new Task[n];
	for (unsigned int i = 0; i < n; ++i)
	{
		tasks[i] = read_task();
	}
	return tasks;
}

void print_tasks(Task* tasks, unsigned int size)
{
	for (unsigned int i = 0; i < size; ++i)
		print_task(tasks[i]);
}

int main()
{
	unsigned int size = 0;
	Task* tasks = read_tasks(size);

	print_tasks(tasks, size);

	return 0;
}
