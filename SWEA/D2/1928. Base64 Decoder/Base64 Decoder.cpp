#include<iostream>
#include <string>
#include <cstring>

using namespace std;

int arr[128];

void init(){
    for(int i=0 ; i<26; i++){
    	arr['A'+i ] = i;
    }
    for(int i=0 ; i<26; i++){
    	arr['a'+i ] = 26 + i;
    }
    for(int i=0 ; i<11; i++){
    	arr['0'+i ] = 52 + i;
    }
    arr['+'] = 62;
    arr['/'] = 63;
}

void decode(char* enc_s, char* dec_s){
	int bits, pos = 0, pos2 =0;
    while(enc_s[pos]){
        // 원래대로 6bits씩 풀어서
    	bits = arr[enc_s[pos++]] << 18;
        bits += arr[enc_s[pos++]] << 12;
        bits += arr[enc_s[pos++]] << 6;
        bits += arr[enc_s[pos++]];
        
        // 8bits씩 복호화
        dec_s[pos2++] = bits >> 16 & 0xFF;
        dec_s[pos2++] = bits >> 8 & 0xFF;
        dec_s[pos2++] = bits  & 0xFF;
    }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;
    
    init();
    
    char encoded[100001];
    char decoded[100001];

	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin >> encoded;
        decode(encoded,decoded);
		
        // cout 대신 printf 로 문자열 전체 내용 출력
		printf("#%d %s\n",test_case,decoded);
	}
	return 0;
}