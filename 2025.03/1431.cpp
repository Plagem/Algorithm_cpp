#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string arr[50];

bool oper(string s1, string s2)
{
    if(s1.length() != s2.length())
    {
        return s1.length() < s2.length();
    }
    
    int s1int = 0; int s2int = 0;
    for(int i = 0; i < s1.length(); i++)
    {
        if('0' <= s1[i] && s1[i] <= '9')
        {
            s1int += s1[i] - '0';
        }
        if('0' <= s2[i] && s2[i] <= '9')
        {
            s2int += s2[i] - '0';
        }
    }
    if(s1int != s2int)
    {
        return s1int < s2int;
    }
    else return s1 < s2;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr+N, oper);

    for(int i = 0; i < N; i++)
    {
        cout << arr[i] << "\n";
    }
}