#include <iostream>
#include <string>
#include <cstring>

using namespace std;
string S, P;
int result;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> S >> P;

	for (int i = 0; i < P.size(); i++) {
		int cnt = 0;
		int max_cnt = 0;	// P[i]로 시작하는 부분 문자열 중 최대길이
		int idx = i;	// i부터 시작하여 P의 인덱스를 가리킴
		for (int j = 0; j < S.size(); j++) {
			while (j < S.size() && idx < P.size() &&  P[idx] == S[j] ) {
				cnt++;
				idx++;
				j++;
			}
			// P[idx] != S[j] 인 경우
			max_cnt = max(max_cnt, cnt);
			cnt = 0;
			idx = i;
		}
		i += max_cnt - 1;	// 최대길이 반영하여 skip, 직후에 바로 i++ 될걸 고려하여 -1 해줌
		result++;
	}
	cout << result;

	return 0;
}
