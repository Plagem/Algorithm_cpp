#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
set<vector<int>> v[11];
vector<int> num;

void iter(int depth, vector<int> input)
{
    for(int i = 0; i < input.size(); i++)
    {
        for(int j = i+1; j < input.size(); j++)
        {
            if(i == 0 && input[j] == 0) continue;
            swap(input[i], input[j]);
            v[depth+1].insert(input);
            swap(input[i], input[j]);
        }
    }
}

int main()
{
    cin >> n >> k;
    while(n)
    {
        num.push_back(n%10);
        n /= 10;
    }
    reverse(num.begin(), num.end());
    v[0].insert(num);

    // bfs 시작
    for(int i = 0; i < k; i++)
    {
        for(auto it = v[i].begin(); it != v[i].end(); it++)
        {
            iter(i, *it);
        }
    }

    int sol = 0;
    for(auto it = v[k].begin(); it != v[k].end(); it++)
    {
        vector<int> cur = *it;
        int curint = 0;
        for(int i = 0; i < cur.size(); i++)
        {
            curint *= 10;
            curint += cur[i];
        }
        sol = max(sol, curint);
    }

    if(sol != 0)
        cout << sol;
    else
        cout << "-1";
}