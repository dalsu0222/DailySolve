#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
int visited[501];	// 트리 깊이 저장

bool isTree(vector<vector<int>> v, int st) {
	queue<int> q;
	q.push(st);
	visited[st] = 1;
	bool tree = true;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < v[cur].size(); i++) {
			int nxt = v[cur][i];  // 인접한 정점 가져오기

			// 인접한 정점이 이미 방문했지만, 부모 노드가 아닌 경우 -> 사이클 존재
			// 이미 방문한 노드의 경우, 현재 노드의 부모노드일 가능성이 있으니 체크해줌
			if (visited[nxt] && visited[nxt] != visited[cur] - 1) {
				tree = false;
			}
			if (visited[nxt])
				continue;

			visited[nxt] = visited[cur] + 1;
			q.push(nxt);
		}
	}
	return tree;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	int tc = 1;
	while (1) {
		cin >> n >> m;
		if (n == 0 && m == 0) {
			break;
		}
		vector<vector<int>> v(n + 1);
		int v1, v2;
		for (int i = 0; i < m; i++) { // 인접 리스트 만듦
			cin >> v1 >> v2;            
			v[v1].push_back(v2);                    
			v[v2].push_back(v1);        
		}
		memset(visited, 0, sizeof(visited));
		int result = 0;
		for (int i = 1; i <= n; i++) {
			if (!visited[i] && isTree(v, i)) {
				result++;
			}
		}

		cout << "Case " << tc++ << ": ";
		if (result > 1)
			cout << "A forest of " << result << " trees.";
		else if (result == 1)
			cout << "There is one tree.";        
		else             
			cout << "No trees.";        
		cout << "\n";
	}

	return 0;
}
