#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;


int main()
{
    while(true)
    {
        string temp;
        cin >> temp;
        if(temp == "*") return 0;

        bool isSuprising = true;
        for(int i = 1; i < temp.length(); i++)
        {
            set<string> stringSet;
            for(int j = i; j < temp.length(); j++)
            {
                int len = j - i;
                string tmp = "";
                tmp += temp[len];
                tmp += temp[j];
                stringSet.insert(tmp);
            }
            if(stringSet.size() != temp.length() - i) 
                isSuprising = false;
        }

        if(isSuprising)
            cout << temp << " is surprising.\n";
        else
            cout << temp << " is NOT surprising.\n";
    }
}