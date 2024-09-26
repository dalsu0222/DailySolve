function calcCombine(arr, k) {
  if (k == 1) {
    return arr.map((x) => [x]);
  }
  const comb = [];
  arr.forEach((fixed, idx, arr) => {
    const rest = arr.slice(idx + 1); // 현재 선택된 인덱스 이후 요소들로 조합 구성
    const array = calcCombine(rest, k - 1);
    const combine = array.map((x) => [fixed, ...x]);
    comb.push(...combine);
  });
  return comb;
}

function solution(orders, course) {
  var answer = [];

  for (const k of course) {
    const combs = [];
    const counter = {};
    // 각 코스 개수에 맞는 조합을 모두 구함
    for (const order of orders) {
      const arr = order.split("").sort(); // 혹시모르니 정렬
      const comb = calcCombine(arr, k);
      //combs.push(...comb);
      for (const c of comb) {
        const key = c.join(""); // 배열을 문자열로 변환
        counter[key] = (counter[key] || 0) + 1;
      }
    }
    // 구한 조합중 가장 많이 나온 조합 찾기
    const maxValue = Math.max(...Object.values(counter));
    if (maxValue > 1) {
      for (const [key, value] of Object.entries(counter)) {
        // 찾은 조합에 대해 최댓값을 정답에 추가
        if (value === maxValue) answer.push(key);
      }
    }
  }
  return answer.sort();
}