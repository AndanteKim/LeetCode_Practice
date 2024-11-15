class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size(), right = n - 1;
        
        while (right > 0 && arr[right] >= arr[right - 1])
            --right;
        
        int ans = right, left = 0;
        
        while (left < right && (left == 0 || arr[left - 1] <= arr[left])){
            // Find next valid number after arr[left]
            while (right < n && arr[left] > arr[right])
                ++right;
            
            // Save length of removed subarray
            ans = min(ans, right - left - 1);
            ++left;
        }
        
        return ans;
    }
};