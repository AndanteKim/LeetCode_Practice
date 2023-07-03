class Solution {
private:
    int n;
    int dp(int i, int remain, vector<vector<int>>& memo, vector<vector<int>>& piles){
        if (i == n || remain == 0) return 0;
        if (memo[i][remain] != -1) return memo[i][remain];
        
        int ans = dp(i + 1, remain, memo, piles);
        int curr = 0;
        for (int j = 0; j < min(remain, (int)piles[i].size()); ++j){
            curr += piles[i][j];
            ans = max(ans, curr + dp(i + 1, remain - j - 1, memo, piles));
        }
        
        return memo[i][remain] = ans;
    }
    
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        n = piles.size();
        vector<vector<int>> memo(n, vector<int>(k + 1, -1));
        return dp(0, k, memo, piles);
    }
};