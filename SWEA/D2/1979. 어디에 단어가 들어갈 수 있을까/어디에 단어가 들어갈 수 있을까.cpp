#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
    int N,K;
	
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case){
		cin >> N >> K;
        int map[N][N];
        for(int i=0 ; i<N ; i++){
			 for(int j=0 ; j<N ; j++){
				cin >> map[i][j];
             }
        }
        int result = 0;
        // 가로 길이 확인
        for(int i=0 ; i<N ; i++){
        	int cnt = 0;
            vector<int> arr;
            for(int j=0 ; j<N ; j++){
            	if(map[i][j] == 1){
                	cnt++;
                	if(j==N-1){		// 가로의 맨 끝인경우, cnt=K인지 별도확인
                    	arr.push_back(cnt);
                    	cnt = 0;
                    }
                }else{
                    if(j>=1 && map[i][j-1]==1){
                    	arr.push_back(cnt);
                    	cnt = 0;
                    }	
                }
            }
            for(int k=0 ; k<arr.size() ; k++){
            	if(arr[k] == K){		// 흰색타일 중 길이가 K인경우 카운트
                	result++;
                }  
            }
        }
        // 세로 길이 확인
        for(int i=0 ; i<N ; i++){
        	int cnt = 0;
            vector<int> arr;
            for(int j=0 ; j<N ; j++){
            	if(map[j][i] == 1){
                	cnt++;
                    if(j==N-1){			// 세로의 맨 끝인경우, cnt=K인지 별도확인
                    	arr.push_back(cnt);
                    	cnt = 0;
                    }
                }else{
                    if(j>=1 && map[j-1][i]==1){

                    	arr.push_back(cnt);
                    	cnt = 0;
                    }	
                }
            }
            for(int k=0 ; k<arr.size() ; k++){
            	if(arr[k] == K){		// 흰색타일 중 길이가 K인경우 카운트
                     result++;
                }
                   
            }
        }
        cout << "#" << test_case << " "  << result << "\n";
    }
    
	return 0;
}