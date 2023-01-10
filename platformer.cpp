#include <stdexcept>
#include <iostream>
#include <vector>
class Platformer
{
    int n1, position1;
    std::vector<int> v;
    
public:

    Platformer(int n, int position)
    {
       position1= position;
        n1= n;
        for (int i = 0; i < n; i++) {
            v.push_back(i);
        }
    }
    void jumpLeft()
    {
        v.erase(v.begin() + position1);
        position1= position1 -2;

      
    }
    void jumpRight()
    {
        v.erase(v.begin() + position1);
        position1 = position1 + 1;// Đi sang phải nên position bị xoá mất rồi
        
    }

    int position()
    {
        return v[position1];
    }
};
#ifndef RunTests
int main()
{
  
    Platformer platformer(6, 3);
    std::cout << platformer.position() << std::endl; // should print 3
    platformer.jumpLeft();
    std::cout << platformer.position() << std::endl; // should print 1
    platformer.jumpRight();
    std::cout << platformer.position() << std::endl; // should print 4
}
#endif
