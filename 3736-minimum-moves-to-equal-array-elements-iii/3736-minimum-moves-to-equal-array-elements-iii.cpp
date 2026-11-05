class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans = 0, mx = *max_element(nums.begin(), nums.end());

        for (int num : nums) {
            ans += abs(num - mx);
        }

        return ans;
    }
};