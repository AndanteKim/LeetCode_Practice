class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, ans = INT_MAX, n = nums.size(), curr = 0;
        
        for (int right = 0; right < n; ++right){
            curr += nums[right];
            while (curr >= target){
                ans = min(ans, right - left + 1);
                curr -= nums[left];
                ++left;
            }
        }
        
        return (ans == INT_MAX)? 0 : ans;
    }
};