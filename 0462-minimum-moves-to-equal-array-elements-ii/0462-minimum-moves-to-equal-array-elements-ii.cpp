class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int ans = 0, l = 0, r = nums.size() - 1;
        sort(nums.begin(), nums.end());

        while (l < r) {
            ans += nums[r--] - nums[l++];
        }

        return ans;
    }
};