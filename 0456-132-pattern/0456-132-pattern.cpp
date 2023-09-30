class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if (nums.size() < 3)
            return false;
        
        int n = nums.size();
        vector<int> minArr(n);
        minArr[0] = nums[0];
        for (int i = 1; i < n; ++i)
            minArr[i] = min(minArr[i - 1], nums[i]);
        
        // monotonic stack
        stack<int> stack;
        for (int j = n - 1; j >= 0; --j){
            if (nums[j] <= minArr[j])
                continue;
            
            while (!stack.empty() && stack.top() <= minArr[j])
                stack.pop();
            
            if (!stack.empty() && stack.top() < nums[j])
                return true;
            stack.push(nums[j]);
        }
        
        return false;
    }
};