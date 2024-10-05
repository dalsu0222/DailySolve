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
		int cntI = 0;	int cntO = 0;
		bool isChecking = false;
		char now = s[i];
		if (now == 'O')
			continue;

		// now == 'I'
		cntI++;
		for (int j = i + 1; j <= i + n * 2; j++) {
			if (s[j - 1] == 'I' && s[j] == 'O') {	// I 직후 O가 나오는 경우
				cntO++;
			}
			else if (s[j - 1] == 'O' && s[j] == 'I') {	// O 직후 I가 나오는 경우
				cntI++;
			}
			else { break; }
		}
		if (cntI == n + 1 && cntO == n) {
			result++;
		}

	}
	cout << result;

	return 0;
}
