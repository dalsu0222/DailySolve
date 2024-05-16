#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int tc;
	int T;

	cin >> T;
	string s[10] = { "ZRO", "ONE", "TWO", "THR", "FOR", "FIV", "SIX", "SVN", "EGT", "NIN" };

	for (tc = 1; tc <= T; ++tc) {
		string tn;
		int n;
		cin >> tn >> n;
		vector<string> word(n);
		vector<int> num(n);		// 숫자 등장 횟수 카운트
		for (int i = 0; i < n; i++) {
			cin >> word[i];
			for (int j = 0; j < 10; j++) {
				if (s[j] == word[i]) {	// 문자열에 해당하는 숫자를 카운트 해주기
					num[j]++;
					break;
				}
			}
		}
		
		cout << tn << "\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < num[i]; j++) {	// 각 숫자별로 등장횟수만큼 출력
				cout << s[i] << " ";
			}
		}

	}
	return 0;
}