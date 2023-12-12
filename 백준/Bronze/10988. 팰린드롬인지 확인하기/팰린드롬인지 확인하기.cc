#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	string s;

	cin >> s;

	for (int i = 0; i < s.length() / 2; ++i) {        // 길이 짝수 홀수 상관 X
		if (s[i] != s[s.length() - i - 1]) {    // 마주보고있는 문자와 다르다면 바로 종료
			cout << "0";
			return 0;
		}
	}

	cout << "1";
	return 0;
}