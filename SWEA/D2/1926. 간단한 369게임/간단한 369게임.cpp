#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int n;
	
	cin>>n;
	
	for(int i= 1; i <= n; ++i)
	{
		int tmp = i;
		int cnt = 0;		// 3 6 9 등장한 횟수
        while(tmp > 0){
        	if(tmp%10 == 3 || tmp%10 ==6 || tmp%10 == 9){
            	cnt++;
            }
            tmp/=10;
        }
        if(!cnt)
            cout<< i;
        else{
            while(cnt--){		// 등장한 횟수만큼 - 출력
            	cout << "-";
            }
        }
        cout << " ";
	}
	return 0;
}