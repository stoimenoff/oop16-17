#include <iostream>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::ifstream;

const int MAX_TITLE_SIZE = 24;
const int MAX_DESCRIPTION_SIZE = 300;

struct Task
{
	char title[MAX_TITLE_SIZE];
	double priority;
	char description[MAX_DESCRIPTION_SIZE];
};

Task read_task(ifstream& in)
{
	Task task;
	in.getline(task.title, MAX_TITLE_SIZE);
	in >> task.priority;
	in.ignore();
	in.getline(task.description, MAX_DESCRIPTION_SIZE);
	return task;
}

int main()
{
	const char* FILE_NAME = "tasks.txt";
	int n = 0;

	ifstream ginka(FILE_NAME);

	Task t1 = read_task(ginka);

	cout << t1.title << endl;
	cout << t1.priority << endl;
	cout << t1.description << endl;

	ginka.close();
	return 0;
}
