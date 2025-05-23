#include <iostream>
using namespace std;

class Dept {
    int size;
    int *scores;
public:
    Dept(int size) {
        this->size = size;
        scores = new int[size];
    }
    //Dept(const Dept& dept);
    ~Dept() { delete[] scores; }
    int getSize() { return size; }
    void read() {
        cout << size << "개 점수 입력>> ";
        for (int i = 0; i < size; i++) {
            cin >> scores[i];
        }
    }
    bool isOver60(int index) {
        if (scores[index] >= 60) return true;
        return false;
    }
};

int countPass(Dept dept) {
    int count = 0;
    for (int i = 0; i < dept.getSize(); i++) {
        if (dept.isOver60(i)) count++;
    }
    return count;
}

int main() {
    Dept com(10);
    com.read();
    int n = countPass(com);
    cout << "60점 이상은 " << n << "명";
}