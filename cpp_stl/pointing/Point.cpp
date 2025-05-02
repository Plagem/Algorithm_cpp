#include <iostream>
#include <sstream>
#include <iomanip>
#include "Point.h"
using namespace std;

int Point::count{ 0 }; //static의 경우 외부에서 초기화

int Point::getCount() //카운트를 세는 함수
{
	return count;
}

Point::Point() //생성자가 호출될 때 마다 카운트 +1
{
	++count;
	
	cout << "Point " << count << " constructor." << endl;
	cout << "Input x and y for Point: ";
	cin >> x >> y; //x,y 값 입력
	
	bool correct_input = false;

	while(!correct_input){
		if (0 < x < 100 && 0 < y < 100) {
			this->x = x;
			this->y = y;
			correct_input = true;
		}
		else {
			cout << "Out of range. Input again." << endl;
		}
	}

}

Point::~Point() //소멸자 호출될 때마다 카운트 -1
{
	cout << "Point " << count << " destructor." << endl;
	--count;
}

string Point::toString() const // 좌표가 한 자리라면 앞에 0을 채움
{
	ostringstream output;
	output << "x = " << setfill('0') << setw(2) << x << ", y = " << setfill('0') << setw(2) << y;
	return output.str();
}
