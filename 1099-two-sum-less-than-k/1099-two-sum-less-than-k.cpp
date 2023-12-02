class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1, ans = -1;
        
        while (left < right){
            if (nums[left] + nums[right] < k){
                ans = max(ans, nums[left] + nums[right]);
                ++left;
            }
            else
                --right;
        }
        
        return ans;
    }
};