#include <iostream>
#include <algorithm>

struct print1 
{
    void operator() (int n)
    {
        std::cout << n << " ";
    }
};

struct print2 
{
    void operator() (int n)
    {
        std::cout << n*n << " ";
    }
};

struct print3
{
    void operator() (int n)
    {
        std::cout << "integer : " << n << std::endl;
    }
};

int main ()
{
    int arg[5] = {10,20,30,40,50};

    std::for_each(arg, arg+5, print1());
    std::cout << std::endl << std::endl;
    std::for_each(arg, arg+5, print2());
    std::cout << std::endl << std::endl;
    std::for_each(arg, arg+5, print3());
    std::cout << std::endl << std::endl;

    return 0;
}