// 2025.01.12
// 중, 후위연산자 문제

#include <stack>
#include <queue>
#include <string>
#include <iostream>


using namespace std;
int main()
{
    // push pop top size empty
    stack<int> s;
    string str;
    cin >> str;

    for(int i = 0; i < str.size(); i++)
    {
        char c = str[i];

        if(48 <= c && c < 58)
        {
            int num = c - 48;
            s.push(num);
        }
        else
        {
            int t1, t2, t3;
            t1 = s.top(); s.pop();
            t2 = s.top(); s.pop();
            switch(c)
            {
                case '-':
                t3 = t2 - t1;
                break;
                case '+':
                t3 = t1 + t2;
                break;
                case '*':
                t3 = t1 * t2;
                break;
                case '/':
                t3 = t2 / t1;
                break;
            }
            s.push(t3);
        }
    }

    cout << s.top();
}