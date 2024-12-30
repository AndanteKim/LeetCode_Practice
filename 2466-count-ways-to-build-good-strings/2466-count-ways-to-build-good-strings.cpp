class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        // Use dp[i] to record to number of good strings of length i.
        const int mod = 1'000'000'007;
        vector<long> dp(high + 1);
        dp[0] = 1;

        // Iterate over each length 'end'.
        for (int end = 1; end <= high; ++end){
            // Check if the current string can be made by append zero '0's or one '1's.
            if (end >= zero)
                dp[end] += dp[end - zero] % mod;
            if (end >= one)
                dp[end] += dp[end - one] % mod;

            dp[end] %= mod;
        }

        // Add up to the number of strings with each valid length [low ~ high].
        return accumulate(dp.begin() + low, dp.begin() + high + 1, 0L) % mod;
    }
};