class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int ans = 0, left = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        
        for (int right = 0; right < n; ++right){
            while (left <= right && nums[right] - nums[left] > 2 * k)
                ++left;
            ans = max(ans, right - left + 1);
        }
        
        return ans;
    }
};