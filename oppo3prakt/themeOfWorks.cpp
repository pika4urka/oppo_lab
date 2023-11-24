#include "themeOfWorks.h"
#include <string>

bool checkingTheCorrectnessOfTheName(std::string Name)
{
	size_t sizestr = Name.size();
	for (size_t i = 0; i < sizestr; i++)
	{
		if (isdigit(Name[i]))
			return false;
	}
	return true;
}

void ThemeOfWorks::ReadingTheTopicAndName(std::istream& ist)
{
	ist >> name >> topic;

	if (!checkingTheCorrectnessOfTheName(name))
	{
		name = "no data available";
		topic = "no data available";
		throw std::runtime_error{ "name is invalid" };
	}

	date.ReadingTheDate(ist);
}

void ThemeOfWorks::OutputToTheConsole(std::ostream& out) const
{
	out << '\t' << name << '\t' << topic << '\t';
	date.DateOutput(out);
}

const Date& ThemeOfWorks::get_date() const
{
	return date;
}

const std::string& ThemeOfWorks::get_Name() const
{
	return name;
};
const std::string& ThemeOfWorks::get_Theme() const
{
	return topic;
};