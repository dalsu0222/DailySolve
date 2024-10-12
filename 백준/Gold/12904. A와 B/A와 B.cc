#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
string s, t;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s >> t;

	// T -> S 로 가는 방법, 최대 N(문자열 길이)번만 반복하면 됨.
	while (s.length() < t.length()) {
		if (t[t.length() - 1] == 'A') {
			t.erase(t.length() - 1);
		}
		else {	// 맨 끝이 'B'
			t.erase(t.length() - 1);
			reverse(t.begin(), t.end());
		}
	}
	if (t == s)
		cout << 1;
	else
		cout << 0;

	return 0;
}
