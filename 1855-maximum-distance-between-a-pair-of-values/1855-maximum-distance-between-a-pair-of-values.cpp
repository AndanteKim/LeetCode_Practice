class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size(), ans = 0;
        reverse(nums2.begin(), nums2.end());
        
        for (int i = 0; i < m; ++i){
            int left = 0, right = n;
            
            while (left < right){
                int mid = (left + right) / 2;
                if (nums1[i] <= nums2[mid]) right = mid;
                else left = mid + 1;
            }
            
            ans = max(ans, n - left - i - 1);
        }
        
        return ans;
    }
};