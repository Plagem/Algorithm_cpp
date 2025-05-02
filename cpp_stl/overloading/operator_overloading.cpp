#include <iostream>

class Point {
private:
    int x;
    int y;

public:
    Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
    void Print() const {std::cout << x << ',' << y << std::endl;}
    const Point operator+ (const Point arg) const; // operator 함수 안에서는 어떤 변수도 바꿀 수 없다.   const를 {} 에 적용시킨다고 생각하면 편함.
    bool operator== (const Point arg) const{
        return x == arg.x && y == arg.y ? true : false;
    }
};

const Point Point::operator+ (const Point arg) const 
{
    Point pt;
    pt.x = this -> x + arg.x;
    pt.y = this -> y + arg.y;
    return pt;
}



int main () 
{
    Point p1(1, 2), p2(2, 3), p4(3, 5);
    Point p3;
    p3 = p1 + p2; // 연산자 오버로딩
    p3.Print();
    p3 = p1.operator+(p2); // 직접 호출
    p3.Print();

    if (p3 == p4) {
        std::cout << "p3과 p4는 동일합니다." << std::endl;
    } else {
        std::cout << "p3과 p4는 동일하지 않습니다" << std::endl;
    }
    return 0;
}

// ????? ctrl + alt + C
// exe???? ?????? ctrl + alt + R