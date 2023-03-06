class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        for (int left = 0; left < n; ++left){
            int min_val = INT_MAX, max_val = INT_MIN;
            
            for (int right = left; right < n; ++right){
                min_val = min(min_val, nums[right]);
                max_val = max(max_val, nums[right]);
                ans += max_val - min_val;
            }
        }
        return ans;
    }
};