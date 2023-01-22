class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), ans = INT_MAX, left = 0, sum = 0;
        
        for (int right = 0; right < n; ++right){
            sum += nums[right];
            while (sum >= target){
                ans = min(ans, right - left + 1);
                sum -= nums[left++];
            }
            
        }
        return (ans != INT_MAX) ? ans : 0;
    }
};