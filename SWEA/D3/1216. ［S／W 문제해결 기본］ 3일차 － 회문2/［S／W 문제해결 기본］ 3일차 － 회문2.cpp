#include<iostream>

using namespace std;
char map[100][100];

int main()
{
	int t;
	for (int tc = 1; tc <= 10; tc++) {
		cin >> t;
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> map[i][j];
			}
		}

		int max_d = 1;	// 최대 길이의 회문수
		// 가로방향
		for (int i = 0; i < 100; i++) {	// i : 몇번째 가로인지
			for (int l = 0; l < 100; l++) {	// l : 왼쪽 (시작하는) 인덱스
				for (int r = l + 1; r < 100; r++) {	// r: 오른쪽 (끝나는) 인덱스
					int d = r - l + 1;		// 회문의 길이
					bool isPal = true;		// 회문인지의 여부
					for (int k = 0; k < d / 2; k++) {	// 회문인지 판별
						if (map[i][l + k] != map[i][r - k])
							isPal = false;
					}
					if (isPal && max_d < d)	// 최댓값 갱신
						max_d = d;
				}
			}
		}
		// 세로방향
		for (int i = 0; i < 100; i++) {
			for (int l = 0; l < 100; l++) {
				for (int r = l + 1; r < 100; r++) {
					int d = r - l + 1;
					bool isPal = true;
					for (int k = 0; k < d / 2; k++) {
						if (map[l + k][i] != map[r - k][i])
							isPal = false;
					}
					if (isPal && max_d < d)
						max_d = d;
				}
			}
		}

		cout << "#" << t << " " << max_d << "\n";
	}

	return 0;
}