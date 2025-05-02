#include <iostream>
using namespace std;

int w, h, p, q, t;

int main() {

    // Input
    cin >> w >> h;
    cin >> p >> q ;
    cin >> t;

    // Logic
    if ((p + t) / w % 2 == 0) {
        cout << (p + t) % w << ' ';
    }
    else cout << w - (p + t) % w << ' ';

    if ((q + t) / h % 2 == 0) {
        cout << (q + t) % h;
    }
    else cout << h - (q + t) % h;
}