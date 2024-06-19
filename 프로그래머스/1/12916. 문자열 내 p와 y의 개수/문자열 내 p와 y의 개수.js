function solution(s){
    var answer = true;
    var cnt_p = 0;
    var cnt_y = 0;
    for(var i=0 ; i<s.length ; i++){
        if(s[i] === 'p' || s[i] === 'P')
            cnt_p++;
        if(s[i] === 'y' || s[i] === 'Y')
            cnt_y++;
    }

    return cnt_p === cnt_y;
}