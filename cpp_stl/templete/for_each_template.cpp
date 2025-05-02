#include <iostream>
#include <string>
using namespace std;

template <typename IterT, typename Func>
void For_each(IterT begin, IterT end, Func pf) 
{
    while(begin != end)
    {
        pf(*begin++);
    }
}

template <typename T>
struct PrintFunctor
{
    string sep;

    explicit PrintFunctor(const string _sep = " ") : sep(_sep) {}

    void operator() (T data) const
    {
        cout << data << sep;
    }
};

int main ()
{
    int arr[5] = {10, 20, 30, 40, 50};
    For_each(arr, arr+5, PrintFunctor<int>());
    cout << endl;

    string sarr[3] = {"C++", "Hello", "World!"};
    For_each(sarr, sarr+3, PrintFunctor<string>("\n"));


    cout << endl;

    return 0;
}