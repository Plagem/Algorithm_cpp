#include <iostream>
#include <vector>
#include <set>

using namespace std;

void logic()
{
    // input
    int n, m;
    cin >> n >> m;
    vector<bool> candrink(m+1);
    int zeroStack = 0;
    for(int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        
        // main logic;
        if(temp == 0)
        {
            zeroStack++;
        }
        else
        {
            zeroStack--;
            
        }
    }

    // main logic
    
}

int main()
{
    // testcase
    int z;
    while(z--)
    {
        logic();
    }
}