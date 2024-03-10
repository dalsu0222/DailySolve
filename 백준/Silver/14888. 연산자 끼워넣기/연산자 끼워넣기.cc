#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <deque>

using namespace std;
int N;
vector<long long> A;
int oper[4];	// 덧셈, 뺄셈, 곱셈, 나눗셈 개수 순
vector<int> oper2;	// 연산자 일렬로 저장
long long min_r = 1000000001, max_r = -1000000001;	// 초기화 값 수정
int bt[12];	// 자리별로 연산자 type 저장 , type 0 :덧셈, 1:뺄셈, 2:곱셈, 3:나눗셈
bool visited[10];

/*
아이디어 : 백트래킹 이용
0. 입력받은 연산자 타입을 일렬로(1d) 정렬하기 위해 벡터로 옮겨담기
1. bt 배열의 N-1개 자리에 자리(x)별로 연산자 저장
2. 연산자 자리가 꽉차면(x==N-1), 앞에서부터 계산수행
3. 계산 수행한 결괏값을 가지고 최대 및 최솟값 갱신
*/

void calc(int x) {
	if (x == N - 1) {
		long long result = A[0];
		for (int i = 0; i < N - 1; i++) {
			int type = bt[i];
			if (bt[i] == 0) {
				result += A[i + 1];
			}
			else if (bt[i] == 1) {
				result -= A[i + 1];
			}
			else if (bt[i] == 2) {
				result *= A[i + 1];
			}
			else if (bt[i] == 3) {
				result /= A[i + 1];
			}
		}
		if (result < min_r) {	// 최솟값 갱신
			min_r = result;
		}
		if (result > max_r) {	// 최댓값 갱신
			max_r = result;
		}
	}
	else {	// N-1 = oper2.size()
		for (int i = 0; i < N - 1; i++) {
			if (!visited[i]) {		// 연산자 중복 허용 X
				visited[i] = true;
				bt[x] = oper2[i];
				calc(x + 1);
				visited[i] = false;	// 백트래킹
			}
			
		}
	}

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> N;
	long long tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		A.push_back(tmp);
	}
	for (int i = 0; i < 4; i++) {
		cin >> oper[i];
	}
	for (int i = 0; i < 4; i++) {
		while (oper[i] != 0) {
			oper2.push_back(i);
			oper[i]--;
		}
	}

	calc(0);
	cout << max_r << "\n" << min_r;

	return 0;
}