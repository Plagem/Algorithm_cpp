//functor
#include <iostream>
using namespace std;

template <typename T>
struct Less 
{
    bool operator() (T a, T b) 
    {
        return a < b;
    }
};

template <typename T>
struct Greater 
{
    bool operator() (T a, T b) 
    {
        return a > b;
    }
};

int main () 
{
    cout << Less<int>()(10, 20) << endl;
}