#include "date.h"

#include <iostream>

using std::cout;
using std::endl;

bool is_leap(unsigned int year)
{
	bool is_candidate_leap = (year % 4 == 0);
	bool is_exception = ((year % 4 == 0) && (year % 100 == 0) && (year % 400 != 0));
	return is_candidate_leap && !is_exception;
}

unsigned int days_in_month(unsigned int month, unsigned int year)
{
	int days = 31;
	if(month == 4 || month == 6 || month == 9 || month == 11)
		days = 30;
	else if(month == 2)
		days = 28 + is_leap(year);
	return days;
}

bool is_invalid(unsigned int day, unsigned int month, unsigned int year)
{
	int max_allowed_day = days_in_month(month, year);
	bool invalid_day = (day < 1 || day > max_allowed_day);
	bool invalid_month = (month < 1 || month > 12);
	return invalid_day || invalid_month;
}

bool is_valid(unsigned int day, unsigned int month, unsigned int year)
{
	return !is_invalid(day, month, year);
}

Date create_date(unsigned int day, unsigned int month, unsigned int year)
{
	if (is_invalid(day, month, year))
	{
		day = 1;
		month = 1;
		year = 1970;
	}
	Date date;
	date._day = day;
	date._month = month;
	date._year = year;
	return date;
}


unsigned int get_day(Date date)
{
	return date._day;
}

unsigned int get_month(Date date)
{
	return date._month;
}

unsigned int get_year(Date date)
{
	return date._year;
}

void set_day(Date& date, unsigned int day)
{
	if (is_valid(day, date._month, date._year))
	{
		date._day = day;
	}
}

void set_month(Date& date, unsigned int month)
{
	if (is_valid(date._day, month, date._year))
	{
		date._month = month;
	}
}

void set_year(Date& date, unsigned int year)
{
	if (is_valid(date._day, date._month, year))
	{
		date._year = year;
	}
}

bool before(Date first, Date second)
{
	if (first._year < second._year)
		return true;
	if (first._year > second._year)
		return false;
	if (first._month < second._month)
		return true;
	if (first._month > second._month)
		return false;
	if (first._day < second._day)
		return true;
	return false;
}

bool same(Date first, Date second)
{
	return first._day == second._day &&
			first._month == second._month &&
			first._year == second._year;
}

bool after(Date first, Date second)
{
	return !before(first, second) && !same(first, second);
}

void add_years(Date& date, unsigned int years)
{
	if (date._month == 2 && date._day == 29)
	{
		date._month = 3;
		date._day = 1;
	}
	date._year += years;
}

void add_months(Date& date, unsigned int months)
{
	/*TODO Calculate better?*/
	while (months > 0)
	{
		--months;
		if (date._month == 12)
		{
			date._month = 1;
			add_years(date, 1);
		}
		else
		{
			date._month += 1;
		}
	}
}

void add_days(Date& date, unsigned int days)
{
	while (days > 0)
	{
		--days;
		if (date._day == days_in_month(date._month, date._year))
		{
			add_months(date, 1);
			date._day = 1;
		}
		else
		{
			date._day += 1;
		}
	}
}

void print_date(Date date)
{
	cout << date._day << "." << date._month << "." << date._year << endl;
}
