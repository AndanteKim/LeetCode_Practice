class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // Space optimized bottom-up dynamic programming
        // Time complexity: O(n^2), Space Complexity: O(n)
        int n1 = text1.size(), n2 = text2.size();
        vector<int> prevDp(n2 + 1), dp(n2 + 1);
        
        for (int i = n1 - 1; i >= 0; --i){
            for (int j = n2 - 1; j >= 0; --j){
                if (text1[i] == text2[j])
                    dp[j] = 1 + prevDp[j + 1];
                else
                    dp[j] = max(prevDp[j], dp[j + 1]);
            }
            prevDp = dp;
        }
        
        return dp[0];
    }
};