class MRUQueue {
private:
    vector<int> queue;

public:
    MRUQueue(int n) {
        // Initialize the queue with numbers from 1 to n
        queue.resize(n);
        iota(queue.begin(), queue.end(), 1);
    }
    
    int fetch(int k) {
        // Get the k-th element (1 - indexed)
        int ans = queue[k - 1];
        // Remove the element from its current position in the queue
        queue.erase(queue.begin() + k - 1);
        
        // Push back the element to the end of the queue
        queue.push_back(ans);

        return ans;
    }
};

/**
 * Your MRUQueue object will be instantiated and called as such:
 * MRUQueue* obj = new MRUQueue(n);
 * int param_1 = obj->fetch(k);
 */