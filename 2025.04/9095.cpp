#include <iostream>
using namespace std;

int n, t;
int sol;

void logic(int sum) 
{
    if(sum == n)
    {
        sol++;
        return;
    }
	if (sum > n) return;

	for (int i = 1; i <= 3; i++) 
    {
		logic(sum+i);
	}
}

int main() {
	cin >> t;
    while(t--)
    {
        sol = 0;
        cin >> n;
		logic(0);
		cout << sol << endl;
    }
}