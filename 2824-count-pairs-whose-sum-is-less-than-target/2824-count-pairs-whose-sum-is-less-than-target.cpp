class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int ans = 0, n = nums.size();
        int right = n - 1;

        sort(nums.begin(), nums.end());
        for (int left = 0; left < n && left < right;){
            if (nums[left] + nums[right] < target){
                ans += right - left;
                ++left;
            }
            else
                --right;
        }

        return ans;
    }
};