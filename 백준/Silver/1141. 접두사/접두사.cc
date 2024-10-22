#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;

bool isPrefix(string a, string b) {	// a가 b의 접미사로 쓰일 수 있는지
	if (a.size() > b.size())
		return false;

	bool canPrefix = true;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] != b[i])
			canPrefix = false;
	}
	return canPrefix;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	vector<string> s(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	sort(s.begin(), s.end());
	vector<string> answer;
	answer.push_back(s[0]);	// n이 1인경우에도 부분집합으로 구성
	for (int i = 0; i < n; i++) {
		string tmp = s[i];
		for (int j = i + 1; j < n; j++) {
			string tmp2 = s[j];
			if (isPrefix(tmp, tmp2)) {
				// tmp1이 이미 있다면, tmp1을 tmp2로 대체하고 탈출
				auto it = find(answer.begin(), answer.end(), tmp);
				if(it != answer.end()) {	// answer에 tmp가 이미 있다면
					answer[it - answer.begin()] = tmp2;	// tmp를 tmp2로 대체
					break;
				}
				else {	
					answer.push_back(tmp2);
					break;
				}
			}
			else {
				answer.push_back(tmp2);
				break;
			}
		}
	}

	cout << answer.size();
	
	return 0;
}
