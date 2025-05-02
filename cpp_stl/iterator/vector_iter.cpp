#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // 템플릿으로 정의된다.
    vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    //vector<int>::iterator veciter;
    for(auto veciter = v.begin(); veciter != v.end(); veciter++)
    {
        int n = *veciter;
        n = n*2;
        *veciter = n;
    }

    for(auto veciter = v.begin(); veciter != v.end(); veciter++)
    {
        cout << *veciter << endl;
    }
}