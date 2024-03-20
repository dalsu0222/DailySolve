#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	
    int P,Q,R,S,W;
    int total = 0;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin >> P >> Q >> R >> S >> W;
        int A_total = W*P;
        int B_total = Q;
        if(W>R){
        	B_total += (W-R)*S;
        }
        
        if(A_total>B_total)
            total = B_total;
        else
            total = A_total;
        
        cout << "#" << test_case << " " << total << "\n";
	}
    
	return 0;
}