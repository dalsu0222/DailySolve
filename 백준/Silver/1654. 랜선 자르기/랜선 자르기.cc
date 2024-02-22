#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int K, N;

vector<long long> Oh(10000);	// 1<= K <=10,000


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);     // 시간초과방지

	cin >> K >> N;
	
	long long max_Oh = 0;
	for (int i = 0; i < K; i++) {
		cin >> Oh[i];
		//if (max < Oh[i])
			//max = Oh[i];
		max_Oh = max(max_Oh, Oh[i]);
	}

	long long start = 1;		// 무조건 랜선을 만들 수 있는 길이
	long long end = max_Oh;		// 무조건 랜선을 만들 수 없는 길이(K개의 랜선중 최대 길이값)

	long long max_length = 0;		// 1 말고 0으로 초기화(아예 만들 수 없을 수 있으니까)
	while (start <= end) {	// 등호 포함!
		long long mid = (start + end) / 2;
		long long sum = 0;
		
		// 자르고 나온 몫의 합 누적
		for (int i = 0; i < K; i++)
			sum += Oh[i] / mid;

		if (sum >= N) {		// 최소 개수(N개) 만족한 경우
			start = mid + 1;		
			//if (max_length < mid)
				//max_length = mid;
			max_length = max(max_length, mid);
		}
		else {
			end = mid - 1;
		}
	}	

	cout << max_length;

	return 0;
}
