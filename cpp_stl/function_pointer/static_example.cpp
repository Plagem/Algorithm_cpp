#include <iostream>

void auto_var_plus() 
{
    int num0 = 0;
    num0++;
    std::cout << num0 << std::endl;
}

void static_var_plus()
{
    static int num1 = 0;
    num1++;
    std::cout << num1 << std::endl;
}

int main()
{
    auto_var_plus();
    auto_var_plus();
    auto_var_plus();

    std::cout << std::endl;
    static_var_plus();
    static_var_plus();
    static_var_plus();

    return 0;
}