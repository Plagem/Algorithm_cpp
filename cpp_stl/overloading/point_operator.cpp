#include <iostream>

class Point {
    int x;
    int y;
  public:
    Point(int _x, int _y) : x(_x), y(_y) {}
    void Print() const { std::cout << x << ", " << y << std::endl; }
};

class PointPtr {
    Point *ptr;
  public:
    PointPtr(Point *_ptr) : ptr(_ptr) {}

    ~PointPtr() {
        delete ptr;
    }

    Point& operator*() const {
        return *ptr; // 대상을 Reference 형태로 return한다.
    }

    Point* operator->() const {
        return ptr; // Pointptr이 소유하고 있는 ptr을 return한다.
    } 
};

int main () 
{
    PointPtr p1 = new Point(2,3); // Memory Assignment
    Point *p2 = new Point(5,5);
    
    p1->Print();
    p2->Print();
    std::cout << std::endl;
    
    // generic pointer like p1, p2 should be deleted manualy
    (*p1).Print();
    (*p2).Print();


    return 0;
}