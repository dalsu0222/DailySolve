#include<iostream>
#include<vector>

using namespace std;
string grade[10] = {"A+","A0","A-","B+","B0","B-","C+","C0","C-","D0" };

int main(int argc, char** argv)
{
   int tc;
   int T;
   
   cin>>T;
   
   int N , K;
   for(tc = 1; tc <= T; ++tc)
   {
      cin >> N >> K;
        vector<double> score;
        int a,b,c;
         for(int i = 0 ; i < N ; i++) {
           cin >> a >> b >> c;
           double total = a*0.35 + b*0.45 + c*0.2;
           score.push_back(total);
        }
        int cnt = 0;
		for (int i = 0; i < N; i++) {
			if (score[i] > score[K - 1]) 	// 구하고자 하는 학생의 점수보다 더 큰 점수만 세서, 학점 계산에 반영
                cnt++;
		}
		cout << "#" << tc << " " << grade[cnt / (N/10)] << "\n";	// 점수가 더 높은 학생들 수를 구간별 학생수만큼 나누어서 등수 계산
   }
   return 0;
}