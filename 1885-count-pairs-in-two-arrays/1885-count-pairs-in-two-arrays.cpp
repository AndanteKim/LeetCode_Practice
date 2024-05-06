class Solution {
public:
    long long countPairs(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        
        vector<int> diff;
        // Diff stores nums1[i] - nums2[i]
        for (int i = 0; i < n; ++i) diff.push_back(nums1[i] - nums2[i]);
        
        sort(diff.begin(), diff.end());
        
        // Count the number of valid pairs
        long long ans = 0;
        int left = 0, right = n - 1;
        
        while (left < right){
            // Left makes a valid pair with right
            // Right makes a valid pair with indices between the pointers
            if (diff[left] + diff[right] > 0){
                ans += (right-- - left);
            }
            // Left and right doesn't make a valid pair
            else{
                ++left;
            }
        }
        
        return ans;
    }
};