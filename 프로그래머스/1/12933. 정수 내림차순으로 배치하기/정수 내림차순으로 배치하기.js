function solution(n) {
    const arr = String(n);  // 유사 배열로 만들기
    const newarr = arr.split("").sort().reverse().join(""); // 문자열에서 배열로 전환 -> 내림차순 정렬 -> 다시 문자열로 전환
   return parseInt(newarr); // 정수로 형변환
    
}