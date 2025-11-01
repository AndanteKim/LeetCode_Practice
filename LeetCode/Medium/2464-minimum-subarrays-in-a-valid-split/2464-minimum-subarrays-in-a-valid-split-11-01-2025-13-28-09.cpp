class Solution {
private:
    int n;
    int gcd(int a, int b){
        if (b > a) return gcd(b, a);

        int tmp;
        while (b > 0){
            tmp = a % b;
            a = b;
            b = tmp;
        }

        return a;
    }

public:
    int validSubarraySplit(vector<int>& nums) {
        this -> n = nums.size();

        vector<int> dp(n + 1, 100'000'000);
        dp[0] = 0;

        for (int i = 1; i < n + 1; ++i){
            for (int j = 1; j < i + 1; ++j){
                if (gcd(nums[i - 1], nums[j - 1]) > 1)
                    dp[i] = min(dp[i], dp[j - 1] + 1);
            }
        }

        return dp[n] == 100'000'000? -1 : dp[n];
    }
};