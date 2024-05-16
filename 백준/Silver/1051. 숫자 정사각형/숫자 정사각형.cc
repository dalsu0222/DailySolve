#include<iostream>
#include<string>

using namespace std;

int n, m;
int map[50][50];

int main(int argc, char** argv)
{
	cin >> n >> m;
	int min_d = n < m ? n : m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			map[i][j] = s[j] - '0';
		}

	}

	int result = 1;
	for (int i = 0; i < n; i++) {	// 매 위치마다 가능한 정사각형을 전부 그린다.
		for (int j = 0; j < m; j++) {
			for (int r = 1; r < min_d; r++) {	// r : 정사각형의 한 변의 길이
				if (i + r >= n || j + r >= m)	// 인덱스 범위 초과 -> 정사각형 못 만듦
					continue;
				// 다중비교식 적을때, 꼭 &&로 끊어서 적기!!
				// 이어서 적어버리면, 앞의 결과값을 이어받아 비교하므로, true == map[i+r][j] 처럼 동작함.
				if (map[i][j] == map[i + r][j] && map[i + r][j] == map[i + r][j + r] && map[i + r][j + r] == map[i][j + r]) {
					int area = (r + 1) * (r + 1);
					if (result < area)
						result = area;
				}
			}
		}
	}

	cout << result;

	return 0;
}