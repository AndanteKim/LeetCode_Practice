class MyQueue {
    stack<int> st;
    stack<int> q;
public:
    MyQueue() {}
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        peek();
        int ans = st.top();
        st.pop();
        return ans;
    }
    
    int peek() {
        if (st.empty()){
            while (!q.empty()) {
                st.push(q.top());
                q.pop();
            };
        }
        return st.top();
    }
    
    bool empty() {
        return q.empty() && st.empty();
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