class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), ans = INT_MAX, left = 0;
        vector<int> sums(n+1, 0);
        for (int i = 1; i <= n; ++i) sums[i] = sums[i-1] + nums[i-1];
        
        for (int right = 1; right <= n; ++right){
            while (sums[right] - sums[left] >= target){
                ++left;
                ans = min(ans, right - left + 1);
            }
            
        }
        return (ans != INT_MAX) ? ans : 0;
    }
};