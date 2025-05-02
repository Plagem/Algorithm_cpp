#include <iostream>
#include <tuple>
#include <algorithm>
#include <queue>

int dp[61][61][61];
int scv[3];
int attack[6][3] = {{9,3,1}, {9,1,3}, {3,9,1}, {3,1,9}, {1,9,3}, {1,3,9}};

using namespace std;

int main()
{
    int N;
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> scv[i];
    }
    
    for(int i = 0; i < 61; i++)
        for(int j = 0; j < 61; j++)
            for (int k = 0; k < 61; k++)
                dp[i][j][k] = 100;
    
    dp[0][0][0] = 0;
    queue<tuple<int, int, int>> q;
    q.push(make_tuple(0,0,0));
    
    while(!q.empty())
    {
        tuple<int,int,int> t = q.front();
        q.pop();
        
        for(int i = 0; i < 6; i++)
        {
            int arr[3] = {get<0>(t) + attack[i][0], get<1>(t) + attack[i][1], get<2>(t) + attack[i][2]};
            for(int j = 0; j < 3; j++) 
            {
                if(arr[j] > 60) arr[j] = 60;
            }
            sort(arr, arr + 3);
            tuple<int, int, int> nt = make_tuple(arr[2], arr[1], arr[0]);
            
            if(dp[get<0>(nt)][get<1>(nt)][get<2>(nt)] == 100)
            {
                dp[get<0>(nt)][get<1>(nt)][get<2>(nt)] = dp[get<0>(t)][get<1>(t)][get<2>(t)] + 1;
                q.push(nt);
            }
        }
    }
}