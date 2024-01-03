#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;

int N, M;
int arr[9];
//bool visited[9];
vector <int> A;	// 입력받은 N개의 자연수
set<vector<int>> s;		// 정답 수열 저장(중복 방지)

void dfs(int x) {
	if (x == M) {		// 목표 개수까지 도달했다면
		vector<int> v;		// 1개의 정답 수열
		for (int i = 0; i < M; i++) {
			v.push_back(arr[i]);
		}
		s.insert(v);	// set에 추가(중복 수열 방지)
	}
	else {	// 목표 개수에 도달하지 못했다면
		for (int i = 0; i < N; i++) {		// 입력된 수(vector A에 저장된 수)의 모든 노드를 방문
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

	// 중복제거한 수열만을 출력
	for (auto vector : s) {
		for (auto temp : vector) {	// 개별 벡터 안의 원소 하나씩 출력
			cout << temp << " ";
		}
		cout << "\n";
	}

	return 0;
}
