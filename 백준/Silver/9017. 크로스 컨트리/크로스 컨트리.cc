#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
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
	/* 
		team[1001]		//  각 팀의 등장횟수 저장 (자격조건 판별 위함)
		isTeam[1001]	// 각 팀의 자격조건 저장, isTeam[i] == true일 시 자격 O
		vector<int> order(n);	// n번의 입력 그대로 저장하는 배열
		vector<int> v[201];		// 각 팀에 해당하는 모든 점수 저장
	*/
	for (int i = 0; i < tc; i++) {
		cin >> n;

		// 초기화
		int team[1001];		
		memset(team, 0, sizeof(team));
		bool isTeam[1001];	
		memset(isTeam, false, sizeof(isTeam));

		int tmp;	int max_t = 0;	// max_t : 팀번호가 1~k 까지 등장할 때, k를 저장하는 변수
		vector<int> order(n);	// n번의 입력 그대로 저장하는 배열
		for (int j = 0; j < n; j++) {
			cin >> tmp;
			team[tmp]++;	//  팀 등장횟수 카운트
			order[j] = tmp;		// 들어온 순서대로 팀 번호 저장
			if (max_t < tmp)
				max_t = tmp;
		}

		for (int j = 1; j <= max_t; j++) {	// 팀 자격 확인
			if (team[j] == 6)
				isTeam[j] = true;
		}

		int score = 1;
		vector<int> v[201];		// 각 팀에 해당하는 모든 점수 저장 
		// v[i]에는 각 팀의 모든 점수가 오름차순으로 들어감, sort() 따로 필요 X
		for (int j = 0; j < n; j++) {
			int num = order[j];
			if (!isTeam[num]) {	// 자격 조건X -> 다음순서로
				continue;
			}
			v[num].push_back(score);
			score++;
		}
		
		int winner = 1;
		int min_s = 99999999;
		for (int j = 1; j <= max_t; j++) {
			int sum = 0;
			if (!isTeam[j]) {	// 자격 조건X -> 다음순서로
				continue;
			}
			for (int r = 0; r < 4; r++) {	// 상위 4개의 점수만 계산
				sum += v[j][r];
			}
			if (min_s > sum) {	// 팀의 점수 중 더 작은 점수를 저장
				min_s = sum;
				winner = j;
			}
			else if (min_s == sum) {	// 동점인 경우, 다섯 번째 주자 점수로 비교
				if (v[winner][4] > v[j][4]) {
					min_s = sum;
					winner = j;
				}
			}
		}

		cout << winner << "\n";	// 팀 점수 중 가장 작은 점수를 가진 팀이 우승 팀.
	}

	return 0;
}