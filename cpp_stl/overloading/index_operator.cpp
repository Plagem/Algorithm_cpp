#include <iostream>

class Array {
    int *arr;
    int size;
    int capacity;

public:
    Array(int cap = 100) : arr(0), size(0), capacity(cap)
    {
        arr = new int[capacity];
    }

    ~Array() 
    {
        delete [] arr;
    }

    void Add(int data)
    {
        if(size < capacity) {
            arr[size++] = data;
        }
    }

    void Del()
    {
        size--;
    }

    int Size() const
    {
        return size;
    }

    int operator[] (int idx) const
    {
        return arr[idx];
    }

    void Print() const
    {
        for(int i = 0 ; i < size ; i++)
            std::cout << arr[i] << std::endl;
    }
};

int main() 
{
    Array ar(10); // make array size of 10
    ar.Add(30);
    ar.Add(40);
    ar.Add(20);
    ar.Del();
    ar.Add(35);

    ar.Print();

    return 0;
}