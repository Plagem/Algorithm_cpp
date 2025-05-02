#include <iostream>
#include <cmath>
#include <bitset>
using namespace std;

int n;
bool visited[1048576];

void setVisited(bitset<20> bit)
{
    visited[(int)bit.to_ulong()] = true;
    for (int i = n - 1; i >= 0; --i)
        cout << bit[i];
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // Input
    cin >> n;
    bitset<20> cur, rev;
    cin >> cur;
    bitset<20> full;
    for(int i = 0; i < n; i++)
    {
        full.set(i, true);
    }
    
    // Initialize
    rev = cur^full;
    setVisited(cur);
    setVisited(rev);
    
    // 단순 반복 횟수를 주기 위한 for문
    for(int i = 2; i < pow(2, n); i+=2)
    {
        bitset<20> nCur;
        for(int j = 0; j < n; j++)
        {
            nCur = cur;
            nCur.flip(j);
            if(!visited[(int)nCur.to_ulong()]) break;
        }

        cur = nCur;
        rev = cur^full;
        setVisited(cur);
        setVisited(rev);
    }
}