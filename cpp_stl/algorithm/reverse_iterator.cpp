#include <iostream>
#include <vector>
using namespace std;

int main ()
{
    vector<int> vt;
    vt.push_back(10);
    vt.push_back(20);
    vt.push_back(30);
    vt.push_back(40);

    auto viter = vt.begin();
    //vector<int>::iterator viter = vt.begin();
    reverse_iterator<vector<int>::iterator> reviter(vt.end());
    reverse_iterator<vector<int>::iterator> end_reviter(vt.begin());

    for (; reviter != end_reviter; reviter++)
    {
        cout << *reviter << " ";
    }
    cout << endl;

    return 0;
}