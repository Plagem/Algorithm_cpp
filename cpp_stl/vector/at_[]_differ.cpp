#include <iostream>
#include <vector>
using namespace std;

int main ()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    for(vector<int>::size_type i = 0; i < v.size(); i++) 
        cout << v[i] << " ";
    cout << endl;

    v[0] = 100;
    v[4] = 500;
    v[5] = 600;
    for(vector<int>::size_type i = 0; i < v.size(); i++) 
        cout << v[i] << " ";
    cout << v[6] << endl;

    v.at(0) = 1000;
    v.at(4) = 5000;
    //v.at(5) = 6000;       --> 실행단계에서 out of range 에러가 출력된다. (호출 시점에서 벙위 점검을 함.)
    for(vector<int>::size_type i = 0; i < v.size(); i++) 
        cout << v[i] << " ";
    cout << endl;

    return 0;
}