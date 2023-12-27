#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <stack>

using namespace std;

int N, M;
int arr[9];

void dfs(int num, int x) {
	if (x == M) {		// 목표 개수까지 도달했다면
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
	}
	else {	// 목표 개수에 도달하지 못했다면
		// 비내림차순 고려하여 자식노드 검사(num~N)
		for (int i = num; i <= N; i++) {
			arr[x] = i;		// 정답 배열의 위치 x에 i 기록
			dfs(i , x + 1);		// 다음 위치(x+1)로 더 깊게 들어가기, (k k) 꼴도 가능하므로 시작지점은 'i'로 전달
		}
	}
}

int main(void)

{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	dfs(1, 0);

	return 0;
}
