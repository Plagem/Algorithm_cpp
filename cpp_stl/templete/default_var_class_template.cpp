#include <iostream>
#include <string>

template<typename T=int, int capT=100>
class Array 
{
    T* buf;
    int size;
    int capacity;
public:
    explicit Array(int cap = capT) : buf(0), size(0), capacity(cap) 
    {
        buf = new T[capacity];
    }

    ~Array() { delete [] buf; }
    
    void Add(T data) 
    {
        buf[size++] = data;
    }

    T operator[] (int idx) 
    {
        return buf[idx];
    }

    int getSize() 
    {
        return size;
    }
};

int main()
{
    Array<> iarr; // using default parameter, int, 100
    iarr.Add(10);
    iarr.Add(20);
    iarr.Add(30);
    for(int i = 0; i < iarr.getSize(); i++)
        std::cout << iarr[i] << " " ;
    std::cout << std::endl;

    Array<double> darr;
    darr.Add(1.1);
    darr.Add(2.2);
    darr.Add(3.3);
    for(int i = 0; i < darr.getSize(); i++)
        std::cout << darr[i] << " " ;
    std::cout << std::endl;

    Array<std::string, 10> sarr;
    sarr.Add("C++");
    sarr.Add("Hello");
    sarr.Add("World!");
    for(int i = 0; i < sarr.getSize(); i++)
        std::cout << sarr[i] << " " ;
    std::cout << std::endl;   

    return 0;
}