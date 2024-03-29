class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans = 0;
        // Find the max element
        int left = 0, maxElementsInWindow = 0, maxElement = *max_element(nums.begin(), nums.end());
        
        for (int right = 0; right < nums.size(); ++right){
            // When the value of nums[right] is equal to max of elements in the nums array
            if (nums[right] == maxElement)
                ++maxElementsInWindow;
            
            // increment left for counting the subarrays until the max frequency of element in the window is equal to k
            while (maxElementsInWindow == k){
                if (nums[left++] == maxElement)
                    --maxElementsInWindow;
            }
            
            ans += left;
        }
        
        return ans;
    }
};