#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	string poly1 = "AAAA";
	string poly2 = "BB";
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '.')	continue;

		int cnt = 0;
		int start = i;
		while (i < s.size() && cnt < 4 && s[i] == 'X' ) {
			cnt++;
			i++;
		}
		if (cnt == 4) {
			for (int j = start; j < i; j++) {
				s[j] = 'A';
			}
			i--;	// 다음 연산을 위해 i를 1 감소
		}
		else if (cnt == 2) {
			for (int j = start; j < i; j++) {
				s[j] = 'B';
			}
			i--;	// 다음 연산을 위해 i를 1 감소
		}
		else {	// 가지고있는 폴리오미노가 아닌경우, 덮을 수 없음
			cout << -1;
			return 0;
		}
	}
	for (int i = 0; i < s.size(); i++) {
		cout << s[i];
	}
	
	return 0;
}
