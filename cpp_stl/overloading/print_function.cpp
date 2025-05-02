#include <iostream>

struct FunObject 
{
public:
    void operator() (int arg) const // 함수 객체
    {
        std::cout << "정수 : " << arg << std::endl;
    }
};

void Print1(int arg)
{
    std::cout << "정수 : " << arg << std::endl; // 함수
}


int main ()
{
    void (*Print2)(int) = Print1;
    FunObject Print3;

    Print1(10); // 함수로 출력
    Print2(10); // 함수 포인터로 출력
    Print3(10); // 함수 객체로 출력

    return 0;
}