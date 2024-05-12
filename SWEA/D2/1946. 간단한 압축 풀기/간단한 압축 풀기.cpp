#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int tc;
	int T, N;
	
	cin>>T;
	
	for(tc = 1; tc <= T; ++tc)
	{
		cin >> N;
        char c;	int k;
        char doc[201];		 // 출력문자열을 한 번에 배열로 저장
         int index = 0;
        for(int i = 0; i < N ; i++){
        	cin >> c >> k;
           
            while(k--){	// 길이가 k가 되도록 저장
            	doc[index] = c;
                index++;
            }
        }
        
        cout << "#" << tc << "\n";
        for(int i = 0 ; i < index ; i++){
            if( i % 10 == 0 && i != 0){		// 한 줄에 10개의 문자가 출력되면 줄바꿈 일어남
            	cout << "\n";
            }
        	cout<< doc[i];
            
        }
		cout << "\n";
	}
	return 0;
}