#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;
int tc, n;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> tc;
	string w, t;	// 의상, 의상의 종류
	for (int i = 0; i < tc; i++) {
		cin >> n;

		map<string, int> f;	// map에서 int는 0으로 초기화
		for (int j = 0; j < n; j++) {
			cin>> w >> t;
			
			if (f.find(t) != f.end()) {
				//f.find(t)->second++;
				f[t]++;
			}
			else {
				f.insert(make_pair(t, 1));
			}
			
			//f[t]++;	// 위 if-else문을 1줄로 표현 가능
		}

		int cnt = 1;
		for (auto iter = f.begin(); iter != f.end(); iter++) {	//	(현재 옷타입의 개수 + 1) 을 곱해나가면서 총 경우의수를 구해준다.
			cnt *= iter->second + 1;
		}
		
		
		cout << cnt - 1 << "\n";	// 아무것도 안 입은 경우 제외하고 경우의수 출력
	}

	return 0;
}