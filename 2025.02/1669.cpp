#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long N, M;
    cin >> N >> M;
    long long K = M - N;
    long long kan = 0;

    long long rtK = sqrt(K);
    long long namusi = K - rtK * rtK;
    
    if(K == 0)
    {
        kan = 0;
    }
    else if(namusi == 0)
    {
        kan = rtK * 2 - 1;
    }
    else if (namusi <= rtK)
    {
        kan = rtK * 2;
    }
    else
    {
        kan = rtK * 2 + 1;
    }

    cout << kan;
}