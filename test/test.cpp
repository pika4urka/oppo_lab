#include <sstream>
#include <vector>
#include <array>

#include "pch.h"
#include "CppUnitTest.h"
#include "../oppo3prakt/date.h"
#include "../oppo3prakt/themeOfWorks.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test1
{

	TEST_CLASS(test3)
	{
	public:
		TEST_METHOD(constructor_test)
		{
			Date date(05, 10, 2004);
			size_t d, m, y;
			d = date.get_day();
			m = date.get_month();
			y = date.get_year();

			Assert::IsTrue(d == 5, L"Day");
			Assert::IsTrue(m == 10, L"Month");
			Assert::IsTrue(y == 2004, L"Year");
		}

		TEST_METHOD(constructor_default_test)
		{
			Date date;
			size_t d, m, y;
			d = date.get_day();
			m = date.get_month();
			y = date.get_year();

			Assert::IsTrue(d == 11, L"Day");
			Assert::IsTrue(m == 11, L"Month");
			Assert::IsTrue(y == 2023, L"Year");
		}

		TEST_METHOD(valid_date_reading_test)
		{
			Date date;
			size_t d1, m1, y1;
			const auto one = [&](const std::string& val, int d, int m, int y) {

				std::istringstream sin{ val };
				date.ReadingTheDate(sin);

				d1 = date.get_day();
				m1 = date.get_month();
				y1 = date.get_year();

				Assert::IsTrue(d1 == d, L"Day");
				Assert::IsTrue(m1 == m, L"Month");
				Assert::IsTrue(y1 == y, L"Year");
			};

			one("12.10.2020", 12, 10, 2020);
			one("10.11.2000", 10, 11, 2000);
			one("28.01.2005", 28, 01, 2005);
			one("05.10.2004", 05, 10, 2004);
		}

		TEST_METHOD(invalid_date_reading_test)
		{
			Date date;
			const auto func = [&]()
			{
				std::istringstream sin { "33.10.2000" };
				date.ReadingTheDate(sin);
			};

			Assert::ExpectException<std::runtime_error>(func);
		}

		TEST_METHOD(date_output_test)
		{
			Date date(5, 10, 2004);
			std::ostringstream ost;
			date.DateOutput(ost);
			std::string str = ost.str();

			Assert::IsTrue(str == "5.10.2004\n");
		}

		TEST_METHOD(DateChecking_valid)
		{
			const auto func = [&](std::vector<size_t*> cases)
			{
				for (size_t i = 0; i < 3; i++)
				{
					size_t* arr = cases.at(i);
					Date date(*(arr + 0), *(arr + 1), *(arr + 2));
					if (i != 2)
						Assert::IsTrue(date.DateChecking());
					else
						Assert::IsFalse(date.DateChecking());
					delete[] arr;
				}

			};

			std::vector<size_t*> cases;
			size_t* arr = new size_t[3];
			*(arr + 0) = 11; *(arr + 1) = 11; *(arr + 2) = 2023;
			cases.push_back(arr); arr = new size_t[3];
			*(arr + 0) = 29; *(arr + 1) = 2; *(arr + 2) = 2020;
			cases.push_back(arr); arr = new size_t[3];
			*(arr + 0) = 29; *(arr + 1) = 2; *(arr + 2) = 2021;
			cases.push_back(arr); arr = new size_t[3];

			func(cases);

		}

	};

	TEST_CLASS(test2)
	{
		TEST_METHOD(constructor_test)
		{
			Date date(10, 12, 2000);
			ThemeOfWorks stud("student", "Theme1", date);
			std::string name, theme;
			name = stud.get_Name();
			theme = stud.get_Theme();

			Assert::IsTrue(name == "student", L"Name");
			Assert::IsTrue(theme == "Theme1", L"Theme");
		}

		TEST_METHOD(constructor_default_test)
		{
			ThemeOfWorks stud;
			std::string name, theme;
			name = stud.get_Name();
			theme = stud.get_Theme();

			Assert::IsTrue(name == "no data available");
			Assert::IsTrue(theme == "no data available");
		}

		TEST_METHOD(valid_reading_test)
		{
			ThemeOfWorks stud;
			std::string name, theme;
			const auto one = [&](std::vector<std::string> str)
			{
				for (size_t i = 0; i < str.size(); i++)
				{
					std::istringstream sin{ str.at(i) };
					stud.ReadingTheTopicAndName(sin);
					sin >> name >> theme;

					Assert::IsTrue(name == stud.get_Name());
					Assert::IsTrue(theme == stud.get_Theme());
				}
			};

			std::vector<std::string> cases{
				"student theme4 12.10.2020 student theme4",
					"student theme1 10.11.2000 student theme1",
					"student theme2 28.01.2005 student theme2",
					"student theme3 05.10.2004 student theme3"
			};
		}

		TEST_METHOD(invalid_reading_test)
		{
			ThemeOfWorks stud;
			const auto func = [&]()
			{
				std::istringstream sin { "studen1t theme 33.10.2000" };
				stud.ReadingTheTopicAndName(sin);
			};

			Assert::ExpectException<std::runtime_error>(func);
		}

		TEST_METHOD(output_test)
		{
			Date date(5, 10, 2004);
			ThemeOfWorks stud("stud", "theme1", date);
			std::ostringstream ost;
			stud.OutputToTheConsole(ost);
			std::string str = ost.str();

			Assert::IsTrue(str == "\tstud\ttheme1\t5.10.2004\n");
		}
	};
}
