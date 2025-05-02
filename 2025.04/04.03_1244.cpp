// S4 1244 스위치 켜고 끄기 : 구현
#include <iostream>
using namespace std;

int n, m;
bool dSwitch[101];

void boy(int idx)
{
    for(int i = idx; i <= n; i+=idx)
    {
        dSwitch[i] = !dSwitch[i];
    }
}

void girl(int idx)
{
    dSwitch[idx] = !dSwitch[idx];
    int lidx = idx-1; int ridx = idx+1;
    while(true)
    {
        if(1 <= lidx && ridx <= n && dSwitch[lidx] == dSwitch[ridx])
        {
            dSwitch[lidx] = !dSwitch[lidx];
            dSwitch[ridx] = !dSwitch[ridx];
            lidx--; ridx++;
        }
        else break;
    }
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int t1;
        cin >> t1;
        dSwitch[i] = t1 == 0 ? false : true;
    }

    cin >> m;
    for(int i = 0; i < m; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        if(t1 == 1)
        {
            boy(t2);
        }
        else
        {
            girl(t2);
        }
    }

    for(int i = 1; i <= n; i++)
    {
        cout << dSwitch[i] << " ";
        if(i % 20 == 0) cout << "\n";
    }
}