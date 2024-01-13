#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int num;

void isPerfectNum(int x) {
	vector<int> d;
	for (int i = 1; i < x; i++) {	// 자기 자신은 제외한 모든 약수
		if (x % i == 0)
			d.push_back(i);
	}
	int total = 0;
	for (int i = 0; i < d.size(); i++) {
		total += d[i];
	}
	if (total == x) {		// 완전수인 경우
		cout << x << " = ";
		for (int i = 0; i < d.size() - 1; i++) {
			cout << d[i] << " + ";
		}
		cout << d[d.size() - 1] << "\n";
	}
	else {		// 완전수가 아닌 경우
		cout << x << " is NOT perfect.\n";
	}
}

int main(void)

{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		cin >> num;
		if (num == -1)
			break;

		isPerfectNum(num);
	}

	return 0;
}
