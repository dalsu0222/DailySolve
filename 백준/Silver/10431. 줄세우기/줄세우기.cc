#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;
int P, T;

int main(void)
{
	cin >> P;
	for (int i = 0; i < P; i++) {
		cin >> T;
		int cnt = 0;	// 학생들이 뒤로 물러난 걸음 수
		vector<int> v(20);
		for (int j = 0; j < 20; j++) {
			cin >> v[j];
		}

		for (int j = 0; j < 20; j++) {	// 학생 한 명 기준으로 삼기
			for (int k = j; k < 20; k++) {	
				// 기준이 되는 학생의 뒤에 있는 학생들이 더 키가 크다면, 그때마다 1칸씩 이동
				if (v[j] > v[k]) {
					cnt++;
				}
			}
		}

		cout << i + 1 << " " << cnt << "\n";
	}

	
	return 0;
}