class Solution {
private:
    int m, n;

    int dp(int i, int j, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& memo) {
        if (i == m || j == n) return 0;
        
        if (memo[i][j] != -1) return memo[i][j];

        int use = nums1[i] * nums2[j] + dp(i + 1, j + 1, nums1, nums2, memo);
        return memo[i][j] = max(use, max(dp(i + 1, j, nums1, nums2, memo), dp(i, j + 1, nums1, nums2, memo)));
    }

public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        
        int minElem1 = *min_element(nums1.begin(), nums1.end()), maxElem1 = *max_element(nums1.begin(), nums1.end());
        int minElem2 = *min_element(nums2.begin(), nums2.end()), maxElem2 = *max_element(nums2.begin(), nums2.end());

        if (minElem1 > 0 && maxElem2 < 0) return minElem1 * maxElem2;
        if (maxElem1 < 0 && minElem2 > 0) return maxElem1 * minElem2;
        
        this -> m = nums1.size(), this -> n = nums2.size();
        vector memo(m, vector<int>(n, -1));
        return dp(0, 0, nums1, nums2, memo);
    }
};