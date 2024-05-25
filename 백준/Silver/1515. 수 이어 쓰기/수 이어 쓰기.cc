#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;
	int N = 0;
	int index = 0;
	
	// N=1 부터 만족하는 최소 N까지 진행
	while (index < s.size()) {	// index가 입력받은 크기를 초과하면, 최소 N을 구한것이 완료된 것임
		N++;
		string snum = to_string(N);	// int -> string 형변환, N의 앞자리부터 등장하는 수가 있는지 체크
		for (int i = 0; i < snum.size(); i++) {
			if (snum[i] == s[index]) {	// 입력받은 숫자와 일치하는 숫자가 있으면, 다음 입력된 수 체크
				index++;
			}
			if (index >= s.size()) {
				break;
			}
		}
		
	}
	cout << N;
	
	return 0;
}