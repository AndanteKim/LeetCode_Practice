class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int ans = 0, n = nums.size();
        int left = 0, right = accumulate(nums.begin(), nums.end(), 0);

        for (int curr = 0; curr < n; ++curr){
            if (nums[curr] == 0){
                if (abs(left - right) == 0) ans += 2;
                else if (abs(left - right) == 1) ++ans;
            }

            left += nums[curr];
            right -= nums[curr];
        }
        return ans;
    }
};