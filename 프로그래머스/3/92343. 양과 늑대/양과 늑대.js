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

function buildTree(info, edges) {
  const tree = Array.from({ length: info.length }, () => []); // Array.from({ length: n }) : 길이가 n인 배열을 생성
  for (const [from, to] of edges) {
    tree[from].push(to); // from -> to 연결하는 간선 정보 저장
  }
  return tree;
}

function solution(info, edges) {
  const tree = buildTree(info, edges);
  let maxSheep = 0;

  // bfs : 모든 가능한 경로 탐색
  const q = new Queue();
  q.push([0, 1, 0, new Set()]); // [현재 위치, 양의 수,늑대의 수, 방문해야하는 후보 노드 모음]
  // visited를 로컬 변수가 아닌 '큐의 원소'로 사용한 이유는?
  // 각 탐색 경로에서 서로 다른 방문 상태를 유지하기 위해서. 각 방문 노드마다 다른 방문 상태 저장.

  while (!q.isEmpty()) {
    const [current, sheep, wolf, visited] = q.pop();
    maxSheep = Math.max(maxSheep, sheep);
    // 방문한 노드 집합에 현재 노드의 이웃 노드들 추가. 방문한 노드를 다시 방문할 수 있도록 처리해야함.
    for (const next of tree[current]) {
      visited.add(next);
    }
    for (const next of visited) {
      if (info[next]) {
        // 늑대일 경우
        if (sheep > wolf + 1) {
          const newVisited = new Set(visited); // 방문하면, 방문해야하는 후보 노드 모음에서 제외시킴
          newVisited.delete(next);
          q.push([next, sheep, wolf + 1, newVisited]);
        }
      } else {
        // 양일 경우
        const newVisited = new Set(visited);
        newVisited.delete(next);
        q.push([next, sheep + 1, wolf, newVisited]); // (현재까지 모은 양의 수 + 1) 하여 이후 노드들 탐색
      }
    }
  }

  return maxSheep;
}
