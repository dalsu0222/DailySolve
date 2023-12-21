#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <stack>

using namespace std;
string X, Y;
int r_X, r_Y;

int main(void)

{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> X >> Y;
	
	reverse(X.begin(), X.end());	// 문자열의 순서 뒤집기
	reverse(Y.begin(), Y.end());

	r_X = stoi(X);	// 뒤집은 문자열을 정수로 변환
	r_Y = stoi(Y);
	string result = to_string(r_X + r_Y);
	reverse(result.begin(), result.end());
	
	cout << stoi(result) << endl;	// 문자열 0번째 인덱스부터 출력하는것보다 정수로 바꿔서 출력하기(간단)

    return 0;
}
