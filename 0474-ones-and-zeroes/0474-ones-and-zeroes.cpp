class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        
        for (string& s : strs){
            int count0 = count(s.begin(), s.end(), '0');
            int count1 = s.size() - count0;
            
            for (int i = m; i >= count0; --i){
                for (int j = n; j >= count1; --j)
                    dp[i][j] = max(1 + dp[i - count0][j - count1], dp[i][j]);
            }
        }
        
        return dp[m][n];
    }
};