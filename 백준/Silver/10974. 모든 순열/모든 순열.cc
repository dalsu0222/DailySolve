#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;

// N과 M 시리즈와 유사한 문제
int N;
int arr[9];
bool visited[9];

// dfs 사용하여 백트래킹 이용
void dfs(int x) {
	if (x == N) {	// N번째 위치에 도달하면 정답배열 출력
		for (int i = 0; i < N; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
	}
	else {
		for (int i = 1; i <= N; i++) {
			if (!visited[i]) {
				visited[i] = true;
				arr[x] = i;
				dfs(x + 1);	// 다음 위치로 넘어가기
				visited[i] = false;	// 백트래킹 설정
			}
		}
	}
}

int main(void)

{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	dfs(0);
	
	return 0;
}
