class MinStack {
    stack<int> st;
    stack<pair<int, int>> min_st;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        
        if (min_st.empty() || val < min_st.top().first) min_st.push({val, 1});
        else if (val == min_st.top().first) ++min_st.top().second;
        
    }
    
    void pop() {
        if (min_st.top().first == st.top()) --min_st.top().second;
        
        if (min_st.top().second == 0) min_st.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min_st.top().first;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */