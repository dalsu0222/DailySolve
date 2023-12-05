#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int M, N;
char b[50][50];
int visited[50][50];
int cnt;		// 판자 개수
char now_c = '-';		// 현재 판자 모양

void dfs(int i, int j) {
	if (b[i][j] != now_c)		// basecase
		return;

	visited[i][j] = 1;
	if (b[i][j] == '-' && j+1<M && !visited[i][j+1]) {		// dfs에서도 조건 꼭 걸어주기
		dfs(i, j + 1);
	}
	else if(b[i][j] == '|' && i + 1 < N && !visited[i+1][j]) {
		dfs(i + 1, j);
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> b[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i][j] == 0) {		// 방문하지 않은 바닥일때
				visited[i][j] = 1;
				cnt++;	// 바닥 판자 갯수 1 증가

				// 현재 방문한 바닥 판자에 대해 '같은 모양'의 판자 모양 방문
				if (b[i][j] == '-' && j + 1 < M && !visited[i][j+1]) {	
					// 바닥 장식 모양이 '-'이고, 맨 오른쪽 판자가 아니면서 방문하지 않은 판자일 때
					now_c = '-';
					dfs(i, j + 1);
				}
				else if (b[i][j] == '|' && i + 1 < N && !visited[i + 1][j]) {
					// 바닥 장식 모양이 '|'이고, 맨 아래쪽 판자가 아니면서 방문하지 않은 판자일 때
					now_c = '|';
					dfs(i + 1, j);
				}
			}
		}
	}

	cout << cnt;

	return 0;
}