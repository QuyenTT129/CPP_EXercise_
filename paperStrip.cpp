#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>

int minPieces(const std::vector<int> &original, const std::vector<int> &desired)
{
    int count = 0;

    for (int i = 0; i < original.size(); i++)
    {
        for (int j = 0; j < desired.size(); j++)
        {//Phần tử giống nhau
            if (original[i] == desired[j])
            {
                count++;
            }
            // 2 phần tử liền kề 2 vector giống nhau( Đã clear cho cả trường hợp n phần tử liền kề)
            if (original[i] == desired[j] && i + 1 < original.size() && j + 1 < desired.size() && original[i + 1] == desired[j + 1])
            {
                count--;
            }
        }
    }
    return count;
}

#ifndef RunTests
int main()
{
    std::vector<int> original = {1, 4, 3, 5, 9, 2, 7};
    std::vector<int> desired = {1, 2, 7, 4, 3, 5, 9};
    std::cout << minPieces(original, desired) << std::endl;
}
#endif