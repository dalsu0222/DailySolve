#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
string majorName, input;
double avg, sumGrade;
double score[20], grade[20];

int main(void)
{
	for (int i = 0; i < 20; ++i)
	{
		cin >> majorName >> grade[i] >> input;

		// 학점 저장
		if (input == "A+") score[i] = 4.5;
		else if (input == "A0") score[i] = 4.0;
		else if (input == "B+") score[i] = 3.5;
		else if (input == "B0") score[i] = 3.0;
		else if (input == "C+") score[i] = 2.5;
		else if (input == "C0") score[i] = 2.0;
		else if (input == "D+") score[i] = 1.5;
		else if (input == "D0") score[i] = 1.0;
		else if (input == "F") score[i] = 0.0;
		else if (input == "P") { score[i] = 0.0; grade[i] = 0; }	// pass 인 경우 학점에 포함 X
		
		// 학점 계산
		avg += (score[i] * grade[i]);
		sumGrade += grade[i];
	}

	avg = avg / sumGrade;
	cout << avg;

	return 0;
}