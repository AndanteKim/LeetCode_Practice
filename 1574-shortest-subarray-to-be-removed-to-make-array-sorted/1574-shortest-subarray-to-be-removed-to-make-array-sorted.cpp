class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size(), right = n - 1;
        
        // Find the longest non-decreasing prefix
        int left = 0;
        while (left + 1 < n && arr[left] <= arr[left + 1])
            ++left;
        
        // If the entire array is sorted
        if (left == n - 1) return 0;
        
        // Find the longest non-decreasing suffix
        while (right > 0 && arr[right - 1] <= arr[right])
            --right;
        
        // Initial assumption: Remove everything between the prefix and suffix
        int ans = min(n - 1 - left, right);
        
        // Use the binary search to merge prefix and suffix
        for (int i = 0; i <= left; ++i){
            int j = lower_bound(arr.begin() + right, arr.end(), arr[i]) - arr.begin();
            ans = min(ans, j - i - 1);
        }
        
        return ans;
    }
};