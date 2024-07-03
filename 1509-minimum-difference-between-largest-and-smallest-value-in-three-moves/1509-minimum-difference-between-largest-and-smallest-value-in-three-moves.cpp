class Solution {
public:
    int minDifference(vector<int>& nums) {
        if (nums.size() < 5) return 0;
        
        int ans = INT_MAX, n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i <= 3; ++i){
            ans = min(ans, nums[n - 4 + i] - nums[i]);
        }
        
        return ans;
    }
};