class Queue {
  items = [];
  front = 0;
  rear = 0;

  push(item) {
    this.items.push(item);
    this.rear++;
  }
  pop() {
    return this.items[this.front++];
  }
  isEmpty() {
    return this.front === this.rear;
  }
}

function solution(maps) {
  const n = maps.length;
  const m = maps[0].length;
  const visited = Array.from(Array(n), () =>
    // 두번째 인자 : 각 요소를 변환해주는 매핑 함수
    Array(m)
      .fill(false)
      .map(() => Array(2).fill(false))
  ); // 3차원배열 visited[n][m][0,1]

  const dx = [-1, 1, 0, 0]; // 위 아래 왼쪽 오른쪽 순
  const dy = [0, 0, -1, 1];
  const q = new Queue();
  let endX = -1;
  let endY = -1;

  // 시작점과 도착점을 찾아 큐에 넣고 방문 여부 표시
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < m; j++) {
      if (maps[i][j] === "S") {
        // 시작점
        q.push([i, j, 0, 0]); // [x,y,lever방문했는지 여부, time]
        visited[i][j][0] = true;
      }
      if (maps[i][j] === "E") {
        // 도착점
        endX = i;
        endY = j;
      }
    }
  }

  while (!q.isEmpty()) {
    const [x, y, isLever, time] = q.pop();
    if (x === endX && y === endY && isLever === 1) {
      // 도착지점에 도달하면 결과 반환
      return time;
    }

    for (let i = 0; i < 4; i++) {
      const nx = x + dx[i];
      const ny = y + dy[i];
      if (nx >= 0 && ny >= 0 && nx < n && ny < m && maps[nx][ny] !== "X") {
        if (maps[nx][ny] === "L" && !visited[nx][ny][isLever]) {
          // 다음 이동 지점이 레버인경우
          q.push([nx, ny, 1, time + 1]);
            visited[nx][ny][1]=true;
        } else if (maps[nx][ny] !== "L" && !visited[nx][ny][isLever]) {
          // 레버가 아닌 경우
          q.push([nx, ny, isLever, time + 1]);
            visited[nx][ny][isLever]=true;
        }
      }
    }
  }

  return -1; // 도착점에 도달하지 못한 경우
}
