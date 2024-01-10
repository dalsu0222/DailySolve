#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;
int M;
int num;
string str;
int arr[21] = { 0};

int main(void)

{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M;
	for (int i = 0; i <	M; i++) {
		cin >> str;
        if (str == "add") {
            cin >> num;
            if (arr[num] == 0) {   // num에 해당하는 수가 아직 집합에 없다면
                arr[num] = 1;
            }
        }
        else if (str == "remove") {
            cin >> num;
            if (arr[num] == 1) {  // num에 해당하는 수가 있으면
                arr[num] = 0;   
            }
        }
        else if (str == "check") {
            cin >> num;
            if (arr[num] == 0) {   // num에 해당하는 수가 없으면
                cout << "0\n";
            }
            else {
                cout << "1\n";      // 있으면
            }
        }
        else if (str == "toggle") {
            cin >> num;
            if (arr[num] == 1) {  // 있으면
                arr[num] = 0;
            }
            else {
                arr[num] = 1;
            }
        }
        else if (str == "all") {
            // S = {1,2,...,20} 으로 변경
            for (int j = 1; j <= 20; j++){ 
                arr[j] = 1; 
            }
        }
        else if (str == "empty") {
            // S를 공집합으로 바꾸기
            memset(arr, 0, sizeof(arr));
        }
	}

	return 0;
}
