#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> vplus;
vector<int> vminus;

int main()
{
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        if(temp > 0) vplus.push_back(temp);
        else vminus.push_back(temp);
    }

    sort(vplus.begin(), vplus.end(), greater<>());
    sort(vminus.begin(), vminus.end());

    int sol = 0;

    for(int i = 0; i < vplus.size()/2; i++)
    {
        if(vplus[2*i+1] == 1) sol += vplus[2*i] + vplus[2*i+1];
        else sol += vplus[2*i] * vplus[2*i+1];
    }
    if(vplus.size() % 2 == 1) sol += vplus[vplus.size()-1];

    for(int i = 0; i < vminus.size()/2; i++)
    {
        sol += vminus[2*i] * vminus[2*i+1];
    }
    if(vminus.size() % 2 == 1) sol += vminus[vminus.size()-1];

    cout << sol;
}