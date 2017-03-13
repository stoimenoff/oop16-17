#ifndef __DATE_H__
#define __DATE_H__

struct Date;

/*
	Creates a date by given day, month and year.
	If the date happens to be invalid, returns a Date containng 1.1.1970
*/
Date create_date(unsigned int day, unsigned int month, unsigned int year);

/*
	Get a property from a Date object.
*/
unsigned int get_day(Date date);
unsigned int get_month(Date date);
unsigned int get_year(Date date);

/*
	Set a property of a Date object.
	If the property happens to be invalid, the setting is ignored.
*/
void set_day(Date& date, unsigned int day);
void set_month(Date& date, unsigned int month);
void set_year(Date& date, unsigned int year);

/*
	Chronological comparing functions for Date objects.
*/
bool before(Date first, Date second);
bool after(Date first, Date second);
bool same(Date first, Date second);

/*
	Adding days, months or years to a Date object.
*/
void add_days(Date& date, unsigned int days);
void add_months(Date& date, unsigned int months);
void add_years(Date& date, unsigned int years);

void print_date(Date date);

struct Date
{
	unsigned int _month;
	unsigned int _day;
	unsigned int _year;
};

#endif
