#include <iostream>
using namespace std;

int main()
{
    for(int i = 0; i <= 20; i++)
    {
        int length = i;
        int budget = ((length+2)/3)*3 + (length-((length+2)/3))*2;
        cout << budget << " ";
    }

}