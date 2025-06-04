#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n;
int sol;
int all;
vector<int> v;
queue<int> q;
bool visited[51];
int arr[51][51];

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for(int j = 0; j < n; j++)
        {
            if('a' <= s[j] && s[j] <= 'z')
            {
                arr[i][j] = s[j] - 'a' + 1;
            }
            else if('A' <= s[j] && s[j] <= 'Z')
            {
                arr[i][j] = s[j] - 'A' + 27;
            }
            all += arr[i][j];
        }
    }

    visited[0] = true;
    q.push(0);
    v.push_back(0);
    while(!q.empty())
    {
        q.pop();
        int m = 1e9;
        int idx = -1;
        for(int i = 0; i < v.size(); i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(visited[j]) continue;
                
                int cur = 1e9;
                if(arr[v[i]][j] != 0) cur = min(cur, arr[v[i]][j]);
                if(arr[j][v[i]] != 0) cur = min(cur, arr[j][v[i]]);
                if(m > cur && cur != 1e9)
                {
                    m = cur;
                    idx = j;
                }
            }
        }

        if(idx != -1)
        {
            sol += m;
            visited[idx] = true;
            v.push_back(idx);
            q.push(idx);
        }
    }

    if(v.size() != n)
    {
        cout << "-1";
    }
    else
    {
        cout << all - sol;
    }
}