class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n + 1), suffix(n + 1, std::numeric_limits<int>::max());

        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = max(prefix[i], nums[i]);
            suffix[n - 1 - i] = min(suffix[n - i], nums[n - 1 - i]);
        }

        for (int i = 0; i < n; ++i) {
            if (prefix[i + 1] - suffix[i] <= k) return i;
        }

        return -1;
    }
};