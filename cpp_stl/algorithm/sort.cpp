#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

int main ()
{
    vector<int> v;

    v.push_back(50);
    v.push_back(10);
    v.push_back(20);
    v.push_back(40);
    v.push_back(30);

    sort(v.begin(), v.end(), less<int>());
    for(auto iter = v.begin(); iter != v.end(); iter++)
        cout << *iter << " ";
    cout << endl;

    sort(v.begin(), v.end(), greater<int>());
    for(auto iter = v.begin(); iter != v.end(); iter++)
        cout << *iter << " ";
    cout << endl;

    auto iter2 = v.begin() + 1;
    cout << *iter2 << endl;
    iter2--;
    cout << *iter2 << endl;
}