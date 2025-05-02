#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    long long n, r;
    cin >> n >> r;

    // 정수 n을 m으로 나눈 나머지가 r이 되도록 하는 모든 양의 정수 m의 합
    // n % m = r 이라는거는 r + m*뭐시기 = n 즉 n-r의 약수 (12) 중 r보다 큰놈
    // 16 - 4 = 12 12의 약수는 1 2 3 4 6 12 이중에 4보다 큰놈은 6과 12
    long long te = n - r;
    long long sol = 0;
    for(long long i = 1; i <= sqrt(te); i++)
    {
        if(te % i == 0)
        {
            if(i > r) sol += i;
            if(i*i != te && te/i > r) sol += te/i;
        }
    }

    cout << sol;
}