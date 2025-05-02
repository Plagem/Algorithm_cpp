// 2025.01.27
// 그리디알고리즘 & 정렬

#include <iostream>
#include <algorithm>

int at[300001];
int as[300001];

int comp(int a, int b)
{
    return a > b;
}

using namespace std;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, K;
    cin >> N >> K;
    for(int i = 0; i < N; i++)
    {
        cin >> at[i];
    }

    for(int i = 1; i < N; i++)
    {
        as[i-1] = at[i] - at[i-1];
    }

    sort(as, as+N-1, comp);

    int sol = 0;
    for(int i = K-1; i < N-1; i++)
    {
        sol += as[i];
    }
    
    cout << sol;
}
