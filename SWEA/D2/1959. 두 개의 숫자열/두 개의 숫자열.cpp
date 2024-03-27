#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;

    int N,M;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        /*
        	1. N,M의 차이만큼 숫자열을 이동한다.
            2. N,M중 작은 수만큼 숫자열끼리 곱셈을 실행한다.
            3. 최댓값을 갱신한다.
        */
		cin >> N >> M;
        int A[N];	int B[M];
        for(int i=0 ; i<N ; i++){
        	cin >> A[i];
        }
         for(int j=0 ; j<M ; j++){
        	cin >> B[j];
        }
        int length = (N>M)? M : N;	// 더 적은 배열의 크기만큼 곱셈 실행(내부 반복문)
        int tmp =  (N>M)? N-M+1 : M-N+1;	// 두 배열 차이의 크기를 최대 이동 길이로 설정(외부 반복문)
        int max_t = 0;
        for(int i=0 ; i<tmp ; i++){
            int total = 0;
        	for(int j=0 ; j<length ; j++){	// 내부반복문, 크기가 더 큰 숫자열을 i만큼 이동하며 연산 실행
                (N>M)? total += A[i+j]*B[j] : total += A[j]*B[i+j];
            }
            if(max_t < total)	// 최댓값 갱신
                max_t = total;
        }
		cout << "#" << test_case << " " << max_t<<"\n";

	}
	return 0;
}