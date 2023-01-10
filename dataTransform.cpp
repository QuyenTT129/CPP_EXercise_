#include <stdexcept>
#include <iostream>
#include <vector>
#include <string>
std::vector<std::string> transformDateFormat(std::vector<std::string> dates)
{
	for (int i = 0; i < dates.size(); i++) {
		if (dates[i].find("/") == 4 ) {
			std::string date, month, year; // Khai báo chuỗi string

			year = dates[i].substr(0, 4); // Lấy được năm luôn

			// Chọn ngày/ tháng
			int s1 = stoi(dates[i].substr(5, 7));
			int s2 = stoi(dates[i].substr(8, 10));
			if (s1 > 12) {
				date = std::to_string(s1); // int to string
				month = std::to_string(s2);
			}
			else {
				date = std::to_string(s2);
				month = std::to_string(s1);
			}

			dates[i] = year + month + date;

		}


		else if (dates[i].find("/") == 2  ) {
			std::string date, month, year; // Khai báo chuỗi string

			year = dates[i].substr(6, 10); // Lấy được năm luôn

			// Chọn ngày/ tháng
			int s1 = stoi(dates[i].substr(0, 2));
			int s2 = stoi(dates[i].substr(3, 5));
			if (s1 > 12) {
				date = std::to_string(s1); // int to string
				month = std::to_string(s2);
			}
			else {
				date = std::to_string(s2);
				month = std::to_string(s1);
			}

			dates[i] = year + month + date;

		}

		else if (dates[i].find("-") == 2 && dates[i].find("-") == 2) {
			std::string date, month, year; // Khai báo chuỗi string

			year = dates[i].substr(6, 10); // Lấy được năm luôn

			 //Chọn ngày/ tháng
			int s1 = stoi(dates[i].substr(0, 2));
			int s2 = stoi(dates[i].substr(3, 5));
			if (s1 > 12) {
				date = std::to_string(s1); // int to string
				month = std::to_string(s2);
			}
			else {
				date = std::to_string(s2);
				month = std::to_string(s1);
			}

			dates[i] = year + month + date;

		}

		else if (dates[i].find("-") == 4 ) {
			std::string date, month, year; // Khai báo chuỗi string

			year = dates[i].substr(0, 4); // Lấy được năm luôn

			 //Chọn ngày/ tháng
			int s1 = stoi(dates[i].substr(5, 7));
			int s2 = stoi(dates[i].substr(8, 10));
			if (s1 > 12) {
				date = std::to_string(s1); // int to string
				month = std::to_string(s2);
			}
			else {
				date = std::to_string(s2);
				month = std::to_string(s1);
			}

			dates[i] = year + month + date;

		}
		 else{
			 dates[i].erase();
		 }
	
			
		
		 
	}
	return dates;

}


#ifndef RunTests
int main()
{
	std::vector<std::string> dates = { "2010/02/20", "19/12/2016", "11-18-2012", "20130720" };

	std::vector<std::string> reformattedDates = transformDateFormat(dates);
	for (auto const& reformattedDate : reformattedDates)
	{
		std::cout << reformattedDate << std::endl;
	}
}
#endif

// Chưa bắt Exception: Ví dụ 02/01/2022