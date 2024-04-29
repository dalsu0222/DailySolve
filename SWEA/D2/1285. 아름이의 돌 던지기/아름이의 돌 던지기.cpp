#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int tc;
	int T;
	cin>>T;
	
    int N;
	for(tc = 1; tc <= T; ++tc)
	{
		cin >> N;
        int r[N];
        for(int i=0 ; i<N ; i++){
        	cin >> r[i];
        }
        
        
        int min_d = 999999;	// 0인 지점과의 최소거리차이 저장
        int cnt = 0;	// 최소거리차이가 몇번등장했는지 개수 저장
        for(int i=0 ; i<N ; i++){
        	if(min_d > abs(r[i])){	// 최솟값보다 더 작은수가 등장한경우, 최솟값과 개수 갱신
            	min_d = abs(r[i]);
                cnt = 1;
            }else if(min_d == abs(r[i])){	// 최솟값과 같은 값인경우, 개수만 1 증가하여 갱신
            	cnt++;
            }
        }
        
        cout << "#" << tc << " " << min_d << " " << cnt << "\n";
		
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}