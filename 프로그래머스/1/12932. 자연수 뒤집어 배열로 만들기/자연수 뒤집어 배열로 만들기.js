function solution(n) {
    var answer = [];
    const s = String(n);
    for(var i=s.length-1 ; i>=0 ; i--){
        var num = parseInt(s[i]);
        answer.push(num);
    }
    return answer;
}