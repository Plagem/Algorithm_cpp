#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int MAX = 2100000000;

int N;
vector<int> liquids;

bool compare(int a, int b)
{
    return abs(a) < abs(b) ? true : false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        liquids.push_back(temp);
    }

    sort(liquids.begin(), liquids.end(), compare);

    int sol = MAX;

    int sol_first = 0;
    int sol_second = 0;

    for(int i = 0; i < N-1; i++)
    {
        int first = liquids[i] / abs(liquids[i]);
        int second = liquids[i+1] / abs(liquids[i+1]);
        
        int temp;
        if(first * second == -1)
        {
            temp =abs(liquids[i] + liquids[i+1]);
        }
        else
        {
            temp = abs(liquids[i]) + abs(liquids[i+1]);
        }

        if(sol > temp)
        {
            sol = temp;
            sol_first = liquids[i];
            sol_second = liquids[i+1];
        }
    }
    
    cout << min(sol_first, sol_second) << " " << max(sol_first, sol_second);
}