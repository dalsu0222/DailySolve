function solution(enroll, referral, seller, amount) {
  const parent = {}; // 키 : 이름 -  값: 현재 키의 부모인 사람 이름
  for (let i = 0; i < enroll.length; i++) {
    parent[enroll[i]] = referral[i];
  }
  const result = {}; // 키 : 이름 - 값: 벌어들인 누적 금액
  for (const name of enroll) {
    result[name] = 0;
  }
  for (let i = 0; i < seller.length; i++) {
    let total = amount[i] * 100;
    let currentName = seller[i];
    while (total > 0 && currentName !== "-") {
      // 부모를 거슬러 올라가며 10%씩 금액 분배
      result[currentName] += Math.ceil(total * 0.9);
      currentName = parent[currentName];
      total = Math.floor(total * 0.1);
    }
  }
  return enroll.map((name) => result[name]);
}