#include <iostream>
#include <string>
#include <vector>

using namespace std;

int checkDistance(string s1, string s2)
{
    int distance = 0;
    for(int i = 0; i < s1.size(); i++)
    {
        if(s1[i] != s2[i])
            distance++;
    }
    return distance;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    for(int test = 0; test < T; test++)
    {
        vector<string> mbtis;
        int N;
        cin >> N;

        if(N > 32)
        {
            string s;
            cin.ignore();
            getline(cin, s);
            cout << "0" << "\n";
            continue;
        }
        
        for(int i = 0; i < N; i++)
        {
            string s;
            cin >> s;
            mbtis.push_back(s);
        }

        int distance = -1;

        for(int i = 0; i < N; i++)
        {
            for(int j = i+1; j < N; j++)
            {
                for(int k = j+1; k < N; k++)
                {
                    string s1 = mbtis[i]; 
                    string s2 = mbtis[j]; 
                    string s3 = mbtis[k];
                    int tdist = checkDistance(s1, s2) + checkDistance(s3, s2) + checkDistance(s1, s3);
                    if(distance == -1 || tdist < distance)
                    {
                        distance = tdist;
                    }
                }
            }
        }
        cout << distance << "\n";
    }
}