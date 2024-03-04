#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;
int N, M;
vector<int> map[101];		// 벡터배열로 접근
bool visited[101];
int cnt;

void bfs(int v) {
	visited[v] = true;
	queue<int> q;
	q.push(v);
	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		for (int i = 0; i < map[tmp].size(); i++) {		// 인접노드 검사
			int v2 = map[tmp][i];
			if (visited[v2])
				continue;
			visited[v2] = true;		// 방문한 적이 없는 인접노드에 대하여 방문, 감염 개수 증가
			q.push(v2);
			cnt++;
		}
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);

	cin >> N >> M;
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		map[a].push_back(b);		// 양방향 노드
		map[b].push_back(a);
	}

	bfs(1);
	cout << cnt;

	return 0;
}