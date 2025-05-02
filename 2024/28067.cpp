#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <set>

using namespace std;
int main()
{
    int N, M;
    cin >> N >> M;
    set<tuple<int, int, int>> s;

    vector<pair<int, int>> maps;
    for(int i = 0 ; i <= N; i++)
    {
        for(int j = 0; j <= M; j++)
        {
            maps.push_back(make_pair(i, j));
        }
    }

    for(int i = 0; i < maps.size(); i++)
    {
        for(int j = i+1; j < maps.size(); j++)
        {
            for(int k = j+1; k < maps.size(); k++)
            {
                int trisize[3];
                pair<int, int> first = maps[i];
                pair<int, int> second = maps[j];
                pair<int, int> third = maps[k];
                
                if((second.first - first.first) * (third.second - first.second) - (second.second - first.second) * (third.first - first.first) == 0) continue;

                trisize[0] = (first.first - second.first) * (first.first - second.first) + (first.second - second.second) * (first.second - second.second);
                trisize[1] = (second.first - third.first) * (second.first - third.first) + (second.second - third.second) * (second.second - third.second);
                trisize[2] = (third.first - first.first) * (third.first - first.first) + (third.second - first.second) * (third.second - first.second);
                sort(trisize, trisize + 3);
                s.insert(make_tuple(trisize[0], trisize[1], trisize[2]));
            }
        }
    }

    cout << s.size();
}