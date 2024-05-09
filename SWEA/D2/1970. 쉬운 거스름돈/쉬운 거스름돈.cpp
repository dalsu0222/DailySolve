#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int tc;
	int T;
	
	cin>>T;
	
    int money;
	for(tc = 1; tc <= T; ++tc)
	{
		cin>> money;
        int charge[8] = {0, };		
        // 그리디 알고리즘으로 해결
        while(money >= 50000){
        	charge[0]++;
            money -= 50000;
        }
        while(money >= 10000){
        	charge[1]++;
            money -= 10000;
        }
        while(money >= 5000){
        	charge[2]++;
            money -= 5000;
        }
        while(money >= 1000){
        	charge[3]++;
            money -= 1000;
        }
        while(money >= 500){
        	charge[4]++;
            money -= 500;
        }
        while(money >= 100){
        	charge[5]++;
            money -= 100;
        }
        while(money >= 50){
        	charge[6]++;
            money -= 50;
        }
        while(money >= 10){
        	charge[7]++;
            money -= 10;
        }
		cout << "#" << tc << "\n";
        for(int i=0 ; i<8 ; i++){
        	cout << charge[i] << " ";
        }
		cout << "\n";
	}
	return 0;
}