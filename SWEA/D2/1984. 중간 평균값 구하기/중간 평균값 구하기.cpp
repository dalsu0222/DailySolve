#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
    int tc;
    int T;

    cin >> T;

    for (tc = 1; tc <= T; ++tc)
    {
        vector<int>score(10);
        for (int i = 0; i < 10; i++) {
            cin >> score[i];
        }

        sort(score.begin(), score.end());		// 점수 오름차순 정렬

        double avg = 0;
        for (int i = 1; i < 9; i++) {	// 최댓값, 최솟값은 계산에서 제외
            avg += score[i];
        }

        cout << "#" << tc << " " << int(avg / 8 + 0.5) << "\n";     // 소숫점 첫째자리에서 반올림하여 출력

    }
    return 0;
}