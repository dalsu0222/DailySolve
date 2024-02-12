#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;
int F, S, G, U, D;	
int dx[2];		// 방향(위,아래)
int cnt[1000001];		// cnt[n] : n층까지의 버튼 누른 수
bool visited[1000001];		// visited[n] : n층을 방문했는지

void bfs(int x) {
	visited[x] = true;
	queue<int> q;
	q.push(x);	
	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		for (int i = 0; i < 2; i++) {		// 방향 컨트롤
			int new_x = tmp + dx[i];	// 위층(i=0) 혹은 아래층(i=1)으로 이동
			if (1 <= new_x && new_x <= F) {	// 1층부터 F층 사이에 해당하는 층이라면
				if (!visited[new_x]) {	// 아직 방문하지 않은 층이라면
					visited[new_x] = true;
					q.push(new_x);
					cnt[new_x] = cnt[tmp] + 1;	// 이전층까지의 누른 버튼 수에서 1 버튼 수 추가
				}
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);     // 시간초과방지

	cin >> F >> S >> G >> U >> D;
	dx[0] = U;	// 위쪽 방향
	dx[1] = -D;		// 아래쪽 방향
	bfs(S);	

	if (!visited[G])
		cout << "use the stairs";
	else
		cout << cnt[G];

	return 0;
}