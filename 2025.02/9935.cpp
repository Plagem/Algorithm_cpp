#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string myString, C4String, stackString;
    stackString.resize(1000001);
    int C4Length;
    cin >> myString;
    cin >> C4String;
    C4Length = C4String.length();

    int idx = 0;
    for(int i = 0; i < myString.length(); i++)
    {
        stackString[idx] = myString[i]; idx++;
        if(idx >= C4Length)
        {
            bool hasC4String = true;
            for(int j = 0; j < C4Length; j++)
            {
                if(stackString[idx-1-j] != C4String[C4Length-1-j])
                    hasC4String = false;
            }
            if(hasC4String)
            {
                idx -= C4Length;
            }
        }
    }

    if(idx == 0)
    {
        cout << "FRULA";
    }
    else
    {
        for(int i = 0; i < idx; i++)
        {
            cout << stackString[i];
        }
    }
}