#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;
int N;
int col[16];
int result;
//bool visited[16];

bool check(int x) {
	// x번째 열까지 퀸 위치 검사
	for (int i = 0; i < x; i++) {
		// 같은 행에 위치하거나 or 대각선 위치에 존재하면(행 차이 = 열 차이)
		if (col[i] == col[x] || abs(col[x] - col[i]) == (x - i))
			return false;		// 퀸 놓기 불가능
	}
	return true;
}

void nQueen(int x) {
	if (x == N)		// 총 배치 행수가 N이 되면 경우의수(정답) 1 증가
		result++;
	else {
		// 한 행씩 퀸을 배치해가기
		for (int i = 0; i < N; i++) {
			col[x] = i;		// x번째 열의 i행에 퀸 배치
			if (check(x))	// 놓은 자리의 퀸이 가능한 퀸인지 검사
				nQueen(x + 1);	// 그다음 열로 진행(~N번째 열까지)
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);     // 시간초과방지

	cin >> N;
	nQueen(0);
	cout << result;
	
	return 0;
}