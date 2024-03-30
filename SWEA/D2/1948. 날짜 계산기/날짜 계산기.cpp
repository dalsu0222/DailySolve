#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;
	int m1,m2,d1,d2;
    int total = 0;
    int day[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};	 // i번째 : i번째 달의 날짜수
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin >> m1 >> d1 >> m2 >> d2;
        for(int i=m1 ; i<=m2 ; i++){
        	if(i==m1){
            	total += day[m1] - d1;
            }else if (i==m2){
                total += d2;
            }else{
            	total += day[i];
            }
        }
        cout << "#" << test_case << " " << total + 1<< "\n";  	// 시작날짜도 포함시키기 위해 +1 적용
        total = 0;		// total 초기화
	}
	return 0;
}