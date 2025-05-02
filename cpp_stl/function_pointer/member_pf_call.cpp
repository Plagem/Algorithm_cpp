#include <iostream>

class Point
{
    int x;
    int y;
public:
    explicit Point (int _x = 0, int _y = 0) : x(_x), y(_y) {}
    void Print() const { std::cout << x << ", " << y << std::endl; }
    void PrintInt(int n) { std::cout << "test Integer : " << n << std::endl; }
};

int main () 
{
    Point pt(2, 3);
    Point *p = &pt;

    void (Point::*pf1) () const;
    pf1 = &Point::Print; // 'pf1' is an starting adress of Point::Print()
    //'*pf1' is Point::Print()

    void (Point::*pf2) (int n);
    pf2 = &Point::PrintInt;

    pt.Print();
    pt.PrintInt(10);
    std::cout << std::endl;

    (pt.*pf1) (); 
    (pt.*pf2) (10);
    std::cout << std::endl;

    (p->*pf1) ();
    (p->*pf2) (10);

    return 0;
}