#include <iostream>
#include <cmath>
using namespace std;

int sol, sol1, sol2, sol3;
int n, m;
int arr[100][100];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};


int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int ii = 0; ii < m; ii++)
        {
            cin >> arr[i][ii];
        }
    }
    sol1 += n * m * 2;

    // for(int i = 0; i < n; i++)
    // {
    //     sol2 += arr[i][0];
    //     sol2 += arr[0][i];
    //     sol2 += arr[n-1][i];
    //     sol2 += arr[i][n-1];
    // }

    for(int i = 0; i < n; i++)
    {
        for(int ii = 0; ii < m; ii++)
        {
            for(int iii = 0; iii < 4; iii++)
            {
                int ni = i + dx[iii];
                int nii = ii + dy[iii];
                if(0 <= ni && ni < n && 0 <= nii && nii < m)
                {
                    sol3 += max(0, arr[i][ii] - arr[ni][nii]);
                }
                else
                {
                    sol3 += arr[i][ii];
                }
            }        
        }
    }

    cout << sol1+sol2+sol3;
}