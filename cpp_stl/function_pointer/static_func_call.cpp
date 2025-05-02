#include <iostream>

void Print (int n) 
{
    std::cout << "global function : " << n << std::endl;
}

namespace A {
    void Print (int n) 
    {
        std::cout << "global function in namespace A : " << n << std::endl;
    }
};

class Point {
public:
    static void Print (int n)
    {
        std::cout << "static member funtion of Point class : " << n << std::endl;
    }
};

int main()
{
    void (*pf) (int);

    Print(10);          // 1. Global function call without namespace
    A::Print(10);       // 2. Global functoin call in namepace A
    Point::Print(10);   // 3. Calling a static member fuction of the Point class

    pf = Print;         // The name of a function is the starting adress of the function.
    pf(10);
    pf = A::Print;
    pf(10);
    pf = Point::Print;
    pf(10);
}