#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int tc;
	int T;
	
	cin>>T;

	for(tc = 1; tc <= T; ++tc)
	{
		int h1,h2,m1,m2;
        cin >> h1 >> m1 >> h2 >> m2;
        int h = h1 + h2;
        int m = m1 + m2;

        if( m >= 60){	// 60분을 넘어가면, 60분 -> 1시간 변환
        	h++;
            m-=60;
        }
        if(h > 12)	// 12시를 넘어가면, 다시 0시부터 시작
            h -= 12;
        
        cout << "#" << tc << " " << h << " " << m << "\n";
	
	}
	return 0;
}