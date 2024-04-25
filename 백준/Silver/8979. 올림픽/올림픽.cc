#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;
int N, X;
vector<int> v[1001];	// 각 나라를 인덱스로 활용, 각 나라별 v[i]에 차례대로 금,은,동 메달 수 push
int r = 1;	// 찾고자 하는 나라의 ranking

int main(void)
{
	cin >> N >> X;
	int tmp, medal;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		for (int j = 0; j < 3; j++) {	// v[n][0] : n나라의 금메달 수, v[n][1] : 은메달 수, v[n][2] : 동메달 수
			cin >> medal;
			v[tmp].push_back(medal);
		}
	}

	for (int i = 1; i <= N; i++) {
		if (v[i][0] > v[X][0]) {	// 찾고자하는 나라의 금메달 수가 더 작은경우
			r++;
		}
		else if (v[i][0] == v[X][0]) {	// 금메달 수는 동일하지만
			if (v[i][1] > v[X][1]) {	// 찾고자하는 나라의 은메달 수가 더 작은경우
				r++;
			}
			else if (v[i][1] == v[X][1]) {	// 은메달 수도 동일하지만
				if (v[i][2] > v[X][2]) {	// 찾고자하는 나라의 동메달 수가 더 작은경우
					r++;
				}
			}
		}
	}
	cout << r;	
	
	return 0;
}