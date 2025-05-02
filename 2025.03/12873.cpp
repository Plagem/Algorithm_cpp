#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
    {
        v[i] = i+1;
    }

    auto it = v.begin();
    for(int i = 1; i < n; i++)
    {
        long long num = ((long long)i*i*i - 1) % v.size();
        for(int j = 0; j < num; j++)
        {
            it++;
            if(it == v.end()) it = v.begin();
        }
        it = v.erase(it);
        if(it == v.end()) it = v.begin();
    }

    cout << v[0];
}