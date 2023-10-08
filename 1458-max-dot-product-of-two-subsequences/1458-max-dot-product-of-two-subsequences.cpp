class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int max1 = INT_MIN, max2 = INT_MIN;
        int min1 = INT_MAX, min2 = INT_MAX;
        
        for (int num : nums1){
            max1 = max(max1, num);
            min1 = min(min1, num);
        }
        
        for (int num : nums2){
            max2 = max(max2, num);
            min2 = min(min2, num);
        }
        
        if (max1 < 0 && min2 > 0)
            return max1 * min2;
        if (min1 > 0 && max2 < 0)
            return min1 * max2;
        
        int m = nums1.size(), n = nums2.size();
        vector dp(m + 1, vector<int>(n + 1));
        
        for (int i = m - 1; i >= 0; --i){
            for (int j = n - 1; j >= 0; --j){
                int use = nums1[i] * nums2[j] + dp[i + 1][j + 1];
                dp[i][j] = max(use, max(dp[i + 1][j], dp[i][j + 1]));
            }
        }
        
        return dp[0][0];
    }
};