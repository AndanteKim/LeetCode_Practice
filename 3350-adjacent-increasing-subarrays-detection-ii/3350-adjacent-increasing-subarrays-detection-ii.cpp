class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n + 1), suffix(n + 1);

        for (int i = 1; i <= n; ++i){
            if (i > 1 && nums[i - 2] < nums[i - 1])
                prefix[i] = prefix[i - 1] + 1;
            else
                prefix[i] = 1;
        }

        for (int i = n; i >= 1; --i){
            if (i < n && nums[i - 1] < nums[i]) suffix[i] = suffix[i + 1] + 1;
            else suffix[i] = 1;
        }

        int ans = 0;
        for (int i = 1; i <= n; ++i) ans = max(ans, min(prefix[i - 1], suffix[i]));

        return ans; 
    }
};