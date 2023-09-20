class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size(), sum = accumulate(nums.begin(), nums.end(), 0);
        int target = sum - x, curr = 0, left = 0, ans = INT_MAX;
        
        for (int right = 0; right < n; ++right){
            curr += nums[right];
            
            while (curr > target && left <= right){
                curr -= nums[left];
                ++left;
            }
            if (curr == target)
                ans = min(ans, n - 1 - (right - left));
        }
        
        return ans == INT_MAX? -1 : ans;
    }
};