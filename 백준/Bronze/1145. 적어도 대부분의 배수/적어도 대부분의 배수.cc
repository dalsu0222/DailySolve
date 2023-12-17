#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int main(void)

{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int arr[5];
    for(int i = 0; i < 5; i++){
        cin >> arr[i];
    }
    for(int i = 1; ; i++) {        // 무한대로 증가하며 최소 3개로 나누어 떨어지는지 확인
        int cnt = 0;
        for (int j = 0; j < 5; j++) {
            if(i % arr[j] == 0) {        // 해당 배수(i)가 5개의 원소중 하나로 나누어떨어진다면
                cnt++;    // 카운트 1 증가
                if(cnt >= 3) {    // 카운트=3, 즉 최소 3개를 찾았다면
                    cout << i;
                    return 0;       // 즉시 종료
                }
            }
        }
    }

    return 0;
}