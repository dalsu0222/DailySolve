#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
long long S;
long long num = 1;
long long total, cnt;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);     // 시간초과방지

	cin >> S;

	while (1) {
		total += num;	// total에 수 더하기(1부터 차례대로 더해야 최대 개수가 된다.)
		cnt++;	// 개수 증가
		if (total > S) {
			cnt--;	// 더했을때 S를 초과한다면, 직전에 더한 수 빼고 종료
			break;
		}
		num++;
	}

	cout << cnt;

	return 0;
}