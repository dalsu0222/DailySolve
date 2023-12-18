#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
char arr[5][16];	// 전역변수로 선언하지 않을 시 값 비교 과정에서 원치않는 값 출력되는 오류 발생

int main(void)

{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 5; i++) {
		cin >> arr[i];	// 입력받은 문자열 끝에 "\0"(null) 포함된 채 저장
	}
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 5; j++) {
			if (arr[j][i] != '\0')	// 문자열이 끝나거나 초과(=null)하지 않은 경우에만 출력
				cout << arr[j][i];
		}
	}

    return 0;
}
