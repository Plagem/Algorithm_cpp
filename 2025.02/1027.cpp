#include <iostream>
#include <vector>
using namespace std;

long long arr[50];

int main()
{
    int N;
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    int sol = 0;
    for(long long i = 0; i < N; i++)
    {
        int countSeeBuilding = 0;
        for(long long j = 0; j < N; j++)
        {
            if(i == j) continue;
            bool canSee = true;
            for(long long k = min(i, j) + 1; k < max(i, j); k++)
            {
                if(i - j < 0)
                {
                    if((arr[k] - arr[i]) * (i - j) <= (arr[i] - arr[j]) * (k - i))
                    {
                        canSee = false;
                    }
                }
                else
                {
                    if((arr[k] - arr[i]) * (i - j) >= (arr[i] - arr[j]) * (k - i))
                    {
                        canSee = false;
                    }
                }
            }
            if(canSee == true) countSeeBuilding++;
        }
        sol = max(sol, countSeeBuilding);
    }

    cout << sol;
}