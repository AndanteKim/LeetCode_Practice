class Solution {
private:
    int computeCost(vector<vector<int>>& dp, int i, int j, string& s1, string& s2){
        if (i < 0 && j < 0) return 0;
        
        if (i < 0) {
            int deleteCost = 0;
            for (int ptr = 0; ptr <= j; ++ptr) deleteCost += s2[ptr];
            return deleteCost;
        }
        
        if (j < 0) {
            int deleteCost = 0;
            for (int ptr = 0; ptr <= i; ++ptr) deleteCost += s1[ptr];
            return deleteCost;
        }
        
        if (dp[i][j] != -1) return dp[i][j];
        
        if (s1[i] == s2[j]) dp[i][j] = computeCost(dp, i - 1, j - 1, s1, s2);
        else{
            dp[i][j] = min(s1[i] + computeCost(dp, i - 1, j, s1, s2), s2[j] + computeCost(dp, i, j - 1, s1, s2));
        }
        
        return dp[i][j];
    }
    
public:
    int minimumDeleteSum(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        vector dp(n1 + 1, vector<int>(n2 + 1, -1));
        return computeCost(dp, n1 - 1, n2 - 1, s1, s2);
    }
};