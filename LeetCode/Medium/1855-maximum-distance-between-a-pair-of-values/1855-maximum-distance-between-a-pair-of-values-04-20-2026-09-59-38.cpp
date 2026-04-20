class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size(), ans = 0;

        for (int p1 = 0, p2 = 0; p1 < m && p2 < n;) {
            if (nums1[p1] > nums2[p2]) {
                ++p1;
            }
            else {
                ans = max(ans, p2 - p1);
                ++p2;
            }
        }

        return ans;
    }
};