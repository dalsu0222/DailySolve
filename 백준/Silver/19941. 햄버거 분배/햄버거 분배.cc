#include <iostream>

using namespace std;
int n, k, cnt;
string s;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'P') {
			// 현재 위치를 기준으로, -k ~ +k 범위의 먼곳부터 햄버거 먹기.
			for (int j = i - k; j <= i + k; j++) {
				if (0 <= j && j < n && s[j] == 'H') {
					cnt++;
					s[j] = '.';
					break;
				}
			}
		}
	}
	cout << cnt;

	return 0;
}
