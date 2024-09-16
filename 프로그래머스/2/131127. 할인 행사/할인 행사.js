function isObjSame(obj1, obj2) {
  const obj1keys = Object.keys(obj1);
  const obj2keys = Object.keys(obj2);
  if (obj1keys.length !== obj2keys.length) {
    return false;
  }
  for (const key of obj1keys) {
    const value1 = obj1[key];
    const value2 = obj2[key];
    if (value1 !== value2) {
      return false;
    }
  }
  return true;
}

function solution(want, number, discount) {
  var answer = 0;

  // 품목이름 - 개수 로 매핑
  const wantObj = {};
  for (let i = 0; i < want.length; i++) {
    wantObj[want[i]] = number[i];
  }

  for (let i = 0; i <= discount.length - 10; i++) {
    const buyObj = {}; // 10일동안 사는 물품이름 - 개수 모음
    for (let j = i; j < i + 10; j++) {
      if (wantObj[discount[j]])
        // 사고자하는 품목에 해당되면, 모음에 추가
        buyObj[discount[j]] = (buyObj[discount[j]] || 0) + 1; // buyobj[discount[j]]가 undefined경우, 0으로 설정됨
    }
    if (isObjSame(wantObj, buyObj)) {
      answer++;
    }
  }

  return answer;
}
