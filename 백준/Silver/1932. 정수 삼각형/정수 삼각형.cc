#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
int N;
int input[501][501];	// 1.
int tri[501][501];	// 1.
int result;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);

	/* 
		1. 입력받는 배열과 dp(여기선 tri) 배열의 차원 및 크기 동일하게 설정
		2. 맨꼭대기층 값 초기화
		3. tri[i][j] : 이전 층의 j번째 인덱스 기준으로 왼쪽&오른쪽값중 큰 값을 선택하고, 현재층의 값과 함께 더함
		4. 맨 밑 층에서, 가장 큰값을 선택함.
	*/

	cin >> N;
	int index = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {	// 정수 삼각형 입력받기
			cin >> input[i][j];
		}
	}
	tri[1][1] = input[1][1];	// 2.
	for (int i = 2; i <= N; i++) {	// 2층부터 진행
		for (int j = 1; j <= i; j++) {	// 3.
			tri[i][j] = max(tri[i - 1][j - 1], tri[i - 1][j]) + input[i][j];
		}
	}
	for (int i = 1; i <= N; i++) {
		if (result < tri[N][i])	// 4.
			result = tri[N][i];
	}
	cout << result;
	
	
	return 0;
}