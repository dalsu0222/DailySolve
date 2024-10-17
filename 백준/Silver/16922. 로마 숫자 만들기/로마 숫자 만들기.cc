#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
int n;
int num[4] = { 1,5,10,50 };
bool isNum[10000];	// 이미 만든숫자인지 확인
int result;

void func(int cnt, int number, int idx) {
	if (cnt == n) {
		if (isNum[number]) return;
		isNum[number] = true;
		result++;
		return;
	}
	for (int i = idx; i < 4; i++) {
		func(cnt + 1, number + num[i], i);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	func(0, 0, 0);
	cout << result;
	
	return 0;
}
