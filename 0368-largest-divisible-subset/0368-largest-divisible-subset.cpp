class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // Base case
        if (nums.size() == 0) return {};

        // Sort the nums
        sort(nums.begin(), nums.end());

        // The container keeping the size of the largest divisible subset ending with X_i
        // dp[i] corresponds to the length of EDS(X_i)
        int n = nums.size(), maxSubsetSize = 0;
        vector<int> dp(n);

        // Build the dynamic programming matrix/vector
        for (int i = 0; i < n; ++i){
            int maxSubsetSize = 0;
            for (int k = 0; k < i; ++k){
                if (nums[i] % nums[k] == 0)
                    maxSubsetSize = max(maxSubsetSize, dp[k]);
            }
            ++maxSubsetSize;
            dp[i] = maxSubsetSize;
        }

        // Find both the size of largest divisible set and its index
        int maxSize = 0, maxSizeIndex = 0;
        for (int i = 0; i < n; ++i){
            if (maxSize < dp[i]){
                maxSize = dp[i];
                maxSizeIndex = i;
            }
        }

        // Reconstruct the largest divisible subset
        // currSize: the size of the current subset
        // currTail: the last element in the current subset
        int currSize = maxSize, currTail = nums[maxSizeIndex];
        vector<int> ans;
        for (int i = maxSizeIndex; i >= 0; --i){
            if (currSize == dp[i] && currTail % nums[i] == 0){
                ans.push_back(nums[i]);
                --currSize;
                currTail = nums[i];
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};