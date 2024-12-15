class Solution {
public:
    vector<int> maximumLengthOfRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n), right(n);
        stack<int> indexStack;
        // Calculate left boundaries
        for (int currIdx = 0; currIdx < n; ++currIdx){
            while (!indexStack.empty() && nums[indexStack.top()] < nums[currIdx])
                indexStack.pop();
            
            left[currIdx] = indexStack.empty()? -1: indexStack.top();
            indexStack.push(currIdx);
        }
        
        // Clear the stack for reuse
        while (!indexStack.empty())
            indexStack.pop();
        
        // Calculate right boundaries
        for (int currIdx = n - 1; currIdx >= 0; --currIdx){
            while (!indexStack.empty() && nums[indexStack.top()] < nums[currIdx])
                indexStack.pop();
            right[currIdx] = indexStack.empty()? n : indexStack.top();
            indexStack.push(currIdx);
        }
        
        // Calculate the maximal range for each element
        vector<int> ans(n);
        for (int currIdx = 0; currIdx < n; ++currIdx)
            ans[currIdx] = right[currIdx] - left[currIdx] - 1;
        
        return ans;
    }
};