#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n, m;

int search(int vnow, int v2, vector<vector<pair<int, int>>> v, vector<bool> visited) {
	// bfs 이용하여 v1에서 시작하여 목표노드인 v2 찾기
	visited[vnow] = true;
	queue<pair<int, int>> q;
	q.push({ vnow, 0 });
	while (!q.empty()) {
		int tmpv = q.front().first;
		int tmpw = q.front().second;
		q.pop();
		if (tmpv == v2) {
			return tmpw;
		}
		for (int i = 0; i < v[tmpv].size(); i++) {
			int nv = v[tmpv][i].first;
			int weight = v[tmpv][i].second;
			if (!visited[nv]) {
				visited[nv] = true;
				q.push({ nv, tmpw + weight });
			}
		}
	}
	return -1;	// 목표 노드를 못찾은 경우
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	int v1, v2, w;
	vector<vector<pair<int, int>>> v(n + 1);	// 1~n 정점
	for (int i = 0; i < n - 1; i++) {
		cin >> v1 >> v2 >> w;
		v[v1].push_back({ v2,w });
		v[v2].push_back({ v1,w });
	}
	for (int i = 0; i < m; i++) {
		cin >> v1 >> v2;
		vector<bool> visited(n + 1, false);
		cout << search(v1, v2, v, visited) << "\n";	// v1에서 시작하여 목표노드인 v2 찾기
	}

	return 0;
}
