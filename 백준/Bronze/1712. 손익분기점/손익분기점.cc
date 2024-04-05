#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
int A, B, C, result;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);

	cin >> A >> B >> C;
	if (B >= C) {	// 가변비용이 판매비용보다 크면 손익분기점 발생 X
		cout << "-1";
	}
	else {
		result = A / (C - B) + 1;
		cout << result;
	}

	return 0;
}