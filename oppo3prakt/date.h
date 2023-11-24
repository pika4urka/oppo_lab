#pragma once
#include <fstream>
#include <vector>

class Date
{
	size_t day;
	size_t month;
	size_t year;

public:

	Date(size_t day, size_t month, size_t year)
	{
		this->day = day; this->month = month; this->year = year;
	}

	bool DateChecking();

	Date() : Date(11, 11, 2023) {}

	void ReadingTheDate(std::istream& ist);
	void DateOutput(std::ostream& out) const;

	const size_t& get_day() const;
	const size_t& get_month() const;
	const size_t& get_year() const;
};