typedef long long ll;

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size(), same = 0, right = -1;
        ll ans = 0;
        unordered_map<int, long long> counts;

        for (int left = 0; left < n; ++left){
            while (same < k && right + 1 < n){
                ++right;
                same += counts[nums[right]];
                ++counts[nums[right]];
            }

            if (same >= k)
                ans += n - right;

            --counts[nums[left]];
            same -= counts[nums[left]];
        }

        return ans;
    }
};