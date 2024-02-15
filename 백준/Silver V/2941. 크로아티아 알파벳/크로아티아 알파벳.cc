#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;
string s;
string alp[8] = { "c=","c-","dz=","d-","lj","nj","s=","z=" };

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);     // 시간초과방지

	cin >> s;
	for (int i = 0; i < 8; i++) {
		while (1) {	// 대체할 동일한 단어가 여러개인경우 전부 바꾸기
			if (s.find(alp[i]) != -1) {	//  find : string에서 못찾을시 -1 반환
				s.replace(s.find(alp[i]), alp[i].length(), "#");	// replace(처음으로 찾은 위치, 바꿀 길이, 대체단어)
			}
			else
				break;
		}
	}

	cout << s.length();	// 하나의 알파벳으로 바뀐 크로아티아 알파벳 단어 출력

	return 0;
}