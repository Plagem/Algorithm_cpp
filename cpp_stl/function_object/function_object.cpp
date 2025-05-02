#include <iostream>

void Print()
{
    std::cout << "public function!" << std::endl;
}

struct Functor
{
    void operator() (int a, int b)
    {
        std::cout << "function object : " << a << ", " << b << std::endl;
    }
};

int main()
{
    Functor functor;

    Print();
    functor(2, 3);

    return 0;
}