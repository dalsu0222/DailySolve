function solution(progresses, speeds) {
    let answer = [];
    // 1. 각 작업의 배포 가능일 계산
    let daysLeft = progresses.map((progress,index) => Math.ceil((100 - progresses[index])/speeds[index]));
    
    let count = 0;  // 2. 배포될 작업수 카운트
    let maxDay = daysLeft[0];   // 3. 현재까지의 배포된 작업 중 가장 늦은 배포일수
    for(let i=0 ; i < progresses.length ; i++){
        if(maxDay >= daysLeft[i]){  // 4. 배포 가능일이 가장 늦은 배포일보다 빠르다면
            count++;
        }else{  // 5. 배포 예정일이 기준 배포일보다 느리면
            answer.push(count);
            count = 1;
            maxDay = daysLeft[i];
        }
    }
    answer.push(count); // 6. 남은 작업까지 함께 배포
    return answer;
}