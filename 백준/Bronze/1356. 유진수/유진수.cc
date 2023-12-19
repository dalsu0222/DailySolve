#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
string num;

int main(void)

{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> num;
	int len = num.length();
	int result = 1;
	for (int i = 0; i < len; i++) {
		result *= (num[i] - '0');		// 앞부분 자리수 곱
		int tmp = 1;
		for (int j = i + 1; j < len; j++) {
			tmp *= (num[j] - '0');		// 뒷부분 자리수 곱
		}
		if (result == tmp && num != "1") {	// N!=1 이고 앞부분 자리수 = 뒷부분 자리수 이면 유진수
			cout << "YES";
			return 0;
		}
	}

	cout << "NO";

    return 0;
}
