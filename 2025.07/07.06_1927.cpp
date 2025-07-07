#include <iostream>
#include <queue>
using namespace std;

int n;
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        if(t == 0)
        {
            if(pq.size() == 0)
            {
                cout << "0\n";
            }
            else
            {
                cout <<  pq.top() << '\n';
                pq.pop();
            }
        }
        else
        {
            pq.push(t);
        }
    }
}