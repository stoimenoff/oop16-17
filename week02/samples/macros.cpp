#include <iostream>

using std::cout;
using std::endl;

#define BABA 20

#define fun(x) -x

int main()
{
	cout << fun(10) << endl;

	cout << BABA << endl;

	cout << __FILE__ << endl;
	cout << __LINE__ << endl;
	cout << __DATE__ << endl;
	cout << __TIME__ << endl;
	cout << __cplusplus << endl;

	int n = 55;

	n += BABA;

	cout << n << endl;

	return 0;
}
