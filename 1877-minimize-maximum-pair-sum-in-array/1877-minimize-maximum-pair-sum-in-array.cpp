class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int ans = 0, i = (nums.size() >> 1) - 1, j = (nums.size() >> 1);
        while (i >= 0 && j < nums.size()){
            ans = max(ans, nums[i] + nums[j]);
            --i;
            ++j;
        }
        
        return ans;
    }
};