#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<pair<int, int>> v;
    int N;
    int max_height = 0;
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        int pos, height;
        cin >> pos >> height;
        max_height = max(max_height, height);
        v.push_back(make_pair(pos, height));
    }

    sort(v.begin(), v.end());

    int sol = 0;

    int f_stop, s_stop;
    // 위로 올라가는 칸
    int save = 0;
    for(int i = 0; i < N; i++)
    {        
        if(i != 0)
        {
            sol += save * (v[i].first - v[i-1].first);
        }
        save = max(save, v[i].second);

        if(v[i].second == max_height)
        {
            f_stop = v[i].first; break;
        }
    }

    save = 0;
    for(int i = v.size() - 1; i >= 0; i--)
    {
        if(i != v.size() - 1)
        {
            sol += save * (v[i+1].first - v[i].first);
        }
        save = max(save, v[i].second);

        if(v[i].second == max_height)
        {
            s_stop = v[i].first; break;
        }
    }

    sol += (s_stop - f_stop + 1) * max_height;

    cout << sol;
}