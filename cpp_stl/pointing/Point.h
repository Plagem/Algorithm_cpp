
#include <string>
#ifndef POINT_H
#define POINT_H

class Point {
private:
	int x;
	int y;
	static int count; 

public:
	Point(); //기본 생성자
	~Point(); // 소멸자
	static int getCount(); //static 변수를 세기 위한 함수
	std::string toString() const; // 저장된 문자열 리턴하는 함수
};
#endif