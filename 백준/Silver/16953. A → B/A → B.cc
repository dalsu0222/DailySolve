#include <iostream>

using namespace std;
long long a, b;
int cnt;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a >> b;
	// a->b가 아닌, b->a로 역계산하여 2가지 케이스 확인
	while (true) {
		cnt++;
		if (a > b) {	// b -> a 불가능한 경우
			cout << -1;
			return 0;
		}else if (a == b) {	// b가 a에 도달한 경우(종료조건)
			cout << cnt;
			return 0;
		}

		if (b % 10 == 1) {	// 1. 1을 수의 가장 오른쪽에 추가하는 경우
			b--;
			b /= 10;
		}
		else if (b % 2 == 0) {	// 2. 2를 곱하는 경우
			b /= 2;
		}
		else {	
			cout << -1;
			return 0;
		}
	}

	return 0;
}
