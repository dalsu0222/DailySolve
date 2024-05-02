#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;
int R, C;
vector<int> result(10);

int main(void)
{
	cin >> R >> C;
	vector<string> s(R);
	for (int i = 0; i < R; i++) {
		cin >> s[i];
	}
	int cnt = 1;
	bool isRank = false;
	for (int i = C-2; i >= 1; i--) {	// 결승선 직전라인부터 가까운 카약과의 거리 확인
		for (int j = 0; j < R; j++) {
			int num = s[j][i] - '0';	// 카약 번호
			if (1 <= num && num <= 9 && !result[num]) {	// num 유효성 선검사 후 result 접근
				result[num] = cnt;
				isRank = true;
			}
		}
		if (isRank)	// 카약이 존재하는 라인이라면, 등수 카운트
			cnt++;
		isRank = false;
	}


	for (int i = 1; i < 10; i++) {
		cout << result[i] << "\n";
	}

	return 0;
}