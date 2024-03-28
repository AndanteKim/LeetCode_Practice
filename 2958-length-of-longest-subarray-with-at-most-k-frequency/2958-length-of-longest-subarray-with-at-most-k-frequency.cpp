class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        // base case
        if (k <= 0) return 0;
        
        unordered_map<int, int> count;
        int n = nums.size(), left = 0, ans = 0;
        
        for (int right = 0; right < n; ++right){
            while (count[nums[right]] == k && left < right){
                --count[nums[left++]];
            }
            
            ++count[nums[right]];
            ans = max(ans, right - left + 1);
        }
        
        return ans;
    }
};