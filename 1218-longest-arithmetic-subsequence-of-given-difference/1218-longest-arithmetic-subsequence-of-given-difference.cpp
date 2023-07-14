class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size(), ans = 1;
        unordered_map<int, int> dp;
        
        for (int num : arr){
            dp[num] = dp.count(num - difference)? dp[num - difference] + 1: 1;
            ans = max(ans, dp[num]);
        }
        
        return ans;
    }
};