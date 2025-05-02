#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int arr[9][9];

int main()
{
    // Input
    int N, M;
    cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        for(int j = 0; j < M; j++)
        {
            arr[i][j] = s[j] - '0';
        }
    }

    // Logic
    int sol = -1;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            // arr[i][j] 시작지점
            for(int ii = -8; ii < 9; ii++)
            {
                for(int jj = -8; jj < 9; jj++)
                {
                    int temp = 0;

                    if(ii == 0 && jj == 0)
                    {
                        temp = arr[i][j];
                    }
                    else
                    {
                        // i칸 ii만큼 움직이게하고 j칸 jj만큼 움직이게 한다
                        int curi = i; int curj = j;
                        while(true)
                        {
                            temp = temp * 10 + arr[curi][curj];
                            curi += ii; curj += jj;
                            if(sqrt(temp) == int(sqrt(temp)))
                            {
                                sol = max(sol, temp);
                            }
                            if(0 > curi || curi >= N || 0 > curj || curj >= M) break;
                        }
                    }
                    if(sqrt(temp) == int(sqrt(temp)))
                    {
                        sol = max(sol, temp);
                    }
                }
            }
        }
    }
    
    cout << sol;
}