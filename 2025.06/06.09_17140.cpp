#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int iter = 0;
int r, c, k;
int arr[100][100];

int curRow = 3, curCol = 3;

bool comp(const pair<int, int>& a, const pair<int, int>& b)
{
    if(a.second != b.second)
    {
        return a.second < b.second;
    }
    return a.first < b.first;
}

void newSort()
{
    int maxIdx = 0;
    if(curRow >= curCol)
    {
        // R 연산
        for(int i = 0; i < curRow; i++)
        {
            // map
            map<int, int> m;
            for(int j = 0; j < curCol; j++)
            {
                int cur = arr[i][j];
                if(cur == 0) continue; // 0은 기록에서 제외
                m[cur]++;
            }

            // vector
            vector<pair<int, int>> v;
            for(auto i : m)
                v.push_back({i.first, i.second});
            sort(v.begin(), v.end(), comp);
            maxIdx = max(maxIdx, min(100, (int)v.size()*2));

            // 기록
            for(int j = 0; j < 50; j++)
            {
                if(j < v.size())
                {
                    arr[i][j*2] = v[j].first;
                    arr[i][j*2+1] = v[j].second;
                }
                else
                {
                    arr[i][j*2] = 0;
                    arr[i][j*2+1] = 0;
                }
            }
        }
        curCol = maxIdx;
    }
    else if(curRow < curCol)
    {
        // C 연산
        for(int i = 0; i < curCol; i++)
        {
            map<int, int> m;
            for(int j = 0; j < curRow; j++)
            {
                int cur = arr[j][i];
                if(cur == 0) continue; // 0은 기록에서 제외
                m[cur]++;
            }

            vector<pair<int, int>> v;
            for(auto i : m)
                v.push_back({i.first, i.second});
            sort(v.begin(), v.end(), comp);
            maxIdx = max(maxIdx, min(100, (int)v.size()*2));

            for(int j = 0; j < 50; j++)
            {
                if(j < v.size())
                {
                    arr[j*2][i] = v[j].first;
                    arr[j*2+1][i] = v[j].second;
                }
                else
                {
                    arr[j*2][i] = 0;
                    arr[j*2+1][i] = 0;
                }
                
            }
        }
        curRow = maxIdx;
    }   
}

bool printCheck()
{
    // cout << endl;
    // for(int i = 0; i < curRow; i++)
    // {
    //     for(int j = 0; j < curCol; j++)
    //     {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    if(arr[r-1][c-1] == k)
    {
        cout << iter;
        return true;
    }
    iter++;

    return false;
}


int main()
{
    cin >> r >> c >> k;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }

    // 정렬 (최대 100회)
    for(int i = 0; i <= 100; i++)
    {
        bool b = printCheck();
        if(b == true) return 0;

        newSort();
    }
    cout << "-1";

}