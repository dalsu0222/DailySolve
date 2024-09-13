function solution(n, words) {
  if (words[0].length < 2) {
    // 첫번째 단어가 탈락일 조건
    return [1, 0];
  }

  let turn = 1;
  let isExist = new Set(); // 중복단어 검사하기위한 단어 저장소
  isExist.add(words[0]);

  for (let i = 1; i < words.length; i++) {
    if (i % n == 0) {
      // n번째 단어마다 턴 증가
      turn++;
    }
    if (
      // 끝말잇기 종료조건
      words[i].length < 2 ||
      words[i - 1][words[i - 1].length - 1] !== words[i][0] ||
      isExist.has(words[i])
    ) {
      return [(i % n) + 1, turn]; // 인덱스 기준 0~n-1 번째 사람이므로, +1 하여 반환
    }
    isExist.add(words[i]); // 단어 저장소에 추가
  }

  return [0, 0]; // 종료조건에 걸린것이 없다면, [0,0] 반환
}