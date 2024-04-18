#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N, M;
int a, b;
char campus[601][601];
bool visited[601][601];
int cnt;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

/* 
	<깊이 우선 탐색 - dfs> 로 해결
	1. 2차원 배열 이용하여 캠퍼스 정보 입력받고, 도연이의 위치 기억해두기
	2. 도연이의 위치에 대해 dfs 탐색 수행
	3. dfs에서 도연이의 위치를 기준으로 상하좌우로 이동하며 만날 수 있는 사람 수 카운트
	4. dfs 탐색 종료 후, 만난 사람 수(cnt) 출력
*/

void dfs(int x, int y) {
	visited[x][y] = true;
	if (campus[x][y] == 'P')	// 사람을 만난 경우, cnt 증가
		cnt++;
	if (campus[x][y] == 'X')	// 벽을 만난 경우, 재귀 종료 후 원래 함수로 돌아가기
		return;
	// 빈공간을 만난경우, dfs 실행
	for (int i = 0; i < 4; i++) {			// 3.
		int new_x = x + dx[i];
		int new_y = y + dy[i];
		if (new_x < 0 || new_x >= N || new_y < 0 || new_y >= M)
			continue;
		if (!visited[new_x][new_y])
			dfs(new_x, new_y);		
	}
}

int main(void)
{
	cin >> N >> M;
	for (int i = 0; i < N; i++) {	// 1.
		for (int j = 0; j < M; j++) {
			cin >> campus[i][j];
			if (campus[i][j] == 'I') {
				a = i;
				b = j;
			}
		}
	}
	dfs(a, b);	// 2.
	if (cnt)	// 4.
		cout << cnt;
	else
		cout << "TT";

	return 0;
}