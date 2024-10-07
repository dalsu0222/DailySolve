#include <iostream>
#include <vector>
#include <algorithm> // remove 사용

using namespace std;
int n, deleteV;
int cnt;

void search(int v, vector<vector<int>> tree, vector<int> parent) {
	int length = tree[v].size();
	if (length == 0) {	// 리프 노드일 경우, 카운트
		cnt++;
		return;
	}
	for (int i = 0; i < length; i++) {	// 각 자식노드별로 search 다시 수행
		search(tree[v][i], tree, parent);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	vector<vector<int>> tree(n);
	vector<int> parent(n, -1);
	int root = 0;
	for (int i = 0; i < n; i++) {
		cin >> parent[i];
		if (parent[i] == -1) {
			root = i;
			continue;
		}
		tree[parent[i]].push_back(i);
	}
	cin >> deleteV;
	if (root == deleteV) {
		cout << 0;
		return 0;
	}
	// 부모 노드에서 삭제할 노드 제거
	tree[parent[deleteV]].erase(
		remove(tree[parent[deleteV]].begin(), tree[parent[deleteV]].end(), deleteV),
		tree[parent[deleteV]].end()
	);
	search(root, tree, parent);

	cout << cnt;

	return 0;
}
