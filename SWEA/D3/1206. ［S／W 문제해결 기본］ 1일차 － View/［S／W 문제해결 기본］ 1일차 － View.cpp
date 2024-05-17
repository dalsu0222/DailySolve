#include<iostream>
#include<cstring>

using namespace std;

int main(){
	int n;
	for (int tc = 1; tc <= 10; tc++) {
		cin >> n;
		int input[1000] = { 0, };
		for (int i = 0; i < n; i++) {
			cin >> input[i];
		}
		int result = 0;	// 조망권이 확보된 세대 수
		for (int i = 2; i < n - 2; i++) {
			int max_h = 0;
			for (int j = 1; j <= 2; j++) {	// 양쪽 2개의 세대에서 가장 높은 세대의 높이 찾기
				int large_h = input[i - j] > input[i + j] ? input[i - j] : input[i + j];
				if (max_h < large_h)
					max_h = large_h;
			}
			if (max_h < input[i]) {	// 조망권이 확보되는 경우 -> 양쪽 2개의 세대보다 i번째 건물이 더 높은경우
				result += input[i] - max_h;	// 높이 차이만큼 조망권 확보
			}
		}

		cout << "#" << tc << " " << result << "\n";
	}
    
	return 0;
}