class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // Longest consecutive sequence of the maximum value
        // k := maximum number
        int ans = 0, k = 0, n = nums.size(), currentStreak = 0;
        
        for (int num : nums){
            if (k < num){
                k = num;
                ans = currentStreak = 0;
            }
                
            if (k == num)
                ++currentStreak;
            else
                currentStreak = 0;
                
            ans = max(ans, currentStreak);
        }
        
        return ans;
    }
};