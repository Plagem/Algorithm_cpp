#include <iostream>
using namespace std;

// Struct에서의 다운캐스팅이 유효한지 테스트

struct BaseStruct
{
    public:
    int baseValue;  
};

struct ChildStruct : public BaseStruct
{
    public:
    int childValue;
};

BaseStruct* ConvertChildToBasePtr()
{
    BaseStruct* BaseStr = nullptr;

    ChildStruct* ChildStr = new ChildStruct();
    ChildStr->childValue = 10;

    BaseStr = ChildStr;
    BaseStr->baseValue = 100;

    return BaseStr;
}

int main()
{
    BaseStruct* TB = ConvertChildToBasePtr();

    ChildStruct* TC = static_cast<ChildStruct*>(TB);

    cout << TB->baseValue << "\n\n";
    cout << TC->baseValue << "\n";
    cout << TC->childValue << "\n";
}