class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size(), i = 0;
        int p, q, j;
        long long ans = std::numeric_limits<long long>::min(), res, maxSum, currSum;

        while (i < n) {
            res = 0;
            j = i + 1;

            // First segment
            while (j < n && nums[j - 1] < nums[j]) ++j;
            p = j - 1;
            if (p == i) {
                ++i;
                continue;
            }

            // Second segment
            res += nums[p] + nums[p - 1];
            while (j < n && nums[j] < nums[j - 1]) {
                res += nums[j++];
            }

            q = j - 1;
            if (p == q || q == n - 1 || (nums[j] <= nums[q])) {
                i = q;
                continue;
            }

            // Third segment
            res += nums[q + 1];
            int k = q + 2;
            maxSum = 0, currSum = 0;
            while (k < n && nums[k - 1] < nums[k]) {
                currSum += nums[k++];
                maxSum = max(maxSum, currSum);
            }

            // Find the maximum sum of the first segment
            res += maxSum;
            maxSum = 0, currSum = 0;
            for (k = p - 2; k >= i; --k) {
                currSum += nums[k];
                maxSum = max(maxSum, currSum);
            }
            res += maxSum;

            // Update answer
            ans = max(ans, res);
            i = q - 1;
        }

        return ans;
    }
};