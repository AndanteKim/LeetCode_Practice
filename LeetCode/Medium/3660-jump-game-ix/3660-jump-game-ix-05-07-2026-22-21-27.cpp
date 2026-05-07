class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        using Item = pair<int, int>;
        vector<Item> prevMax(n);
        Item prev = {std::numeric_limits<int>::min(), -1};

        for (int i = 0; i < n; ++i) {
            if (nums[i] > prev.first) prev = {nums[i], i};
            prevMax[i] = prev;
        }

        auto process = [&](auto& self, int r, int rightMin, int rightMax) -> void {
            auto [pMax, pivotIdx] = prevMax[r];
            int currMax = pMax <= rightMin? pMax : rightMax;

            int nextRightMin = min(pMax, rightMin);
            for (int i = pivotIdx; i <= r; ++i) {
                ans[i] = currMax;
                nextRightMin = min(nextRightMin, nums[i]);
            }

            if (pivotIdx == 0) return;

            self(self, pivotIdx - 1, nextRightMin, currMax);
        };

        process(process, n - 1, std::numeric_limits<int>::max(), 0);

        return ans;
    }
};