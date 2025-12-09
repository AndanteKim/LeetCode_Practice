class Solution {
public:
    int minProductSum(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end(), [](int a, int b){return a > b;});
        sort(nums2.begin(), nums2.end());

        int ans = 0, n = nums1.size();
        
        for (int i = 0; i < n; ++i) {
            ans += nums1[i] * nums2[i];
        }

        return ans;
    }
};