#include <iostream>

class Point {
private:
    int x;
    int y;

public:
    Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
    void Print() const {std::cout << x << ',' << y << std::endl;}
    const Point operator+ (const Point arg) const; // operator �Լ� �ȿ����� � ������ �ٲ� �� ����.   const�� {} �� �����Ų�ٰ� �����ϸ� ����.
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
    p3 = p1 + p2; // ������ �����ε�
    p3.Print();
    p3 = p1.operator+(p2); // ���� ȣ��
    p3.Print();

    if (p3 == p4) {
        std::cout << "p3�� p4�� �����մϴ�." << std::endl;
    } else {
        std::cout << "p3�� p4�� �������� �ʽ��ϴ�" << std::endl;
    }
    return 0;
}

// ????? ctrl + alt + C
// exe???? ?????? ctrl + alt + R