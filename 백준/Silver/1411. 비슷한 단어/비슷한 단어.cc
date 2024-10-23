#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
int n, result;

bool isShom(string s1, string s2) {
	map <char, char> m;	// key : 바꿈의 대상 문자, value : 바뀐 문자
	vector<bool> isChanged(26, false);
	for (int i = 0; i < s1.size(); i++) {
		if (m.find(s1[i]) == m.end()) {	// 바꿈 대상 문자 s1[i]가 아직 바뀐적이 없는경우 
			if (isChanged[s2[i] - 'a']) {	// 바뀐 문자 s2[i]가 이미 쓰인경우
				return false;
			}
			m.insert({ s1[i], s2[i] });	// s1[i] -> s2[i]로 바뀜
			isChanged[s2[i] - 'a'] = true;	// s2[i]가 쓰임을 표시
		}
		else {	// 바꿈 대상 문자 s1[i]가 이미 쓰였던 경우
			if (m[s1[i]] != s2[i]) {	// 바뀌어야하는 문자가 아닌경우, false
				return false;
			}
		}
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (isShom(v[i], v[j])) {
				result++;
			}
		}
	}

	cout << result;
	
	return 0;
}
