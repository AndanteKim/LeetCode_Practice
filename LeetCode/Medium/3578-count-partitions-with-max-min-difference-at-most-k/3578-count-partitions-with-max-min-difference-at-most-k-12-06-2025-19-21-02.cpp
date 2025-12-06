typedef long long ll;

class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        const int n = nums.size(), mod = 1'000'000'007;
        vector<ll> dp(n + 1), prefix(n + 1);
        dp[0] = 1, prefix[0] = 1;
        int j = 0;
        deque<int> minQ, maxQ;

        for (int i = 0; i < n; ++i) {
            // Maintain the maximum value queue
            while (!maxQ.empty() && nums[maxQ.back()] < nums[i])
                maxQ.pop_back();
            maxQ.push_back(i);

            // Maintain the minimum value queue
            while (!minQ.empty() && nums[minQ.back()] > nums[i])
                minQ.pop_back();
            minQ.push_back(i);

            // Adjust window
            while (!maxQ.empty() && !minQ.empty() && abs(nums[maxQ.front()] - nums[minQ.front()]) > k) {
                if (maxQ.front() == j) maxQ.pop_front();
                if (minQ.front() == j) minQ.pop_front();
                ++j;
            }

            if (j > 0)
                dp[i + 1] = (prefix[i] - prefix[j - 1] + mod) % mod;
            else
                dp[i + 1] = prefix[i] % mod;
            
            prefix[i + 1] = (prefix[i] + dp[i + 1]) % mod;
        }

        return dp[n];
    }
};