#include <iostream>
#include <vector>
using namespace std;

int main () 
{
    vector<int> v;

    for(int i = 0; i < 11; i++) 
    { 
        cout << "size : " << v.size() << "   capacity : " << v.capacity() << endl;
        v.push_back(i);
    }

    for(vector<int>::size_type i = 0; i < v.size(); i++)
        cout << v[i] << " " ;
    cout << endl;

    return 0;
}