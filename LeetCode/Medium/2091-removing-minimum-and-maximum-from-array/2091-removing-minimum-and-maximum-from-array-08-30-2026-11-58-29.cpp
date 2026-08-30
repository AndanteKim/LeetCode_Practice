class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();

        int minElem = std::numeric_limits<int>::max(), maxElem = std::numeric_limits<int>::min(), minIdx = -1, maxIdx = -1;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] < minElem) {
                minIdx = i;
                minElem = nums[i];
            }

            if (nums[i] > maxElem) {
                maxIdx = i;
                maxElem = nums[i];
            }
        }

        int ans = std::numeric_limits<int>::max();

        ans = min(ans, n - abs(minIdx - maxIdx) + 1);
        ans = min(ans, max(minIdx + 1, maxIdx + 1));
        ans = min(ans, max(n - minIdx, n - maxIdx));

        return ans;
    }
};