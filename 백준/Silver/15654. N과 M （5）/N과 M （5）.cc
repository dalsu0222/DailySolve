#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <stack>

using namespace std;

int N, M;
int arr[9];
bool visited[10001];		// 10000거나 작거나 같은 수 입력 가능
vector <int> A;

void dfs(int x) {
	if (x == M) {		// 목표 개수까지 도달했다면
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
	}
	else {	// 목표 개수에 도달하지 못했다면
 		for (int i = 0; i < A.size(); i++) {		// 입력된 수(vector A에 저장된 수)를 바탕으로 노드 방문
			if (!visited[A[i]]) {		// 방문하지 않은 노드에 대해
				visited[A[i]] = true;
				arr[x] = A[i];		// 정답 배열의 위치 x에 i 기록
				dfs(x + 1);		// 다음 위치(x+1)로 더 깊게 들어가기
				visited[A[i]] = false;		// 백트래킹 설정(다른 경우 계산을 위해)
			}
		}
		
	}
}

int main(void)

{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		A.push_back(tmp);
	}
	sort(A.begin(), A.end());	// 사전 순으로 증가하기 위해 사전에 정렬
	dfs(0);

	return 0;
}
