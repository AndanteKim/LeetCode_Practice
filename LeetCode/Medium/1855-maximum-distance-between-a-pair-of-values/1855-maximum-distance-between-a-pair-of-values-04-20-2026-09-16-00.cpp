class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int ans = 0, j = 0;

        for (int i = 0; i < m; ++i) {
            j = max(i, j);
            for (; j < n && nums1[i] <= nums2[j]; ++j){
                ans = max(ans, j - i);
            }
        }

        return ans;
    }
};