class Solution {
private:
    int m, n;
    int dp(vector<vector<int>>& memo, int i, int j, vector<int>& nums1, vector<int>& nums2){
        if (i == m || j == n)
            return 0;
        
        if (memo[i][j] != 0)
            return memo[i][j];
        
        int use = nums1[i] * nums2[j] + dp(memo, i + 1, j + 1, nums1, nums2);
        memo[i][j] = max(use, max(dp(memo, i + 1, j, nums1, nums2), dp(memo, i, j + 1, nums1, nums2)));
        
        return memo[i][j];
    }
    
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        this -> m = nums1.size(), this -> n = nums2.size();
        int max1 = INT_MIN, min1 = INT_MAX, max2 = INT_MIN, min2 = INT_MAX;
        
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
        
        vector memo(m, vector<int>(n));
        return dp(memo, 0, 0, nums1, nums2);
    }
};