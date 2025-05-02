// int int 곱해서 overflow가 발생하면 프로그램이 꺼질 수 있다.

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

const long long MAX = 1e7;
vector<bool> is_prime(MAX+1, true);

void CheckPrime()
{
    is_prime[0] = false; is_prime[1] = false;
    
    for(long long i = 2; i < MAX+1; i++)
    {
        if(is_prime[i] == false) continue;

        for(long long j = i * i; j < MAX+1; j += i)
        {
            is_prime[j] = false;
        }
    }
}

// N이상 M이하 소수 개수를 구한다
int countPrimary(long long N, long long M)
{
    int count = 0;
    for(int i = N; i <= M; i++)
    {
        if(is_prime[i]) count++;
    }
    return count;
}

int main()
{
    CheckPrime();

    long long N, M;
    cin >> N >> M;

    long long sol = 0;
    long long powNum = 2;

    while(true)
    {
        long long powN = (long long)ceil(pow(N, 1.0/powNum));
        long long powM = (long long)floor(pow(M, 1.0/powNum));
        
        if(powM < 2) break;

        sol += countPrimary(powN, powM);
        powNum++;
    }

    cout << sol;
}