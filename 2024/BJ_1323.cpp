#include <iostream>
#include <vector>
#include <cmath>

int countdigit(int n) 
{
    int cnt = 0;
    while (n > 0) {
        n = n/10;
        cnt++;
    }
    return cnt;
}

int main () 
{
    int solve = 1;
    int N, K;
    std::cin >> N >> K;
    int p = countdigit(N);
    bool check[100001] = {0}; // 나머지 확인
    long long tmp = N % K;

    while(tmp != 0) {
        if(check[tmp] == 0) {
            check[tmp] = 1;
        } else {
            std::cout << -1 << std::endl;
            return 0;
        }

        solve++;
        tmp = (tmp * round(pow(10, p)) + N);
        tmp = tmp % K;
    }

    std::cout << solve << std::endl;
    return 0;
}