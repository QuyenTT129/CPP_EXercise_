#include <stdexcept>
#include <functional>
#include <iostream>

class ReptileEgg;
class Reptile
{
public:
    virtual ~Reptile(){};
    virtual ReptileEgg *lay() = 0;
};
class ReptileEgg
{
    int hatchCount = 0; // Đếm số trứng nở
public:
    ReptileEgg(std::function<Reptile *()> createReptile) : hatchEgg(createReptile)
    {
    }
    Reptile *hatch()
    {
        std::cout << "hatch " << hatchCount << std::endl;
        if (hatchCount > 0)
        {
            throw std::logic_error("The egg already hatched");
        }
        hatchCount++;
        return hatchEgg();
    }

private:
    std::function<Reptile *()> hatchEgg; //[params_to_be_caprutred_from_current_context](arguments to the function) -> trailing_ret_type {function body}
};
class FireDragon : public Reptile
{
public:
    FireDragon()
    {
    }
    ReptileEgg *lay()
    {
        std::cout << "lay" << std::endl;
        return new ReptileEgg([]() -> Reptile *
                              { return new FireDragon; });
    }
};

#ifndef RunTests
int main()
{
    Reptile *fireDragon = new FireDragon();

    ReptileEgg *egg = fireDragon->lay();
    Reptile *childDragon = egg->hatch();
}
#endif
