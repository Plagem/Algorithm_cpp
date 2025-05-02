#include <iostream>

class Point {
private:
    int x;
    int y;
public:
    Point(int _x = 0, int _y = 0) : x(_x), y(_y) {} // ????
    void print() const 
    {
        std::cout << x << ", " << y << std::endl;
    }
    int getX() const { return x; }
    int getY() const { return y; }
};

const Point operator+ (const Point& arg1, const Point& arg2) 
{
    return Point (arg1.getX() + arg2.getX(), arg1.getY() + arg2.getY());
}

const Point operator- (const Point& arg1, const Point& arg2) 
{
    return Point (arg1.getX() - arg2.getX(), arg1.getY() - arg2.getY());
}

bool operator== (const Point& arg1, const Point& arg2) 
{
    return arg1.getX() == arg2.getX() && arg1.getY() == arg2.getY() ? true : false;

    
    //return arg1.getX() == arg2.getX() && arg1.getY() == arg2.getY() ? true : false;
}

int main () 
{
    Point p1(3,6), p2(5,5);
    Point p3 = p1 + p2;
    Point p4 = p1 - p2;

    p3.print();
    p4.print();

    if (p3 == p4) {
        std::cout << "p3과 p4는 동일합니다" << std::endl;
    } else {
        std::cout << "p3과 p4는 동일하지 않습니다" << std::endl;
    }
}