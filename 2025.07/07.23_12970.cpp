#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<char> v;

void pv()
{
    for(int i = 0; i < n; i++)
    {
        cout << v[i];
    }
    cout << endl;
}

int check()
{
    int sum = 0;
    int a = 0;
    for(int i = 0; i < n; i++)
    {
        if(v[i] == 'A')
        {
            a++;
        }
        else
        {
            sum += a;
        }
    }

    return sum;
}

int main()
{
    cin >> n >> k;

    for(int i = 0; i < n; i++)
    {
        v.push_back('B');
    }

    int sol = 0;
    for(int i = 0; i < n; i++)
    {   
        for(int j = n-1; j >= i; j--)
        {
            v[j] = 'A';
            if(j != n-1)
            {
                v[j+1] = 'B';
            }

            if(k == check())
            {
                pv();
                return 0;
            }
        }
    }

    cout << "-1";
}