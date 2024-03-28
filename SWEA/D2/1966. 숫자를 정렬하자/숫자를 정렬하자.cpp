#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;
	int N;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
        vector<int> v(N);
        for(int i=0 ; i<N ; i++){
        	cin >> v[i];
        }    
        sort(v.begin(),v.end());		// 오름차순 정렬
        cout << "#" << test_case << " ";
        for(int i=0 ; i<N ; i++){
        	cout << v[i] << " ";
        }
        cout << "\n";
	}
    
	return 0;
}