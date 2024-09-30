class CustomStack {
private:
    vector<int> st;
    int ptr;
    
public:
    CustomStack(int maxSize) {
        st.resize(maxSize, -1);
        ptr = -1;
    }
    
    void push(int x) {
        if (ptr + 1 >= st.size())
            return;
        st[++ptr] = x;
    }
    
    int pop() {
        if (ptr < 0)
            return -1;
        
        return st[ptr--];
    }
    
    void increment(int k, int val) {
        for (int i = 0; i < min(k, (int)st.size()); ++i)
            st[i] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */