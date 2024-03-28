class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        // base case
        if (k <= 0) return 0;
        
        unordered_map<int, int> count;
        int n = nums.size(), left = 0, curr = 0, ans = 0;
        
        for (int right = 0; right < n; ++right){
            while (count[nums[right]] == k && left < right){
                --count[nums[left++]];
                --curr;
            }
            
            ++count[nums[right]];
            ++curr;
            ans = max(ans, curr);
        }
        
        return ans;
    }
};