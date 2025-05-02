#include <iostream>
using namespace std;

int n, m, k;
long long price[11];
long long maxMoney = 0;

void dfs(long long money, long long debt, int stock, int day)
{
    // 매도, 매수..
    // 대출을 할 때에만 매도를 한다

    if(day == n)
    {
        maxMoney = max(maxMoney, money + stock*price[day]);
        return;
    }

    // 1. 매도o, 매수x
    if(stock > 0)
    {
        dfs(money + stock*price[day], debt, 0, day+1);
    }
    // 2. 매도x, 매수o
    // 매수 조건 : 빚을 다 갚아야 하고 + 대출해서 주식을 하나라도 살 수 있어야 한다
    if(money >= debt && (money-debt)*(k+1) >= price[day])
    {
        int canbuy = (money-debt)*(k+1) / price[day];
        dfs((money-debt)*(k+1) - canbuy * price[day], (money-debt)*k, canbuy, day+1);
    }

    // 3. 매도o, 매수o
    if(stock > 0)
    {
        long long curmoney = money + stock*price[day];
        if(curmoney >= debt && (curmoney-debt)*(k+1) >= price[day])
        {
            int canbuy = (curmoney-debt)*(k+1) / price[day];
            dfs((curmoney-debt)*(k+1) - canbuy*price[day], (curmoney-debt)*k, canbuy, day+1);
        }
    }

    dfs(money, debt, stock, day+1);
}

int main()
{
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> price[i+1];
    }

    dfs(m, 0, 0, 1);

    cout << maxMoney;
}