#include <iostream>

template <typename T, int size>
void PrintArray (T* arr)
{
    for(int i = 0; i < size; i++)
    {
        std::cout << "[" << i << "]" << " : " << arr[i] << std::endl;
    }
    std::cout << std::endl;
}

int main()
{
    int arr1[5] = {10, 20, 30, 40, 50};
    PrintArray<int, 5>(arr1);

    double arr2[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    PrintArray<double, 5>(arr2);

    return 0;
}