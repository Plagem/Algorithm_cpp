#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <cmath>

std::unordered_map<int, std::array<int, 2>> factors;
int factos[20][3];

void Decomposition(int num, bool max)
{
    while(num != 1)
    {
        bool flag = false;
        for(int i = 2; i <= sqrt(num); i++)
        {
            // 나누어떨어진다 -> 소인수 발견
            if(num % i == 0)
            {
                flag = true;
                if(max)
                    factors[i][1]++;
                else
                    factors[i][0]++;
                num /= i;
                break;
            }
        }
        if(flag == false)
        {
            // 제곱근까지 돌았는데 없다? -> 소수
            if(max)
                factors[num][1]++;
            else
                factors[num][0]++;
            num = 1;
        }
    }
}

using namespace std;
int main()
{
    int N, M; // M이 더 크다
    cin >> N >> M;

    Decomposition(N, false);
    Decomposition(M, true);

    int minDifference = numeric_limits<int>::max();
    int bestA = 0, bestB = 0;
    for(int i = 0; i < pow(2, factors.size()); i++)
    {
        int A = 1, B = 1;
        int index = 0;

        for (const auto& [key, value] : factors)
        {
            int exponentA, exponentB;

            if (i & (1 << index)) // index번째 비트가 1이면 value[1] 선택
            {
                exponentA = value[1];
                exponentB = value[0];
            }
            else // index번째 비트가 0이면 value[0] 선택
            {
                exponentA = value[0];
                exponentB = value[1];
            }

            A *= pow(key, exponentA);
            B *= pow(key, exponentB);
            
            index++;
        }

        int diff = abs(A - B);
        if (diff < minDifference)
        {
            minDifference = diff;
            bestA = A;
            bestB = B;
        }
    }

    cout << min(bestA, bestB) << " " << max(bestA, bestB);
}