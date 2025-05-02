// 2025.01.13
// Permutation

#include <iostream>

using namespace std;

int arr[8] = {1,2,3,4,5,6,7,8};
int permutation[8];
int N, M;

void func(int permutation[], int idx, int depth)
{
    if(depth == M)
    {
        for(int i = 0; i < M; i++)
        {
            cout << permutation[i] << " ";
        }
        cout << "\n";
    }
    else
    {
        for(int i = idx + 1; i <= N; i++)
        {
            permutation[depth] = i;
            func(permutation, i, depth+1);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    func(permutation, 0, 0);
}