class Solution {
private:
    int n1, n2;
    int dp(int i, int j, string& text1, string& text2, vector<vector<int>>& memo){
        if (i >= n1 || j >= n2)
            return 0;
        if (memo[i][j] != -1)
            return memo[i][j];
        
        int longest = 0;
        if (text1[i] == text2[j])
            longest = 1 + dp(i + 1, j + 1, text1, text2, memo);
        else
            longest = max(dp(i + 1, j, text1, text2, memo), dp(i, j + 1, text1, text2, memo));
        
        return memo[i][j] = longest;
    }
    
public:
    int longestCommonSubsequence(string text1, string text2) {
        this -> n1 = text1.size(), this -> n2 = text2.size();
        vector memo(n1 + 1, vector<int>(n2 + 1, -1));
        
        return dp(0, 0, text1, text2, memo);
    }
};