#include <iostream>

using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M;
    cin >> N >> M;

    cout << N/2 + M/2 << "\n";

    for(int i = 1; i <= N; i++)
    {
        if(i%2 == 0)
        {
            cout << i << " 1 " << i << " " << M << "\n";
        }
    }

    for(int i = 1; i <= M; i++)
    {
        if(i%2 == 0)
        {
            cout << "1 " << i << " " << N << " " << i << "\n";
        }
    }
}