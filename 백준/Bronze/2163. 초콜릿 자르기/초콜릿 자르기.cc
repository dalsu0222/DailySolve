#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int N, M;
int cnt;

int main(void)

{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	// N조각으로 자른 후 N조각을 각각 M조각으로 자른다
	// (N-1) + N*(M-1) = N*M-1
	cout << N * M - 1;		
		
	return 0;
}
