function solution(arr) {
    if(arr.length == 1) // 리턴하려는 배열이 빈 배열인 경우
        return [-1];
    
    var min_n = 9999;   // 임의의 큰 값
    const newarr = [];
    for(var i=0 ; i<arr.length ; i++){
        if(min_n > arr[i]){ // 최솟값 찾기
            min_n = arr[i];
        }
    }
    for(var i=0 ; i<arr.length ; i++){
        if(arr[i] !== min_n){       // 찾은 최솟값 제외하고 배열 다시 만들기
            newarr.push(arr[i]);
        }
    }
    return newarr;
    
}