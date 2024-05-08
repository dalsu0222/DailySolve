#include<iostream>
#include<cstring>
using namespace std;

int main(int argc, char** argv)
{
	int tc;
	int T, n;

	cin>>T;

	for(tc = 1; tc <= T; ++tc)
	{
		cin >> n;
        int tri[n][n];
        memset(tri, 0, sizeof(tri));	// 모든 원소 0으로 초기화
        tri[0][0] = 1;		// 맨 꼭대기 값 초기화
        for(int i= 1 ; i<n ; i++){
        	for(int j=0 ; j<=i ; j++){
            	if(0 <= j -1){	// 왼쪽 위 값 더해주기, 인덱스에러 방지
                	tri[i][j] += tri[i-1][j-1];
                }
               	tri[i][j] += tri[i-1][j];	// 오른쪽 위 값 더해주기
            }
        }
        
        // 출력
		cout << "#" << tc << "\n";
        for(int i=0 ; i <n ; i++){
        	for(int j=0 ; j<= i ; j++){
            	cout << tri[i][j] << " ";
            }
            cout << "\n";
        }
	}
	return 0;
}