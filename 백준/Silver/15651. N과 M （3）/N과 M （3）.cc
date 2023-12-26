#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <stack>

using namespace std;

int N, M;
int arr[9];
//bool visited[9];

void dfs(int x) {
	if (x == M) {		// 목표 개수까지 도달했다면
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
	}
	else {	// 목표 개수에 도달하지 못했다면
		// 모든 자식노드에 대해 검사(1~N)
		for (int i = 1; i <= N; i++) {
			// 기존(N과M (1))처럼 방문을 검사할 필요 없이, 중복 허용하여 기록
			arr[x] = i;		// 정답 배열의 위치 x에 i 기록
			dfs(x + 1);		// 다음 위치(x+1)로 더 깊게 들어가기
		}
	}
}

int main(void)

{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	dfs(0);

	return 0;
}
