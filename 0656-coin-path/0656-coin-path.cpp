class Solution {
public:
    vector<int> cheapestJump(vector<int>& coins, int maxJump) {
        int n = coins.size();
        vector<int> dp(n, 1'000'000'000);
        dp[0] = 0;
        vector path(n, vector<int>{});
        path[0] = {1};

        for (int i = 1; i < n; ++i){
            if (coins[i] == -1) continue;

            for (int j = max(0, i - maxJump); j < i; ++j){
                if (dp[i] > (coins[i] + dp[j])){
                    dp[i] = coins[i] + dp[j];
                    vector<int> newPath = path[j];
                    newPath.push_back(i + 1);
                    path[i] = newPath;
                }
                else if (dp[i] == coins[i] + dp[j]){
                    vector<int> newPath = path[j];
                    newPath.push_back(i + 1);
                    if (path[i] > newPath)
                        path[i] = newPath;
                }
            }
        }

        return path.back();
    }
};