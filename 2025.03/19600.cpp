#include <iostream>
#include <vector>
using namespace std;

void solFuncBi(int arr[], int start, int end, int depth)
{
    if(start == end) arr[start] = depth;
    if(start >= end) return;
    arr[(start + end) / 2] = depth;
    solFuncBi(arr, start, (start+end)/2-1, depth+1);
    solFuncBi(arr, (start+end)/2+1, end, depth+1);
}

void solFuncTri(int arr[], int start, int end, int depth)
{
    if(start == end) arr[start] = depth;
    if(start >= end) return;

    int left = start + (end - start) / 3;
    int right = end - (end - start) / 3;

    arr[left] = depth;
    arr[right] = depth+1;

    solFuncTri(arr, start, left-1, depth+2);
    solFuncTri(arr, left+1, right-1, depth+2);
    solFuncTri(arr, right+1, end, depth+2);
}

int arrs[2][5001][5001];
// arrs[0]은 Bi
// arrs[1]은 Tri
// arrs[0][a][b]는 Bi에서 a크기 배열의 b원소 찾는 개수

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    for(int i = 1; i < 5001; i++) // 크기 : i
    {
        solFuncBi(arrs[0][i], 0, i-1, 0);
        solFuncTri(arrs[1][i], 0, i-1, 0);

        for(int j = 1; j < 5000; j++)
        {
            arrs[0][i][j] += arrs[0][i][j-1];
            arrs[1][i][j] += arrs[1][i][j-1];
        }
    }

    int q;
    cin >> q;
    while(q--)
    {
        int s, e, n; int sol = 0;
        cin >> n >> s >> e;
        int minus = s == 0 ? 0 : arrs[1][n][s-1];
        sol += (arrs[1][n][e] - minus);
        minus = s == 0 ? 0 : arrs[0][n][s-1];
        sol -= (arrs[0][n][e] - minus);
        cout << sol << "\n";
    }
}