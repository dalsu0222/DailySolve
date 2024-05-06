#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int tc;
	int T,n,m;

	cin>>T;

	for(tc = 1; tc <= T; ++tc)
	{
		cin >> n >> m;
        int map[n][n];
		for(int i=0 ; i<n ; i++){
        	for(int j=0 ; j<n ; j++){
            	cin >> map[i][j];
            }
        }
        
        int result = 0;
        int max_r = 0;
		for(int i=0 ; i<=n-m ; i++){            
        	for(int j=0 ; j<=n-m ; j++){
                result = 0;		// 초기화
                int cnt_y = 0;	int cnt_x = 0;
        		int nx = j +cnt_x;	// nx, ny : 더하기를 수행할 다음 위치
                int ny= i + cnt_y;
                // 파리채 크기만큼 오른쪽, 아래쪽으로 이동하며 더하기 수행
                while(cnt_y < m){	// 아래쪽으로 세로이동
                    ny= i + cnt_y;
                    cnt_x = 0;
                  	while(cnt_x < m){	// 오른쪽으로 가로 이동
                        nx = j +cnt_x;
                        result+=map[ny][nx];
                        cnt_x++;
               	 	}
                    cnt_y++;
                }

                // 최댓값 확인
                if(max_r < result){
                	max_r = result;
                }
       		}
        }
		cout << "#" << tc << " " << max_r << "\n";
	}
	return 0;
}