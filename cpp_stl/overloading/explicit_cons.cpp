#include <iostream>

class Point {
	int x;
	int y;
public:
	explicit Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
	// 명시적 형 변환! 이제 암시적 생성자 호출이 불가능하다.
	// ex) Point pt; pt = 10; 같은 생성이 불가능하고 pt = Point(10) 같은 생성만 가능하다.
	void Print() { std::cout << x << ", " << y << std::endl; }
};

int main()
{
	Point pt;
	pt.Print();

	//pt = 10;
	pt = Point(10);
	pt.Print();
	
	return 0;
}