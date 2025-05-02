// S3) 10973 이전 순열 : 뭐지
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> v(n);

    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    bool flag = prev_permutation(v.begin(), v.end());
    if(!flag) cout << "-1";
    else
    {
        for(int i : v)
        {
            cout << i << " ";
        }
    }
}