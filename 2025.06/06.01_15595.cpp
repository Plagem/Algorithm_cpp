#include <iostream>
#include <string>
#include <map>
using namespace std;

double cor = 0;
double tul = 0;
map<string, int> m;
map<string, bool> v;
int n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int idx, result, mem, time, lang, len;
        string id;
        cin >> idx >> id >> result >> mem >> time >> lang >> len;

        if(id == "megalusion") continue;

        if(m.find(id) != m.end())
        {
            m[id]++;
        }
        else
        {
            m.insert({id, 1});
        }

        if(result == 4)
        {
            if(v.find(id) == v.end())
            {
                cor++;
                tul += m[id];
                v.insert({id, true});
            }
            else
            {
                continue;
            }
        }
    }

    cout << fixed;
    cout.precision(10);
    if(cor == 0) cout << 0;
    else cout << cor*100 / tul;
}