#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;
int n, m;
int v1, v2;
vector<int> map[101];
bool visited[101];
int result;
			
void bfs(int v, int depth) {		// 촌 계산을 위해 bfs 깊이 활용
	visited[v] = true;
	queue<pair<int, int>> q;
	q.push(make_pair(v, 0));
	while (!q.empty()) {
		pair<int, int> tmp = q.front();
		int x = tmp.first;		// 방문 노드
		int x_d = tmp.second;		// 방문 노드의 깊이
		q.pop();
		for (int i = 0; i < map[x].size(); i++) {
			int new_x = map[x][i];
			if (visited[new_x])		// 이미 방문한 경우 pass
				continue;
			if (new_x == v2) {		// 목표 노드일 경우 해당 노드까지 방문한(+1) 촌수로 정답 저장
				result = x_d + 1;
				return;
			}
			visited[new_x] = true;
			q.push(make_pair(new_x, x_d + 1));
		}
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> n;
	cin >> v1 >> v2;
	cin >> m;
	int t1, t2;
	for (int i = 0; i < m; i++) {
		cin >> t1 >> t2;
		map[t1].push_back(t2);
		map[t2].push_back(t1);
	}

	bfs(v1, 0);
	if (result != 0)
		cout << result;
	else
		cout << -1;

	return 0;
}