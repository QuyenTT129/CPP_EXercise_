#include <vector>
#include <stdexcept>
#include <iostream>
#include <map>
// Sử dụng Map(C1)
// Ngoài ra có thể sử dụng chỉ số vector làm key(C2)
// Hoặc thêm thư viện, sắp xếp(sort) lại rồi đếm (C3)
int nthLowestSelling(const std::vector<int>& sales, int n) 
{
    std::map<int, int> count; // Map key:value là duy nhất
	

	for (int i = 0; i <sales.size();i++){
		count[sales[i]]++;// Nếu bị trùng thì value ++
	}
    return count[n]; // Bán ế thứ n
	
}

#ifndef RunTests
int main()
{
    std::vector<int> input;
    input.push_back(5);
    input.push_back(4);
    input.push_back(3);
    input.push_back(2);
    input.push_back(1);
    input.push_back(5);
    input.push_back(4);
    input.push_back(3);
    input.push_back(2);
    input.push_back(5);
    input.push_back(4);
    input.push_back(3);
    input.push_back(5);
    input.push_back(4);
    input.push_back(5);
    int x = nthLowestSelling(input, 2);
    std::cout << x;
}
#endif

