#include <iostream>
#include <vector>
using namespace std;

int main () 
{
    vector<int> v;
    
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    for(vector<int>::size_type i = 0; i < v.size(); i++) 
    {
        cout << v[i] << endl;
    }
    cout << typeid(vector<int>::size_type).name() << endl;

    cout << v.size() << endl;
    cout << v.capacity() << endl;
    cout << v.max_size() << endl;

    return 0;
}