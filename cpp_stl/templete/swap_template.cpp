#include <iostream>

template <typename T>
void Swap (T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

int main()
{
    int n1 = 10, n2 = 20;
    double d1 = 1.1; double d2 = 2.2;

    Swap(n1, n2);
    Swap(d1, d2);

    std::cout << n1 << ", " << n2 << std::endl;
    std::cout << d1 << ", " << d2 << std::endl;

    return 0;
}