class Solution {
public:
    long long countSubarrays(vector<int>& nums) {
        // sliding window
        int left = 0, prev = 0;
        long long ans = 0;
        for (int right = 0; right < nums.size(); ++right){
            if (prev >= nums[right])
                left = right;
            ans += right - left + 1;
            prev = nums[right];
        }
        
        return ans;
    }
};