#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;

    bool is_cpp = false;
    bool is_java = false;
    string newString;
    if('a' > s[0] || s[0] > 'z')
    {
        cout << "Error!";
        return 0;
    }
    for(int i = 0; i < s.size(); i++)
    {
        if('a' <= s[i] && s[i] <= 'z')
        {
            newString += s[i];
        }
        else if(s[i] == '_')
        {
            if(is_java || i+1 >= s.size())
            {
                cout << "Error!";
                return 0;
            }
            else if('a' > s[i+1] || s[i+1] > 'z')
            {
                cout << "Error!";
                return 0;
            }
            else
            {
                newString += char(s[++i] + 'A' - 'a');
                is_cpp = true;
            }
        }
        else if(s[i] >= 'A')
        {
            if(is_cpp)
            {
                cout << "Error!";
                return 0;
            }
            else
            {
                newString += '_';
                newString += char(s[i] + 'a' - 'A');
                is_java = true;
            }
        }
    }

    cout << newString;
}