#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int N, M;
int x, y;
int map[101][101];
int cnt;

void bfs(int x,int y, bool visited[101]) {
	visited[x] = true;
	queue<pair<int, int>> q;		// <목표사람, 목표사람까지의 단계수> 쌍
	q.push(make_pair(x, 0));
	while (!q.empty()) {
		int a = q.front().first;
		int a_cnt = q.front().second;
		q.pop();

		if (a == y) {	// 큐의 top 원소가 목표사람과 일치한다면
			cnt = a_cnt;	// 케빈베이컨수(단계수) 저장
			break;
		}
		for (int i = 1; i <= N; i++) {
			if (!visited[i] && map[a][i] == 1) {	// 아직 방문하지 않았고, a와 i가 친구관계라면
				// i 사람에 대한 정보 업데이트
				q.push(make_pair(i, a_cnt + 1));	
				visited[i] = true;
			}
		}
		
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);     // 시간초과방지

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		map[x][y] = 1;	
		map[y][x] = 1;
	}
	
	int min_K = 999999;
	int name = 0;
	for (int i = 1; i <= N; i++) {	// 시작 사람(i)
		int level = 0;
		for (int j = 1; j <= N; j++) {		// 목표 사람(j), 목표사람마다 bfs실행하여 관계 수 조사
			bool visited[101] = { 0, };
			if (i != j) {	// 시작 사람과 목표 사람이 동일인일 수는 없음
				bfs(i, j, visited);
				level += cnt;	// 목표 사람(j)의 케빈베이컨단계를 모두 합침
				cnt = 0;	// 다음 목표 사람을 위해 초기화
			}
		}
		if (min_K > level) {		// 조사한 관계 수(level)중에 최솟값 따로 저장
			min_K = level;
			name = i;
		}
	}
	cout << name;

	return 0;
}