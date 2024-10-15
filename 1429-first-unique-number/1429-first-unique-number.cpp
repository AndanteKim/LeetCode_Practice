class FirstUnique {
private:
    queue<int> queue;
    unordered_map<int, int> seen;
    
public:
    FirstUnique(vector<int>& nums) {
        for (int num : nums)
            add(num);
    }
    
    int showFirstUnique() {
        // If we've seen the frequency of integer in queue over 1, then pop it in the queue.
        while (!queue.empty() && seen[queue.front()] > 1)
            queue.pop();
        return (queue.empty())? -1 : queue.front();
    }
    
    void add(int value) {
        if (!seen.count(value))
            queue.push(value);
        ++seen[value];
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */