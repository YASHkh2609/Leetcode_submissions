class MyStack {
    queue<int>q1;
    // queue<int>q2;
public:    
    void push(int x) {
        // q2.push(x);
        // while(!q1.empty()){
        //     q2.push(q1.front());
        //     q1.pop();
        // }
        // while(!q2.empty()){
        //     q1.push(q2.front());
        //     q2.pop();
        // }
        q1.push(x);
        for(int i=0;i<q1.size()-1;i++){
            q1.push(q1.front());
            q1.pop();
        }
    }
    int pop() {
        int top=q1.front();
        q1.pop();
        return top;

    }  
    int top() {
        return q1.front();
    }
    
    bool empty() {
        if(q1.size()==0)return true;
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */