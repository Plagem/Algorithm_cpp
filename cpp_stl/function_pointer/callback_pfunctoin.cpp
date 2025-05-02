#include <iostream>


//////////////serever///////////////////
void For_each(int *begin, int *end, void (*pf) (int))
{
    while(begin != end)
    {
        pf(*begin++); // Callback client function
    }
}

//////////////client///////////////////
void Print1(int n) 
{
    std::cout << n << " ";
}
void Print2(int n)
{
    std::cout << n*n << " ";
}
void Print3(int n)
{
    std::cout << "integer : " << n << std::endl;
}

int main ()
{
    int arr[5] = {10, 20, 30, 40, 50};

    For_each(arr, arr+5, Print1);
    std::cout << std::endl << std::endl;
    For_each(arr, arr+5, Print2);
    std::cout << std::endl << std::endl;
    For_each(arr, arr+5, Print3);
    std::cout << std::endl << std::endl;
    
    return 0;
}