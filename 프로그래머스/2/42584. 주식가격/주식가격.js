function solution(prices) {
    let n = prices.length;
    var answer = new Array(n).fill(0);
    // 스택을 사용해 이전 가겨고가 현재 가격을 비교
    let stack = [0];
    for(let i=1 ; i<n ; i++){
        while(stack.length > 0 && prices[i] < prices[stack[stack.length - 1]]){
            // 가격이 떨어졌으므로 이전 가격의 기간을 계산
            let idx = stack.pop();
            answer[idx] = i - idx;
        }
        stack.push(i);
    }
    // 스택에 남아있는 가격들 : 가격이 떨어지지 않은 경우
    while(stack.length > 0){
        let idx = stack.pop();
        answer[idx] = n - 1 - idx;
    }
    return answer;
}