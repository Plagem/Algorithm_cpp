#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> arr;
int spf[5000001]; // smallest prime factor

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    for(int i = 2; i <= 5000000; i++) {
        if(spf[i] == 0) { // 아직 소수
            for(int j = i; j <= 5000000; j += i) {
                if(spf[j] == 0) spf[j] = i;
            }
        }
    }

    cin >> n;
    arr.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for(int i = 0; i < n; i++) {
        int x = arr[i];
        while(x > 1) {
            cout << spf[x] << " ";
            x /= spf[x];
        }
        cout << '\n';
    }
}