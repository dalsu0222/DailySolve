#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dna[51][4];	// A, T, G, C 순
int ATGC[4] = { 'A', 'C', 'G', 'T' };

int main() {
	int n, m;
	cin >> n >> m;
	vector<string> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	
	// 각 자리별로 가장 많이 등장하는 알파벳 체크
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			char tmp = v[j][i];
			if (tmp == 'A')
				dna[i][0]++;
			else if (tmp == 'C')
				dna[i][1]++;
			else if (tmp == 'G')
				dna[i][2]++;
			else   // tmp == 'T'
				dna[i][3]++;
		}
	}

	// 각 자리에 가장 많이 등장하는 알파벳을 사용
	string s = "";
	for (int i = 0; i < m; i++) {
		int max_c = 0;
		char max_ch = ATGC[0];
		for (int j = 0; j < 4; j++) {
			if (max_c < dna[i][j]) {
				max_c = dna[i][j];
				max_ch = ATGC[j];
			}
		}
		s += max_ch;
	}
	// distance 재기
	int d = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[j] != v[i][j])
				d++;
		}
	}

	cout << s << "\n";
	cout << d;

	
	return 0;
}