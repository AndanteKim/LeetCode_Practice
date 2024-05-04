class Solution {
public:
    long long countPairs(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        long long ans = 0;
        vector<long long> diff(n);
        
        // diff[i] stores nums1[i] - nums2[i]
        for (int i = 0; i < n; ++i) diff[i] = static_cast<long>(nums1[i]) - nums2[i];
        
        sort(diff.begin(), diff.end());
        
        // Count the number of valid pairs
        for (int i = 0; i < n; ++i){
            // All indices j following i make a valid pair
            if (diff[i] > 0)
                ans += n - i - 1;
                
            else{
                // Binary search to find the first index j
                // that makes aa valid pair with i
                int left = i + 1, right = n - 1;
                
                while (left <= right){
                    int mid = left + ((right - left) >> 1);
                    // If diff[mid] doesn't make a valid pair, search in right half
                    if (diff[i] + diff[mid] <= 0) left = mid + 1;
                    // If diff[mid] is a valid pair, search in left half
                    else right = mid - 1;
                }
                
                // After the search left points to the first index j that makes
                // a valid pair with i, so we count that and all following indices
                ans += n - left;
            }
            
            
        }
        
        return ans;
    }
};