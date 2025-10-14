class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), preCount = 0, count = 1, ans = 0;

        for (int i = 1; i < n; ++i){
            if (nums[i] > nums[i - 1]) ++count;
            else{
                preCount = count;
                count = 1;
            }

            ans = max(ans, min(preCount, count));
            ans = max(ans, count >> 1);
        }

        return ans >= k;
    }
};