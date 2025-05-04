#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> think;
int n;

void init()
{
    for(int i = 1; i <= 9; i++)
    {
        for(int j = 1; j <= 9; j++)
        {
            for(int k = 1; k <= 9; k++)
            {
                if(i==j || j==k || k==i) continue;
                think.push_back(i*100 + j*10 + k);
            }
        }
    }
}

pair<int, int> check(int input, int input2)
{
    int strike = 0;
    int ball = 0;
    int inputarr1[3] = {input/100, (input%100)/10, (input%10)};
    int inputarr2[3] = {input2/100, (input2%100)/10, (input2%10)};

    for(int i = 0; i < 3; i++)
    {
        if(inputarr1[i] == inputarr2[i])
        {
            strike++;
        }
        else
        {
            for(int j = 0; j < 3; j++)
            {
                if(inputarr1[i] == inputarr2[j])
                {
                    ball++;
                }
            }
        }
    }

    return make_pair(strike, ball);
}

int main()
{
    init();
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int num, strike, ball;
        cin >> num >> strike >> ball;
        pair<int, int> res = make_pair(strike, ball);
        vector<int> newThink;
        for(int j = 0; j < think.size(); j++)
        {
            if(res == check(num, think[j]))
            {
                newThink.push_back(think[j]);
            }
        }
        think = newThink;
    }

    cout << think.size();
}