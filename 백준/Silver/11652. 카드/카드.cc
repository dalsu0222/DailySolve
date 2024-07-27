#include <iostream>
#include <map>

using namespace std;
long long n, tmp;
map<long long, long long> m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	long long max = 0;
	long long int maxN = 0;

	for (int i = 0; i < n; i++) {
		cin >> tmp;
		m[tmp]++;	// map : 중복걱정 X, value 기본값 0
	}

	for (auto& map : m){
		if (map.second > max){
			//map의 value값 갱신
			max = map.second;
			//map의 key값 갱신
			maxN = map.first;
		}
	}
	cout << maxN;

	return 0;
}