#include <iostream>
#include <cmath>
#include <iomanip>

// 함수 정의 f(x) = (cos^2(x)) / (1 + x^2)
#define FUNC(x) (pow(cos(x), 2) / (1 + pow(x, 2)))

int main() {
    double sum, err;
    double true_value = 0.673622; // 주어진 정적분 값
    int n = 1; // 초기 사각형 개수
    double tolerance = 0.5; // 허용 백분율 상대오차(%)

    while (true) {
        sum = 0.0; // 적분값 초기화
        double width = 1.0 / n; // 사각형의 폭

        // 직사각형 방법 (중점 값을 이용한 근사 적분)
        for (int i = 0; i < n; i++) {
            double x = (i + 0.5) * width; // 각 사각형의 중점
            sum += FUNC(x) * width; // 중점 값에서 함수 평가 후 합산
        }

        // 백분율 상대오차 계산
        err = fabs((sum - true_value) / true_value) * 100;

        // 오차가 허용 범위 이하면 결과 출력 후 종료
        if (err <= tolerance) {
            std::cout << "최소 사각형 개수: " << n
                << ", 근사적분 값: " << std::setprecision(15) << sum
                << ", ERROR: " << std::setprecision(15) << err << "%\n";
            break;
        }

        n++; // 사각형 개수 증가
    }

    return 0;
}