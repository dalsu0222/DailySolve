#include<iostream>

using namespace std;
int arr[501][501];

int main() {

	int t;
	cin >> t;

	int num = 1; 
	for (int i = 1; i <= 500; i++) {
		arr[i][1] = num;
		for (int j = 2; j <= 500; j++) {	// 각 열(i)마다 오른쪽으로 진행하며 수 구해주기
			arr[i][j] = arr[i][j - 1] + i + j - 1;
		}
		num += i;
	}

	int p, q;
	int px, py, qx, qy;
	for (int tc = 1; tc <= t; tc++) {
		cin >> p >> q;
		for (int i = 1; i <= 500; i++) {
			for (int j = 1; j <= 500; j++) {
				if (arr[i][j] == p) {
					px = i;
					py = j;
				}
				if (arr[i][j] == q) {
					qx = i;
					qy = j;
				}
			}
		}
		cout << "#" << tc << " " << arr[px + qx][py + qy] << "\n";
	}

	return 0;
}