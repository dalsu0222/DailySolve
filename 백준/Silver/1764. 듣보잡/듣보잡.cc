#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>		// map을 사용하면 M번만 확인하면 되므로 n^2보다 실행시간이 빨라진다.

using namespace std;

int N, M;
map <string, bool> dict;	// (이름,첫번째 집합에 존재하는지 유무) 저장
vector <string> result;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);     // 시간초과방지

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		dict.insert(make_pair(tmp,true));		// 듣도 못한 사람
	}
	for (int i = 0; i < M; i++) {
		string tmp;
		cin >> tmp;
		if (dict[tmp]) {		// 듣도 못한 사람에 존재하는 이름이라면 중복 원소로 체크
			result.push_back(tmp);
		}
	}


	cout << result.size() << "\n";		
	sort(result.begin(), result.end());		// 사전순으로 정렬
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << "\n";

	return 0;
}