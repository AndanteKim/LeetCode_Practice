class CustomStack {
private:
    vector<int> st, inc;
    int top;
        
public:
    CustomStack(int maxSize) {
        // Vector to store stack elements
        st.resize(maxSize);
        
        // Vector to store increments for lazy propagation
        inc.resize(maxSize);
        
        // Current top index of the stack
        top = -1;
    }
    
    void push(int x) {
        if (top < (int)st.size() - 1)
            st[++top] = x;
    }
    
    int pop() {
        if (top < 0)
            return -1;
        
        // Calculate the actual value with increment
        int res = st[top] + inc[top];
        
        // Propagate the increment to the element below
        if (top > 0){
            inc[top - 1] += inc[top];
        }
        
        // Reset the increment for this position
        inc[top--] = 0;
        
        return res;
    }
    
    void increment(int k, int val) {
        if (top >= 0){
            // Apply increment to the topmost element of the range
            int index = min(top, k - 1);
            inc[index] += val;
        }
            
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */