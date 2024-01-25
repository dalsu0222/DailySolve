#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;
int L, C;
char arr[16];
bool visited[16];
vector<char> code;

void find_code(int idx, int x) {
	if (x == L) {
		// 최소 1개의 모음과 2개의 자음으로 구성되도록, 암호 출력 전 검사하기
		bool isVowel = false;
		int consCnt = 0;
		for (int i = 0; i < L; i++) {
			if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' ||
				arr[i] == 'o' || arr[i] == 'u')
				isVowel = true;
			else
				consCnt++;
		}
		// 모음과 자음의 최소 개수를 만족하는 암호만 출력
		if (isVowel && consCnt >= 2) {
			for (int i = 0; i < L; i++) {
				cout << arr[i];
			}
			cout << "\n";
		}
	}
	else {
		for (int i = idx; i < C; i++) {
			if (!visited[i]) {
				visited[i] = true;
				arr[x] = code[i];
				find_code(i + 1, x + 1);	// i+1번째 인덱스 문자를 x+1번째 자리에 기입
				visited[i] = false;		// 백트래킹 이용
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);     // 시간초과방지

	cin >> L >> C;
	
	for (int i = 0; i < C; i++) {
		char tmp;
		cin >> tmp;
		code.push_back(tmp);
	}

	sort(code.begin(), code.end());		// 암호는 알파벳이 암호에서 증가하는 순서로 배열됨

	find_code(0, 0);
	
	return 0;
}