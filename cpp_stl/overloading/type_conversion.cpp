#include <iostream>

class A {

};

class B {
  public:
    B() { std::cout << "B() ������" << std::endl; }
    B(A& _a) {std::cout << "B(A _a) ������" << std::endl; }
    B(int n) {std::cout << "B(int n) ������" << std::endl; }
    B(double d) {std::cout << "B(double d) ������" << std::endl; }
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