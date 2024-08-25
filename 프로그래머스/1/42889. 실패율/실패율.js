function solution(N, stages) {
  // 1. 스테이지별 도전자 수를 구함
  let challengers = new Array(N + 2).fill(0);
  for (const stage of stages) {
    challengers[stage] += 1;
  }
  //2. 스테이지별 실패한 사용자 수 계산
  const fails = {}; // key: stage, value: 실패한 사용자 수
  let total = stages.length;
  for (let i = 1; i <= N; i++) {
    if (challengers[i] === 0) {
      fails[i] = 0;
      continue;
    }
    fails[i] = challengers[i] / total;
    total -= challengers[i]; // 다음 스테이지 실패율을 구하기 위해 현재 스테이지 인원 빼기
  }
  //3. 실패율을 기준으로 내림차순 정렬
  const answer = Object.entries(fails).sort((a, b) => b[1] - a[1]);

  //4. 스테이지 번호만 추출하여 반환
  return answer.map((el) => Number(el[0]));
}