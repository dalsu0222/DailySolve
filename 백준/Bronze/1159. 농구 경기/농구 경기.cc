#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>		// map을 사용하면 M번만 확인하면 되므로 n^2보다 실행시간이 빨라진다.

using namespace std;

int N;
int alphabet[26];	// 알파벳순으로 a~z

int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;
		alphabet[input[0] - 'a']++;
	}
	bool predaja = true;
	for (int i = 0; i < 26; i++) {
		if (alphabet[i] >= 5) {
			printf("%c", 'a' + i);		// 다시 인덱스 i만큼 더하여 char로 출력
			predaja = false;
		}
	}
	if (predaja) 
		cout << "PREDAJA";
}