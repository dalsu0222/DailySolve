function solution(n) {
    const answer = [];
    
    do{
        answer.push(n%10);
        n = Math.trunc(n/10);   // -를 제외하고 소숫점 버림, 정수 반환. -를 제외하므로 음수 양수 동일하게 작동
    }while(n>0)
    
    return answer;
}