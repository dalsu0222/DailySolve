#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T, N;
	
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
		int arr[N][N];
        for(int i=0 ; i<N ; i++)
            for(int j=0 ; j<N; j++)
                cin >> arr[i][j];
        
        // 회전한 배열을 각각 저장해서, 마지막에 반복문에서 다같이 출력
       	int res_90[7][7];
		int res_180[7][7];
		int res_270[7][7];
        // 배열 90도로 회전
         for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                res_90[j][(N - 1) - i] = arr[i][j];
            }
        }
       	//90도 돌린 배열 90도 회전(180도 회전)
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                res_180[j][(N - 1) - i] = res_90[i][j];
            }
        }
        //180도 돌린 배열 90도 회전(270도 회전)
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                res_270[j][(N - 1) - i] = res_180[i][j];
            }
        }
        
        cout << "#" << test_case << "\n";
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << res_90[i][j];
            }
            cout << " ";
            for (int j = 0; j < N; j++) {
                cout << res_180[i][j];
            }
            cout << " ";
            for (int j = 0; j < N; j++) {
                cout << res_270[i][j];
            }
            cout << "\n";
        }    
	}
	return 0; 
}