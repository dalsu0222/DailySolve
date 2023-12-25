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

void dfs(int num, int x) {	// 오름차순 위한 변수(최소시작지점), 위치지정변수(x) 추가
	if (x == M) {		// M까지 들어갔을 때
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
	}
	else {	// M 까지 들어가지 못했다면
		// num(>=1)부터 시작하는 자식노드에 대해 검사(num~N)
		for (int i = num; i <= N; i++) {
				arr[x] = i;		// 정답 배열의 위치 x에 i 기록
				dfs(i + 1, x + 1);		// 다음 위치(x+1)로 더 깊게 들어가기
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
