#include "LinkedList.h"
#include <iostream>

using std::cout;
using std::endl;
using std::boolalpha;

int main()
{
	LinkedList test;
	test.push_front(1);
	test.push_front(2);
	test.push_front(3);
	test.push_front(4);
	test.push_front(5);
	test.print();

	test.reverse();
	LinkedList other;
	other.push_front(1);
	other.push_front(2);
	other.push_front(3);
	other.push_front(4);
	other.push_front(5);

	(test+other).print();

	test.remove_after(2);
	test.print();

	cout << boolalpha << test.member(3) << endl;
	cout << test.size() << endl;

	return 0;
}
