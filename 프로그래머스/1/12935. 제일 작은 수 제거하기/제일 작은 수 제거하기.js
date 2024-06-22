function solution(arr) {
    const min_n = Math.min(...arr); // Math.min() : 배열에서 최솟값 반환
    return arr.length !== 1 ? arr.filter(n => n !== min_n) : [-1];  // filter이용하여 조건에 맞지않는값 제외하고 출력
}