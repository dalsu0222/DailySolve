#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int k;
int A[14];
int arr[14];
bool visited[14];

void dfs(int num, int x) {		// num : A의 인덱스, x : arr의 depth
	if (x == 6) {
		vector<int> v;
		for (int i = 0; i < 6; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
	}
	else {
		for (int i = num; i < k; i++) {
			arr[x] = A[i];
			dfs(i + 1, x + 1);
		}
	}
}

int main(void)

{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		cin >> k;
		if (k == 0)
			break;
		for (int i = 0; i < k; i++) {
			cin >> A[i];
		}
		dfs(0, 0);
		cout << "\n";
		
		// 어차피 k개 만큼 사용하기 때문에, 초기화단계는 생략해도 됨
		memset(A, 0, sizeof(A));
		memset(visited, false, sizeof(visited));
	}
		
	return 0;
}
