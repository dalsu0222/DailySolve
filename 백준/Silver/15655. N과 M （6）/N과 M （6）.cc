#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M;
int arr[9];
vector <int> A;

void dfs(int num, int x) {
	if (x == M) {		// 목표 개수까지 도달했다면
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
	}
	else {	// 목표 개수에 도달하지 못했다면
		for (int i = num; i < A.size(); i++) {		// 입력된 수(vector A에 저장된 수)를 바탕으로 노드 방문
				arr[x] = A[i];		// 정답 배열의 위치 x에 i 기록
				dfs(i + 1, x + 1);		// 다음 위치(x+1)로 더 깊게 들어가기
										// 다음(i+1번째)원소부터 수열 만드는 원소의 후보로 지정
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
	dfs(0, 0);

	return 0;
}
