#include<iostream>
#include <string>

using namespace std;
int testcase, n;
int map[50][50];

int main(int argc, char** argv)
{
	cin >> testcase;
    for (int tc = 1; tc <= testcase; tc++) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            string tmp;
            cin >> tmp;
            for (int j = 0; j < n; j++) {
                map[i][j] = tmp[j] - '0';
            }
        }

        
        // 농장의 수익 계산
        int total = 0;
        for (int j = 0; j <= (n - 1) / 2; j++) {
            for (int k = j; k < n - j; k++) {
                total += map[n / 2 - j][k];
                if (j != 0)
                    total += map[n / 2 + j][k];
            }
        }

        cout << "#" << tc << " " << total << "\n";
    }
    
    return 0;
}