#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M;
int arr[9];
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
			// visited[] 사용하지 않음.(중복 허용)	
			arr[x] = A[i];		// 정답 배열의 위치 x에 i 기록
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
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		A.push_back(tmp);
	}
	sort(A.begin(), A.end());	// 사전 순으로 증가하기 위해 사전에 정렬
	dfs(0);

	return 0;
}
