#include <iostream>

#include "date.h"

using std::cout;
using std::endl;
using std::boolalpha;

int main()
{
	Date d1 = create_date(17, 5, 1972);

	cout << "day: " << get_day(d1) << endl;
	cout << "month: " << get_month(d1) << endl;
	cout << "year: " << get_year(d1) << endl;

	cout << endl << "Set day, month & year:" << endl;
	set_day(d1, 20);
	set_month(d1, 2);
	set_year(d1, 2004);
	print_date(d1);

	cout << endl << "Add days:" << endl;

	add_days(d1, 366 + 3 * 365);
	print_date(d1);

	cout << endl << "Add months:" << endl;

	add_months(d1, 14);
	print_date(d1);

	cout << endl << "Add years:" << endl;

	add_years(d1, 2);
	print_date(d1);

	Date d2 = create_date(21, 12, 2012);

	cout << endl;
	print_date(d1);
	print_date(d2);
	cout << boolalpha;
	cout << "before? " << before(d1, d2) << endl;
	cout << "after? " << after(d1, d2) << endl;
	cout << "same? " << same(d1, d2) << endl;

	return 0;
}
