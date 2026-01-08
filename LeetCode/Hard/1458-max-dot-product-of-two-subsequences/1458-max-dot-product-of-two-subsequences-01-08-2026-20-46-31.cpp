class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        
        int minElem1 = *min_element(nums1.begin(), nums1.end()), maxElem1 = *max_element(nums1.begin(), nums1.end());
        int minElem2 = *min_element(nums2.begin(), nums2.end()), maxElem2 = *max_element(nums2.begin(), nums2.end());

        if (minElem1 > 0 && maxElem2 < 0) return minElem1 * maxElem2;
        if (maxElem1 < 0 && minElem2 > 0) return maxElem1 * minElem2;
        
        int m = nums1.size(), n = nums2.size();
        vector dp(m + 1, vector<int>(n + 1, 0));

        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                int use = nums1[i] * nums2[j] + dp[i + 1][j + 1];
                dp[i][j] = max(use, max(dp[i + 1][j], dp[i][j + 1]));
            }
        }

        return dp[0][0];
    }
};