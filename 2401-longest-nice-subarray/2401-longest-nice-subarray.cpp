class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        // Bit manipulation and sliding window
        int left = 0, used = 0, ans = 0;
        
        for (int right = 0; right < nums.size(); ++right){
            while (left < right && (nums[right] & used)){
                used ^= nums[left++];
            }
            used |= nums[right];
            ans = max(ans, right - left + 1);
        }
        
        return ans;
    }
};