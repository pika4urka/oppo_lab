#pragma once
#include <iostream>
#include "date.h"
#include <fstream>

class ThemeOfWorks
{
	std::string name;
	std::string topic;
	Date date;
public:
	ThemeOfWorks(std::string name, std::string topic, Date& date)
	{
		this->name = name; this->topic = topic; this->date = date;
	}

	ThemeOfWorks() { name = "no data available"; topic = "no data available"; }

	void OutputToTheConsole(std::ostream& out) const;
	void ReadingTheTopicAndName(std::istream& ist);

	const Date& get_date() const;
	const std::string& get_Name() const;
	const std::string& get_Theme() const;
};