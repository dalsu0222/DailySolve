#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int L, U, X;
		cin >> L >> U >> X;
		int total = 0;	// L <= X <= U 라고 가정
		if (L > X) {	// Lower보다 작다면, 부족한 만큼 추가  운동
			total = L - X;
		}
		else if (U < X) {	// Upper보다 크다면, 더많은 운동을 하고있는 것임
			total = -1;
		}

		cout << "#" << tc << " " << total << "\n";
	}

	return 0;
}