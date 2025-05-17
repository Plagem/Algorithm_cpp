#include <iostream>
#include <string>
#include <stack>
using namespace std;

int n;
int cur = 0;
int arr[100001];
stack<int> s;
string out;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for(int i = 0; i < n; i++)
    {
        if(arr[i] > cur)
        {
            while(cur < arr[i])
            {
                cur++;
                s.push(cur);
                out += '+';
            }
        }

        if(s.top() == arr[i])
        {
            s.pop();
            out += '-';
        }
        else
        {
            cout << "NO";
            return 0;
        }
    }

    for(int i = 0; i < out.size(); i++)
    {
        cout << out[i] << '\n';
    }
}