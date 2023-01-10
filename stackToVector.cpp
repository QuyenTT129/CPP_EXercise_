#include <iostream>
#include<vector>
#include<stack>

//Select the computational complexity of the stackToVector function if the reverseItems argument is false: O(n)
//Selectback  the computational complexity of the stackToVector function if the reverseItems argument is true: O(n*log(n))
// Push_back dùng đỡ tốn thời gian hơn insert: Vì thằng push_back chỉ push vào cuối nhanh hơn nhiều
template <typename T>
std::vector<T> stackToVector(std::stack<T> stack, bool reverseItems) {
    std::vector<T> items(stack.size());
    while (stack.size() > 0)
    {
        T item = stack.top();
        stack.pop();

        if (reverseItems) {
            items.insert(items.begin(), item);
        }
        else {
            items.push_back(item);
        }
    }
    return items;
}

int main() {
    std::stack<int> mystack;

    for (int i = 0; i < 5; ++i) {
        mystack.push(i);
    }



    for (int i = 0; i < 5; i++) {
        std::cout << stackToVector(mystack, false)[i]<<std::endl;
    }
}