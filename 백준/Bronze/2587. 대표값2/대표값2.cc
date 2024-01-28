#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int arr[5];
int total, mid;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);     // 시간초과방지

	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
		total += arr[i];
	}

	// sort 함수의 시간복잡도 : nlogn
	sort(arr, arr + 5);		// 두번째 인자 : (배열의 포인터) + (배열의 크기)
	mid = arr[2];

	cout << total / 5 << "\n";
	cout << mid << "\n";

	return 0;
}