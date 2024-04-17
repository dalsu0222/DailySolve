#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N, K;
int cnt;
int num[1001];	// 1. 2부터 N까지 모든 정수를 적기( 0: 지우기 전, 1: 지운 후)

int main(void)
{
	cin >> N >> K;
	while (1) {
		int P = 0;	// 소수 담을 변수
		for (int i = 2; i <= N; i++) {
			if (num[i] == 0) {		// 2. 아직 지우지 않은 수 중 가장 작은 수 찾기
				P = i;
				break;
			}	
		}
		for (int i = P; i <= N; i += P) {	// 3. P를 지우고, 아직 지우지 않은 P의 배수를 크기 순서대로 지우기
			if (num[i] == 0) {	
				num[i] = 1;
				cnt++;
			}
			if (cnt == K) {	// K번째 지워진 수이면, 출력하고 프로그램 종료
				cout << i;
				return 0;
			}
		}
		// 4. 아직 모든 수를 지우지 않았다면, 다시 위의 단계 실행
	}

	return 0;
}