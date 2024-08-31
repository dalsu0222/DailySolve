#include <iostream>
#include <cmath>

using namespace std;
int n, r, c;	// r = x, c = y
int cnt;

void Z(int x,int y,int size) {
	if (r == x && c == y) {	// size = 1, basecase
		cout << cnt;
		return;
	}

	if (r >= x && r < x + size && c >= y && c < y + size) {
		// 찾으려는 열&행이 사분면 안에 있는 경우
		Z(x, y, size / 2);
		Z(x, y + size / 2, size / 2);
		Z(x + size / 2, y, size / 2);
		Z(x + size / 2, y + size / 2, size / 2);
	}
	else {	// 없다면 정사각형 넓이만큼 카운트 추가
		cnt += size * size;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> r >> c;

	Z(0,0,pow(2,n));

	return 0;
}
