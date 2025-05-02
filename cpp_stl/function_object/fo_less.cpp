#include <iostream>

bool Pred_less(int a, int b)
{
    return a < b;
}

struct Less
{
    bool operator() (int a, int b)
    {
        return a < b;
    }
};

int main()
{
    Less l; // l is struct

    std::cout << Pred_less(10, 20) << std::endl;
    std::cout << Pred_less(10, 20) << std::endl;
    std::cout << std::endl;
    std::cout << l(10, 20) << std::endl;
    std::cout << l(20, 10) << std::endl;
    std::cout << Less () (10,20) << std::endl; // 임시 객체로 암묵적 함수 호출
    std::cout << Less () (20,10) << std::endl;
    std::cout << std::endl;
    std::cout << l.operator() (10, 20) << std::endl; // 명시적 호출
    std::cout << Less().operator() (20, 10) << std::endl; // 명시적 호출, Less() 는 임시 객체를 생성한다 (l과 같은 상태)
}