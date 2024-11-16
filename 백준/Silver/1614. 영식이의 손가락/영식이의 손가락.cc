#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
long long canCnt;
int finger;

int main() {

	cin >> finger >> canCnt;
	
	//몇 번째 손가락을 몇 번까지만 사용할 수 있는지에 따라 셀 수 있는 수가 전부 다름.
	// 그에 따른 규칙찾기
	if (finger == 1)	 cout << canCnt * 8;
	else if (finger == 5)	cout << 4 + 8 * canCnt;
	else if (finger == 2)	cout << 1 + 6 * ((canCnt + 1) / 2) + 2 * (canCnt / 2);
	else if (finger == 3)	cout << 2 + canCnt * 4;
	else if (finger == 4)	cout << 3 + 2 * ((canCnt + 1) / 2) + 6 * (canCnt / 2);
	
	return 0;
}