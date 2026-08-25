class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int ans = k;
        unordered_set<int> seen(nums.begin(), nums.end());

        while (seen.contains(ans)) {
            ans += k;
        }

        return ans;
    }
};