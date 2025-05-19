#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;
vector<int> palList;
bool sosu[1003002];

bool isPalindrom(int a)
{
    int c = 0;
    int b = a;
    while(b)
    {
        c*= 10;
        c += b%10;
        b /= 10;
    }

    if(a == c) return true;
    return false;
}

int main()
{
    for(int i = 2; i < 1003002; i++)
    {
        if(sosu[i] == false)
        {
            if(isPalindrom(i))
            {
                palList.push_back(i);
            }
            for(int j = i; j < 1003002; j += i)
            {
                sosu[j] = true;
            }
        }
    }

    cin >> n;
    for(int i = 0; i < palList.size(); i++)
    {
        if(n <= palList[i])
        {
            cout << palList[i];
            return 0;
        }
    }
}