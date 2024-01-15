#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

long long x, y;
int w, s;

int main(void)

{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long t1, t2;
	cin >> x >> y >> w >> s;
	if (w < s) {		// 평행이동 시간이 더 짧은 경우
		// (x+y)*w -> 평행이동으로만
		// min(x, y) * s + abs(x - y) * w -> 최대한 대각선으로 이동 + 나머지 평행이동
		t1 = min((x + y) * w, min(x, y) * s + abs(x - y) * w);
		cout << t1;	// 둘 중에 작은 시간을 출력
	}
	else {		// 대각선 이동 시간이 더 짧은 경우
		if ((x + y) % 2 == 0) {		// 좌표의 합이 짝수인경우
			t2 = max(x, y) * s;	// 대각선 이동으로만.
		}
		else {		// 좌표의 합이 홀수인경우
			t2 = (max(x, y) - 1) * s + w;	// 대각선이동 + 평행이동 1번
		}
		cout << t2;
	}

	return 0;
}
