#include <iostream>

void For_each(int *begin, int *end, void (*pf) (int)) 
{
    while(begin != end)
    {
        pf(*begin++);
    }
}

void PrintInt(int n)
{
    std::cout << n << " ";
}

int main ()
{
    int arr[5] = {10, 20, 30, 40, 50};
    For_each(arr, arr+5, PrintInt);
    std::cout << std::endl;

    return 0;
}