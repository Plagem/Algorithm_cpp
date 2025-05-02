#include <iostream>

class Adder 
{
    int total;
public:
    explicit Adder(int n = 0) : total(n) {}
    int operator() (int n) 
    {
        return total += n;
    }
};

int main()
{
    Adder add(0);

    std::cout << add(10) << std::endl;
    std::cout << add(20) << std::endl;
    std::cout << add(30) << std::endl;

    return 0;
}