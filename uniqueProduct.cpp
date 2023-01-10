#include <stdexcept>
#include <iostream>
#include <string>
#include <vector>

std::string firstUniqueProduct( std::vector<std::string>& products)
{   // Tạo vector duy nhất
    for (int i = 0; i < products.size(); i++) {
        for (int j = i + 1; j < products.size(); j++) {
            if (products[i] == products[j]) {
                products.erase(products.begin() + i);
                products.erase(products.begin() + j);
            }
        }
    }
    //Check xem vector có rỗng không
    if (products.empty()){
        return "";
    }
    else
    return products[0]; // In ra sp đầu tiên
}

#ifndef RunTests
int main()
{
    std::vector<std::string> products = { "Apple", "Computer", "Apple", "Bag" };
    std::cout << firstUniqueProduct(products);
}
#endif
