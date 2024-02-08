#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int N;
int a, b;
vector<int> v[100001];
int parent[100001];
bool visited[100001];

void bfs(int x) {
	visited[x] = true;
	queue<int> q;
	q.push(x);
	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		for (int i = 0; i < v[tmp].size(); i++) {
			int next = v[tmp][i];		// tmp 정점의 이웃 정점들 가져오기
			if (!visited[next]) {
				visited[next] = true;
				parent[next] = tmp;		// 이웃노드의 부모노드 기록
				q.push(next);
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);     // 시간초과방지

	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	bfs(1);

	for (int i = 2; i <= N; i++) {
		cout << parent[i] << "\n";
	}

	return 0;
}