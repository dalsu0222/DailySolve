#include <iostream>
#include <vector>
#include <cmath> //C++

using namespace std;

int main(int argc, char** argv)
{
    int n;
    cin >> n;

    long long P[91];      // 배열 이용
    P[0] = 0;       // n>=2 이므로 0,1번째 값 미리 저장
    P[1] = 1;


    for (int i = 2; i <= n; i++) {
        P[i] = P[i - 2] + P[i - 1];     // 피보나치 수열
    }

    cout << P[n] << endl;       // n번째 수 출력

    return 0;
}