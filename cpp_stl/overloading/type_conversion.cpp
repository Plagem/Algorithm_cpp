#include <iostream>

class A {

};

class B {
  public:
    B() { std::cout << "B() 持失切" << std::endl; }
    B(A& _a) {std::cout << "B(A _a) 持失切" << std::endl; }
    B(int n) {std::cout << "B(int n) 持失切" << std::endl; }
    B(double d) {std::cout << "B(double d) 持失切" << std::endl; }
};

int main () 
{
    A a;
    int n = 10;
    double d = 5.5;
    
    B b;
    b = n;
    b = d;
    b = a;
}