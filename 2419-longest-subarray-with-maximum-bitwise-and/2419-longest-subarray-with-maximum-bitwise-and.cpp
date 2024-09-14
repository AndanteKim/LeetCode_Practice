class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 0, k = 0, n = nums.size(), left = 0;
        unordered_map<int, int> seen;
        
        for (int right = 0; right < n; ++right){
            k = max(k, nums[right]);
            while (left < right && (nums[left] & nums[right]) < k)
                ++left;
            
            if (k == nums[right]){
                ans = max(seen[k], right - left + 1);
                seen[k] = max(seen[k], right - left + 1);
            }
        }
        
        return ans;
    }
};