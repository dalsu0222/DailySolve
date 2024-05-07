#include<iostream>
#include<cstring>

using namespace std;

int main(int argc, char** argv)
{
	int tc;
	int T;
	
	cin>>T;
	
    int result;
	for(tc = 1; tc <= T; ++tc)
	{
		int map[10][10];
        result = 1;
        for(int i=1 ; i<=9 ; i++){
        	for(int j=1 ; j<=9 ; j++){
            	cin >> map[i][j];
            }
        }
        
        // 가로 방향 검증
        for(int i=1 ; i<=9 ; i++){
        	int x_map[10];
            memset(x_map, 0, sizeof(x_map));
            for(int j=1 ; j<=9 ; j++){
                int num = map[i][j];
            	if(!x_map[num])
                    x_map[num]++;
                else{	// 2개 이상 등장한 것이 있다면, 스도쿠 불가
                	result = 0;
                    break;
                }
            }
            if(!result){
                break;
            }
        }
		
        // 세로 방향 검증
         for(int i=1 ; i<=9 ; i++){
        	int y_map[10];
            memset(y_map, 0, sizeof(y_map));
            for(int j=1 ; j<=9 ; j++){
                int num = map[j][i];
            	if(!y_map[num])
                    y_map[num]++;
                else{	// 2개 이상 등장한 것이 있다면, 스도쿠 불가
                	result = 0;
                    break;
                }
            }
            if(!result){
                break;
            }
        }
        
        // 3x3 크기 검증
         for(int i=1 ; i<=9 ; i+=3){
        	for(int j=1 ; j<=9 ; j+=3){
                // 각 3x3크기의 1행1열 원소 기준으로 검증 진행
            	int map3x3[10];
                memset(map3x3, 0, sizeof(map3x3));
                for(int a=0 ; a<3 ; a++){
                	for(int b=0 ; b<3 ; b++){
                    	int num = map[i+a][j+b];
                        if(!map3x3[num])
                            map3x3[num]++;
                        else{
                        	result = 0;
                            break;
                        }
                    }
                    if(!result){
                        break;
                    }
                }
                if(!result){
                        break;
                    }
            }
        }
        
        cout << "#" << tc << " " << result << "\n";
	}
	return 0;
}