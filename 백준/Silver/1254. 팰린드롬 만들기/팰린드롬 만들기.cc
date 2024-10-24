#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
string s;

bool isPalindrome(string str) {
	for (int i = 0; i < str.size() / 2; i++) {
		if (str[i] != str[str.size() - 1 - i]) {
			return false;
		}
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s;
	int minValue = s.size() * 2 - 1;
	// 팰린드롬이 생길 수 있는 최소한의 시작위치 찾기, 뒤에 i개 만큼 뒤집어 더하면 팰린드롬이 됨
	for (int i = 0; i < s.size(); i++) {
		string tmp = s.substr(i, s.size()- i);	// substr(pos,len) : pos부터 시작해 len길이만큼의 문자열 반환
		if (isPalindrome(tmp)) {
			minValue = s.size() + i;
			break;
		}
	}

	cout << minValue;
	
	return 0;
}
