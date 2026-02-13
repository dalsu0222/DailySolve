#include <iostream>
using namespace std;

int prob[8][8]; // prob[i][j]: i가 j를 이길 확률
double alive[4][8]; // alive[r][i] : r라운드 통과 후 i가 살아남을 확률

// dp로 접근하여 각 라운드별 우승 확률 누적

double calcWin(int i, int j){
  if(i<j) return prob[i][j]/100.0;
  return 1.0 - prob[j][i]/100.0;
}

int main() 
{
    for(int i=0 ; i<7 ; i++){
      for(int j=i+1; j<=7 ; j++){
        cin >> prob[i][j];
      }
    }
    
    // 시작
    for(int i=0 ; i<8 ; i++){
      alive[0][i] = 1.0;
    }
    
    int sizeArr[4] = {0, 2, 4, 8};
    
    for(int r=1; r<=3; r++){ // 라운드
      int size = sizeArr[r];
      int half = size / 2;
      
      for(int i=0 ; i<=7 ; i++){
        int base = (i/size) * size; // 블럭에서 시작지점
        
        int left, right;  // 상대로 만날 수 있는 구간 [l,r]
        if(i < base + half){ // 본인이 블록의 왼쪽에 위치
          left = base + half;
          right = base + size - 1;
        }else{ // 본인이 블록의 오른쪽에 위치
          left = base;
          right = base + half - 1;
        }
        
        double sum = 0.0;
        for(int j=left ; j<=right ; j++){  // 적j가 직전라운드에서 살고 동시에 i가 적 j를 이김
          sum += alive[r-1][j] * calcWin(i,j);
        }
        // i가 라운드 r까지 살 확률 * 대결가능성 상대 이기는 경우
        alive[r][i] = alive[r-1][i] * sum;
      }
    }

    cout.precision(9);
    for(int i=0 ; i<=7 ; i++){
        cout << alive[3][i] << " ";
    }

    
    return 0;
}

//7 6 5 4 3 2 1 -> 마지막은 6번참가자가 7번참가자 이길