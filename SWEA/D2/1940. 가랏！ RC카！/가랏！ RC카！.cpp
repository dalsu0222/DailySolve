#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	
    int N, c, a;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
        int meter = 0;
        int v = 0;
        for(int i=0 ; i<N ; i++){
        	cin >> c;
            if(c==0){	// 유지
            	meter += v;
            }
            else{
            	cin >> a;
                if(c==1){	// 가속
                    v += a;
                    meter += v;
                }
                else if(c==2){	// 감속
                    v = (v-a>=0 ? v-a : 0);	// 제약사항 3.
                	meter += v;
                }
            }
        }
        cout << "#" << test_case << " " << meter << "\n";
	}
    
	return 0;
}