class Solution {
private:
    int len1, len2;
    int dp(int i, int j, string& text1, string& text2, vector<vector<int>>& memo){
        if (i == len1 || j == len2) return 0;
        
        if (memo[i][j] != -1) return memo[i][j];
        
        int ans;
        if (text1[i] == text2[j])
            ans = 1 + dp(i + 1, j + 1, text1, text2, memo);
        else
            ans = max(dp(i + 1, j, text1, text2, memo), dp(i, j + 1, text1, text2, memo));
        
        memo[i][j] = ans;
        return ans;
    }
    
public:
    int longestCommonSubsequence(string text1, string text2) {
        len1 = text1.size(), len2 = text2.size();
        vector<vector<int>> memo(len1 + 1, vector<int>(len2 + 1, -1));
        
        return dp(0, 0, text1, text2, memo);
    }
};