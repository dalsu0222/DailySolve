#include<iostream>
#include <string>

using namespace std;
int test_case;
string s;

int main(int argc, char** argv)
{
	    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> test_case;
    for (int tc = 1; tc <= test_case; tc++) {
        cin >> s;
        int cnt = 0;
        char now = s[0];
        if (now == '1') {
            cnt++;
        }
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == now) {
                continue;
            }
            else {
                cnt++;
                now = s[i];
            }
        }
        cout << "#" << tc << " " << cnt << "\n";
    }
   
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}