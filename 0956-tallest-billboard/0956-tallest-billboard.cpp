class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        unordered_map<int, int> dp;
        dp[0] = 0;
        for (int r : rods){
            unordered_map<int, int> newDp(dp);
            for (auto& [diff, taller] : dp){
                int shorter = taller - diff;
                newDp[diff + r] = max(newDp[diff + r], taller + r);
                int newDiff = abs(shorter + r - taller);
                int newTaller = max(shorter + r, taller);
                newDp[newDiff] = max(newDp[newDiff], newTaller);
            }
            dp = newDp;
        }
        return dp[0];
    }
};