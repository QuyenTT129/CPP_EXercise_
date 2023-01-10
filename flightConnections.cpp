#include <iostream>
#include <vector>

int getMinimumConnections(const std::vector<std::vector<bool>>& matrix)
{
    int count = 0;
    for(int i = 0; i < matrix.size(); i++){
        for(int j = i+1; j<matrix.size() ; j++){
            if(matrix[i][j] == true){
                count++;
            }
        }
    }
    return (matrix.size() - 1) - count;
}

#ifndef RunTests
int main()
{
    std::vector<std::vector<bool>> matrix {
        {false, true, false, false, true},
        {true, false, false, false, false},
        {false, false, false, true, false},
        {false, false, true, false, false},
        {true, false, false, false, false}
    };
    std::cout << getMinimumConnections(matrix) << std::endl; // should print 2
    return 0;
}
#endif