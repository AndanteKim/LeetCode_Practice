class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int ans = 0;
        reverse(nums2.begin(), nums2.end());

        for (int i = 0; i < m; ++i) {
            int k = lower_bound(nums2.begin(), nums2.end(), nums1[i]) - nums2.begin();
            ans = max(ans, n - k - 1 - i);
        }

        return ans;
    }
};