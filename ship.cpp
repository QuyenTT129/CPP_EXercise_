#include <iostream>
#include <functional>



//Dùng Mảng động tiêu thụ ít memory hơn thằng cu Map
// std::function<int(int)> : Pointer Function
//Mỗi container được điền vào constructor
class Ship
{
private:
    int containerCount;
    int* containers = new int[containerCount];
public:
    Ship(int containerCount, std::function<int(int)> fillContainer)
    {
        this->containerCount = containerCount;
        for (int i = 0; i < containerCount; i++)
        {
            containers[i] = fillContainer(i);
        }

    }
    int peekContainer(int containerIndex)
    {
        return containers[containerIndex];
    }

};

#ifndef RunTests
int main()
{
    Ship ship(100, [](int containerIndex) { return containerIndex; });
    for (int i = 0; i < 100; i++) {
        std::cout << "Container: " << i << ", cargo: " << ship.peekContainer(i) << "\n";
    }
}
#endif
