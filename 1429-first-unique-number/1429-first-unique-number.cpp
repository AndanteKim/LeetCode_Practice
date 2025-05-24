class FirstUnique {
private:
    queue<int> q;
    unordered_map<int, int> frequency;

public:
    FirstUnique(vector<int>& nums) {
        for (int num : nums){
            if (frequency[num] == 0)
                q.push(num);
            
            ++frequency[num];
            while (!q.empty() && frequency[q.front()] > 1)
                q.pop();
        }
    }
    
    int showFirstUnique() {
        return !q.empty()? q.front() : -1;
    }
    
    void add(int value) {
        ++frequency[value];

        if (frequency[value] == 1)
            q.push(value);
        else{
            while (!q.empty() && frequency[q.front()] > 1)
                q.pop();
        }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */