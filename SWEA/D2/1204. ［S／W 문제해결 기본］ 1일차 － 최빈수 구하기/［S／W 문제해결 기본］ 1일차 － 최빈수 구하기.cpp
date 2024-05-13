#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int tc;
	int T, n;
	
	cin>>T;

	for(tc = 1; tc <= T; ++tc)
	{
		cin >> n;
        int score[101] = { 0, };
        for(int i = 0 ; i < 1000 ; i++){
        	int tmp;
            cin >> tmp;
            score[tmp]++;
        }
        int max_c = 0;		// 점수 최대등장횟수 저장
        int max_s = 0;		// 최빈수 저장
		for(int i = 0 ; i <= 100 ; i++){
        	if(score[i] && max_c <= score[i]){		// 존재하는 점수이고, 더 많이 등장한 점수라면
            	max_c = score[i];
                max_s = i;		// 최빈수 갱신
            }
        }
		
        // 출력
        cout << "#" << n << " " << max_s << "\n";
	}
	return 0;
}