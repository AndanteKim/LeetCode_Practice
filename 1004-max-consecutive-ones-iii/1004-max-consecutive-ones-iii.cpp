class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size(), left = 0, ans = 0, remain = k;
        
        for (int right = 0; right < n; ++right){
            remain -= nums[right] == 0;
            while (left <= right && remain < 0){
                remain += nums[left] == 0;
                ++left;
            }
            ans = max(ans, right - left + 1);
        }
        
        return ans;
    }
};