/*
10:27
카드 2N개. 1부터 2N까지 넘버링
베시에게 N개, 엘시에게 N개 분배
N라운드 플레이 한다. 
처음 N/2라운드에서는 높은 카드 낸 사람이 승리
나머지에서는 낮은 카드 낸 사람이 승리

엘시가 낼 카드를 완전히 알고 있다고 할 때, 최대 승리 수를 구하라

N = 4이고 1 8 4 3?
내가 가진 카드 : 2 5 6 7
1 8 / 4 3
1보다 큰애 2 5 6 7
8보다 큰애 x
4보다 작은애 2
3보다 작은애 2

8 1 / 3 4
1. 8 7 x
2. 3 2 o -> 5 6 7
3. 

정렬을 이렇게 한다
큰놈 하는거 큰거부터 차례대로
작은놈 하는거 작은거부터 차례대로

게임은 10만회 진행
*/

#include <iostream>
#include <algorithm>

int bessiDeckUp[25000];
int bessiDeckDown[25000];

int myDeck[50000];

bool visited[1000001];

bool reverse_compare(int i, int j)
{
    return j < i;
}

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, sol = 0;
    cin >> N;

    for(int i = 0; i < N/2; i++)
    {
        cin >> bessiDeckUp[i];
        visited[bessiDeckUp[i]] = true;
    }
    sort(bessiDeckUp, bessiDeckUp + N/2, reverse_compare);
    for(int i = 0; i < N/2; i++)
    {
        cin >> bessiDeckDown[i];
        visited[bessiDeckDown[i]] = true;
    }
    sort(bessiDeckDown, bessiDeckDown + N/2);

    int sidx = 0;
    for(int i = 0; i < 2 * N; i++)
    {
        if(visited[i+1] == false)
        {
            myDeck[sidx] = i+1;
            sidx++;
        }
    }

    int start = 0, end = N-1;
    for(int i = 0; i < N / 2; i++)
    {
        // 큰놈 비교
        if(myDeck[end] > bessiDeckUp[i])
        {
            sol++;
            end--;
        }

        if(myDeck[start] < bessiDeckDown[i])
        {
            sol++;
            start++;
        }
    }

    cout << sol;
}