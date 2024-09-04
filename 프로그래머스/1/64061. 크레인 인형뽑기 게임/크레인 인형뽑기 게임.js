function solution(board, moves) {
    // 각 열에 대한 스택을 관리
   const lanes = [...new Array(board[0].length)].map(()=>[]);
    
    for(let i=board.length -1 ; i>=0 ; i--){
        for(let j=0 ; j<board[0].length ; j++){
            if(board[i][j]){
                lanes[j].push(board[i][j]);     
            }
        }
    }
    
    let answer = 0;
    let basket = [];
    for(const m of moves){
        if(lanes[m-1].length > 0){  // 해당 열에 인형이 있는 경우
            let doll = lanes[m-1].pop();
            if(basket.length > 0 && doll === basket[basket.length - 1]){    
                // 바구니에 인형이 있고, 가장 위에 있는 인형과 같은 경우 -> bomb 
                basket.pop();
                answer += 2;
            }else{  // 인형은 있지만 가장 위에 있는 인형과 다른 종류인 경우
                basket.push(doll);
            }
        }
    }
    return answer;
    
}