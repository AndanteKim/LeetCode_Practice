class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 0, left = 0, zeroCount = 0;
        
        for (int right = 0; right < nums.size(); ++right){
            zeroCount += (nums[right] == 0);
            while (zeroCount > 1){
                zeroCount -= (nums[left] == 0);
                ++left;
            }
            
            ans = max(ans, right - left);
        }
        
        return ans;
    }
};