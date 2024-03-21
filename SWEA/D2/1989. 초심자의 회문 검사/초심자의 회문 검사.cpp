#include<iostream>
#include<string>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;
	
    string s;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin >> s;
        int cnt = 0;
        int isPalindrome = 0;
        for(int i=0 ; i<s.length()/2 ; i++){
        	if(s[i] == s[s.length()-1 -i]){
            	cnt++;
            }
        }
;
        if(cnt == s.length()/2){
        	isPalindrome = 1;
        }
		cout << "#" << test_case << " " << isPalindrome << "\n";
	}
    
	return 0;
}