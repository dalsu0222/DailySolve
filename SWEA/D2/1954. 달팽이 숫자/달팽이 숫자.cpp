#include<iostream>
#include<cstring>

using namespace std;

int dx[4] = { 1 , 0 , -1 ,0 };	// 동, 남, 서, 북 방향진행
int dy[4] = { 0 , 1, 0 , -1 };

int main(int argc, char** argv)
{
	int tc;
	int T,n;
	
	cin>>T;
	for(tc = 1; tc <= T; ++tc)
	{
		cin >> n;
       	int s[n][n];
        
        // 초기화
		memset(s,0,sizeof(s));
        s[0][0] = 1;	
        int cnt = 2;
        int x = 0, y = 0, dir = 0;
        
		while(n*n >= cnt){
            // 새로운 위치
        	int nx = x + dx[dir];
            int ny = y + dy[dir];
            
            if( nx<0 || ny <0 || nx >=n || ny >= n || s[ny][nx] > 0 ){		// 배열 밖을 벗어나거나, 이미 수가 존재하는 경우
            	dir++;	// 방향 전환
                if(dir == 4)	// 북쪽 -> 동쪽 진행
                    dir = 0;
                continue;
            }
            s[ny][nx] = cnt;
            cnt++;
            x = nx;
           	y = ny;
        }
        
        // 출력
        cout << "#" << tc << "\n";
        for(int i=0 ; i<n ; i++){
        	for(int j=0 ; j<n ; j++){
            	cout << s[i][j] << " ";
            }
            cout << "\n";
        }
	}
	return 0;
}