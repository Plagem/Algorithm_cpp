#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> arr;
vector<int> soinsu[5000001];
bool visited[5000001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // prime algorithm

    for(int i = 2; i <= 5000000; i++)
    {
        if(visited[i]) continue;
        int now;
        for(int j = i; j <= 5000000; j += i)
        {
            visited[j] = true;
            now = j;
            while(now % i == 0)
            {
                soinsu[j].push_back(i);
                now = now / i;
            }
        }
    }

    // Input
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        arr.push_back(t);
    }

    // Output
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < soinsu[arr[i]].size(); j++)
        {
            cout << soinsu[arr[i]][j] << " ";
        }
        cout << '\n';
    }
}
