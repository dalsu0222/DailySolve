#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int n;
int testcase;
int arr[10] = { 0, };

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);     // 시간초과방지

	cin >> testcase;	// 테스트케이스의 갯수
	for (int j = 0; j < testcase; j++) {
		for (int i = 0; i < 10; i++) {
			cin >> arr[i];
		}
		sort(arr, arr + 10);		// nlogn
		// 8번째 수 출력
		cout << arr[7] << endl;
	}

	return 0;
}