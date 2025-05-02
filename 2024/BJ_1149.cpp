#include <iostream>

int main ()
{
    int sol[3] = {0};
    int new_sol[3];

    int N;
    std::cin >> N;
    int **arr = new int*[N];
    for(int i = 0; i < N; i++) 
        arr[i] = new int[3];
    for(int i = 0; i < N; i++)
        std::cin >> arr[i][0] >> arr[i][1] >> arr[i][2];

    for(int i = 0; i < N; i++) { // new_sol을 새로 배정해주는 과정
        new_sol[0] = arr[i][0];
        new_sol[1] = arr[i][1];
        new_sol[2] = arr[i][2];
        int temp[3] = {INT_MAX, INT_MAX, INT_MAX};

        for(int j = 0; j < 3; j++) { // 여기서 A' 정해주고 (new_sol)    
            for(int k = 0; k < 3; k++) { // 여기서 A B C (sol) 비교 시작합니다
                if(j==k) // 같은 색 마을이 반복될 수 없으므로
                    continue;
                if(new_sol[j]+sol[k] < temp[j])
                    temp[j] = new_sol[j]+sol[k];
            }
        }
        sol[0] = temp[0]; sol[1] = temp[1]; sol[2] = temp[2];
    }

    int temp = INT_MAX;
    for(int i=0; i < 3; i++) {
        if(sol[i] < temp)
            temp = sol[i];
    }

    std::cout << temp << std::endl;
}