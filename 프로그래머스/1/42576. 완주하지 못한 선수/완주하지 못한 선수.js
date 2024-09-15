function solution(participant, completion) {
  const hashobj = {};
  // O(n) 복잡도로 해결 -> 해시테이블 이용, 키:이름, 값:동명이인 수
  for (const p of participant) {
    if (hashobj[p]) {
      hashobj[p]++;
    } else {
      hashobj[p] = 1;
    }
  }
  for (const c of completion) {
    hashobj[c]--;
  }
  for (const name of participant) {
    if (hashobj[name] > 0) {
      return name;
    }
  }
}