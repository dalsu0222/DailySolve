#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int N, M;
int u, v;
vector<int> G[1001];
bool visited[1001];
int cnt;

void bfs(int x) {
	visited[x] = true;
	queue<int> q;
	q.push(x);
	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		for (int i = 0; i < G[tmp].size(); i++) {
			if (!visited[G[tmp][i]]) {
				visited[G[tmp][i]] = true;
				q.push(G[tmp][i]);
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);     // 시간초과방지

	cin >> N >> M;
	while (M--) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {	// 각 노드마다 bfs 실행, 한 노드에서 갈 수 있는 모든 노드들 체크
			bfs(i);
			cnt++;	// 연결 요소 수 증가
		}
	}

	cout << cnt;

	return 0;
}