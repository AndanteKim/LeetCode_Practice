class Solution {
public:
    int numberOfWays(int numPeople) {
        int m = 1000000007;
        vector<int> dp(numPeople / 2 + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= numPeople / 2; ++i){
            for (int j = 0; j < i; ++j){
                (dp[i] += (long long)dp[j] * dp[i - j - 1] % m) %= m;
            }
        }
        return dp[numPeople / 2];
    }
};