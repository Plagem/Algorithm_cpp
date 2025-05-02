// 2025.01.14
// LCS (Longest Common Subsequence)

#include <iostream>
#include <string>
using namespace std;

string s1, s2;
int dp[1001][1001];
bool visited[1001][1001];

int func(int x, int y)
{  
    if(visited[x][y]) return dp[x][y];
    visited[x][y] = true;

    // 한놈의 길이가 0이면 공통부분 최대 길이는 0이다
    if(x == 0 || y == 0)
    {
        dp[x][y] = 0;
        return 0;
    }

    if(s1[x-1] != s2[y-1])
    {
        dp[x][y] = max(func(x-1, y), func(x, y-1));
    }
    else
    {
        dp[x][y] = func(x-1, y-1) + 1;
    }

    return dp[x][y];
}

int main()
{
    cin >> s1 >> s2;
    cout << func(s1.length(), s2.length());
}