#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
int n, m, result;
string s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> s;
	// Pn = n+1개의 I와 n개의 O
	
	for (int i = 0; i < m; i++) {
		int cnt = 0;	// 처음 I 뒤의 'OI' 개수
		if (s[i] == 'O') continue;
		// s[i] == 'I'
		while (s[i + 1] == 'O' && s[i + 2] == 'I') {
			cnt++;
			if (cnt == n) {
				result++;
				cnt--;	// i+=2로 뛰어넘을걸 고려하여, 앞에있던 'OI' 제외시켜줌
			}
			i += 2;
		}

	}
	cout << result;

	return 0;
}
