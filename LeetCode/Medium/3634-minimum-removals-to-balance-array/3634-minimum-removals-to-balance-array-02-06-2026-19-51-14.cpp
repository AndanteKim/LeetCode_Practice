class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size(), right = 0;
        int ans = n;
        sort(nums.begin(), nums.end());

        for (int left = 0; left < n; ++left) {
            while (right < n && nums[right] <= (long long)nums[left] * k) ++right;

            ans = min(ans, n - (right - left));
        }

        return ans; 
    }
};