#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);     // 시간초과방지

	cin >> n;
	for (int i = 1; i <= n * 2; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i % 2 == 0)
			{
				if (j % 2 == 0)
					cout << "*";
				else cout << " ";
			}
			else
			{
				if (j % 2 == 0)
					cout << " ";
				else cout << "*";
			}
		}
		cout << endl;
	}

	return 0;
}