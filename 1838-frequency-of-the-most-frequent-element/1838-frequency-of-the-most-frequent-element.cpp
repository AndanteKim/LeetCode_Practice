class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size(), ans = 0, left = 0;
        long curr = 0;
        
        for (int right = 0; right < n; ++right){
            int target = nums[right];
            curr += target;
            while ((long)target * (right - left + 1) - curr > k){
                curr -= nums[left];
                ++left;
            }
            
            ans = max(ans, right - left + 1);
        }
        
        return ans;
    }
};