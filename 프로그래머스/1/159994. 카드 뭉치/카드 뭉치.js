class Queue{
    items = []
    front = 0;
    rear = 0;
    constructor(array){
        this.items = array;
        this.rear = array.length;
    }
    push(item){
        this.items.push(item);
        this.rear++;
    }
    pop(){
        return this.items[this.front++];
    }
    top(){
        return this.items[this.front];
    }
    isEmpty(){
        return this.front === this.rear;
    }
}

function solution(cards1, cards2, goal) {  
    // 배열을 Queue로 변환
    const qcards1 = new Queue(cards1);
    const qcards2 = new Queue(cards2);
    const qgoal = new Queue(goal);
    
    while(!qgoal.isEmpty()){
        if(!qcards1.isEmpty() && qcards1.top() === qgoal.top()){
            qcards1.pop();
            qgoal.pop();
        }else if(!qcards2.isEmpty() && qcards2.top() === qgoal.top()){
            qcards2.pop();
            qgoal.pop();
        }else{
            break;
        }
    }
    
    return qgoal.isEmpty() ? "Yes" : "No";
}