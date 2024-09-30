class CustomStack {
private:
    list<int> st;
    int maxSize;
    
public:
    CustomStack(int maxSize) {
        this -> maxSize = maxSize;
    }
    
    void push(int x) {
        // Add the element to the top of the stack if it hasn't reached maxSize
        if (st.size() < maxSize)
            st.push_back(x);
    }
    
    int pop() {
        // Return -1 if the stack is empty, otherwise remove and return the top element
        if (st.empty()) return -1;
        int topElement = st.back();
        st.pop_back();
        return topElement;
    }
    
    void increment(int k, int val) {
        // Incremeent the bottom k elements (or all elements if k > stack size)
        auto it = st.begin();
        for (int i = 0; i < k && it != st.end(); ++i, ++it)
            *it += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */