#include<iostream>
#include<cstring>

using namespace std;
int n;
int result;
int col[10];	// col[i] : i번째 행에 놓인 퀸의 열 위치

bool check(int level) {
	for (int i = 0; i < level; i++) {
		if (col[level] == col[i] || abs(col[level] - col[i]) == abs(level - i))
			return false;
	}
	return true;
}

void dfs(int x) {	// x 번째 행
	if (x == n) {
		result++;
		return;
	}
	for (int i = 0; i < n; i++) {
		col[x] = i;	// x번째 행의 i열에 퀸 배치
		if (check(x))
			dfs(x + 1);

	}
}

int main(){
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> n;
		dfs(0);
		cout << "#" << tc << " " << result << "\n";
		memset(col, 0, sizeof(col));
		result = 0;
	}

    
	return 0;
}