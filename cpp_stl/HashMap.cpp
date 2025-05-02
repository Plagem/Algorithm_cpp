/**
 * 해시맵은 키를 통해 어떤 값을 찾기 위한 자료구조
 * STL에서는 map이 해당한다
 * 해싱은 해쉬함수를 이용해서 키를 숫자로 변환하는 과정이다
 * 이렇게 생성된 키는 해쉬맵 내부에 있는 자료구조 방 번호가 된다
 * 서로 다른 키 값에 대해 같은 방 번호가 나오는 것을 해시 충돌이라고 한다
 * 해시 충돌 시 체이닝 방법을 사용한다 - 연결리스트
 * 혹은 빈 방을 탐색하는 Open Adressing을 통해 해결한다
 */

#include <iostream>

#define MAX_TABLE 5 // 해시테이블 크기
#define MAX_KEY 8 // include null
#define MAX_DATA 12 // 해시테이블에 넣을 데이터의 수
#define DELETE_COUNT 6 // 삭제할 데이터의 수
#define FIND_COUNT 8 // 찾을 데이터의 수

struct Node
{
    char key[MAX_KEY];
    int value;
    Node* next; // 연결 리스트 방식을 사용하여 해시충돌 해결
};

// 해싱 함수
int hash(const char* str)
{
    int hash = 401;
    int c;
    while(*str != '\0')
    {
        hash = ((hash<<4) + (int)(*str)) % MAX_TABLE;
        str++;
    }

    return hash % MAX_TABLE;
}

Node* tb[MAX_TABLE];
char keys[MAX_DATA][MAX_KEY];
int values[MAX_DATA];

int main()
{
    std::cout << hash("happz");
}