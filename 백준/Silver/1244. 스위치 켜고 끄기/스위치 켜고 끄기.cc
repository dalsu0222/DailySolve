#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;
int n, m;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	vector<int> sw(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> sw[i];
	}
	cin >> m;
	int gen, num;
	for (int i = 0; i < m; i++) {
		cin >> gen >> num;
		if (gen == 1) {	// 남학생인 경우
			for (int j = 1; j <= n; j++) {
				if (j % num == 0) {	// 자기가 받은 수의 배수만 바꿈
					sw[j] = (sw[j] == 1) ? 0 : 1;	// toggle 하여 저장
				}
			}
		}
		else {
			int j = 0;	// num을 중심으로 얼만큼 대칭인지 나타내는 길이
			for ( ; j <= n / 2; j++) {
				if (num - j <= 0 || num + j > n)		// 가장 먼저 배열 인덱스 유효성 검사 
					break;

				if (sw[num - j] == sw[num + j]) {	// 대칭하는 위치의 스위치 상태가 같으면, j 카운트 계속 진행
					continue;
				}
				else {
					break;
				}
			}
			j--;	// 바로 위의 반복문을 빠져나오기 전 하나 더 카운트 된 것 제외
			for (int k = num - j; k <= num + j; k++) {
				sw[k] = (sw[k] == 1) ? 0 : 1;	// 대칭 길이만큼(num-j~num+j) toggle
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << sw[i] << " ";
		if (i % 20 == 0)
			cout << "\n";
	}

	return 0;
}