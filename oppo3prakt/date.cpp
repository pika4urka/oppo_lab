#include "date.h"

#include <vector>
#include <iostream>
#include <stdexcept>


bool Date::DateChecking() //CheckingTheDateForCorrectness
{
	if (
		(day > 0) && (day < 32) &&
		(month > 0) && (month < 13) &&
		(year > 0) && (year < 2024)
		)
	{
		if ((day == 31) && (month % 2 == 0))
			return false;
	}
	else
		return false;

	if (year % 4 == 0)
	{
		if (month == 2)
			if (day > 29)
				return false;
	}
	else
	{
		if (month == 2)
			if (day > 28)
				return false;
	}
	return true;
}

void Date::ReadingTheDate(std::istream& ist)
{
	char buf[2];
	ist >> day;
	ist.get(buf[0]);
	ist >> month;
	ist.get(buf[1]);
	ist >> year;

	if ((buf[0] != '.') || (buf[1] != '.'))
		throw std::runtime_error{ "date is invalid" };

	if ((ist.fail()) || !DateChecking())
	{
		day = 0;
		month = 0;
		year = 0;
		throw std::runtime_error{ "date is invalid" };
	}
}

void Date::DateOutput(std::ostream& out) const
{
	out << day << "."
		<< month << "."
		<< year << "\n";
}

const size_t& Date::get_day() const
{
	return day;
}

const size_t& Date::get_month() const
{
	return month;
}

const size_t& Date::get_year() const
{
	return year;
}