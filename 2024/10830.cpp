// Divide and Conquer 제곱합 문제

// 10579 한다고 생각해보자
// 10579 = 10100101010011

// for문 돌때마다 arr은 제곱이 된다
// 2로 나눴는데 0이면 arr을 정답행렬에 곱하지 않고
// 1이면 arr을 정답행렬에 곱한다

// 그러면 10579 한다고 할 때,
// arr에 arr^1 * arr^2 * arr^16 * ... = arr^10579가 된다

#include <iostream>


int N;
long long B;
int sol[5][5];
int arr[5][5];

void multi(int mat1[5][5], int mat2[5][5])
{
    int temp[5][5];
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            temp[i][j] = 0;
            for(int k = 0; k < N; k++)
            {
                temp[i][j] += mat1[i][k] * mat2[k][j];
            }
            temp[i][j] %= 1000;
        }
    }

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            mat1[i][j] = temp[i][j];
}

using namespace std;
int main()
{
    // 초기화
    cin >> N >> B;
    for(int i = 0; i < 5; i++)
        sol[i][i] = 1;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> arr[i][j];
    
    // 로직
    while(B != 0)
    {
        if(B % 2 != 0)
        {
            multi(sol, arr);
        }
        multi(arr, arr);

        B = B / 2;
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cout << sol[i][j] << " ";
        }
        cout << "\n";
    }
}

