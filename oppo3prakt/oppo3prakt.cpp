#include <iostream>
#include <stdexcept>

#include "date.h"
#include "themeOfWorks.h"

//#include <cassert>

void readingInformation(std::vector<ThemeOfWorks>& PointerToTheVect, std::ifstream& ist)
{
	ThemeOfWorks bufStruct;
	while (!ist.eof())
	{
		bufStruct.ReadingTheTopicAndName(ist);
		PointerToTheVect.push_back(bufStruct);
	}
	ist.close();
}

void informationOutput(const std::vector<ThemeOfWorks>& PointerToTheVect, std::ostream& out)
{
	for (size_t i = 0; i < PointerToTheVect.size(); i++)
		PointerToTheVect.at(i).OutputToTheConsole(std::cout);
}

int main()
{
	std::ifstream ist("Themes Of Works.txt");
	if (!ist.is_open()) {
		std::cout << "The text file did not open" << std::endl;
		exit(0);
	}

	try {
		auto PointerToTheVect = std::vector<ThemeOfWorks>();
		readingInformation(PointerToTheVect, ist);
		printf("\tName\tTopic\tDate\n");
		informationOutput(PointerToTheVect, std::cout);
	}

	catch (const std::runtime_error& err)
	{
		std::cerr << err.what() << std::endl;
	}

	return 0;
}