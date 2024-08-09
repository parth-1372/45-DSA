class MyQueue {
public:
    stack<int> q;
    MyQueue() {
        
    }
    
    void push(int x) {
        stack<int> t;
        while(!q.empty()){
            t.push(q.top());
            q.pop();
        }
        q.push(x);
        while(!t.empty()){
            q.push(t.top());
            t.pop();
        }
        return;
    }
    
    int pop() {
         int x = q.top();
         q.pop();
        return x;
        
    }
    
    int peek() {
        return q.top();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */