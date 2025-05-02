#include <iostream>

int main()
{
    int N;
    std::cin >> N;
    if(N%7==0||N%7==2) std::cout<<"CY";
    else std::cout<<"SK";
}