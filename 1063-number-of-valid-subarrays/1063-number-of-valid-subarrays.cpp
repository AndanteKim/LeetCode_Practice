class Solution {
public:
    int validSubarrays(vector<int>& nums) {
        stack<int> stack;
        int ans = 0;
        
        for (int i = 0; i < nums.size(); ++i){
            // keep popping elements from the stack
            // until the current element becomes greater than the top element
            while (!stack.empty() && nums[i] < nums[stack.top()]){
                // The diff between the current index and the stack top would be the subarray size
                // which is equal to the number of subarrays
                ans += i - stack.top();
                stack.pop();
            }
            
            stack.push(i);
        }
        
        // For all remaining elements, the last element will be considered as the right endpoint
        while (!stack.empty()){
            ans += nums.size() - stack.top();
            stack.pop();
        }
        
        return ans;
    }
};