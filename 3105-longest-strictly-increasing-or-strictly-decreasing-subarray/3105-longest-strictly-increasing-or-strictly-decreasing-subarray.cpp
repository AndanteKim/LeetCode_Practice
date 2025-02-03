class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size(), increasing = std::numeric_limits<int>::min(), decreasing = std::numeric_limits<int>::max();
        int ans = 0, incCount = 0, decCount = 0;

        for (int i = 0; i < n; ++i){
            if (increasing < nums[i])
                ++incCount;
            
            else
                incCount = 1;

            if (decreasing > nums[i])
                ++decCount;
            else
                decCount = 1;

            increasing = nums[i], decreasing = nums[i];
            ans = max(ans, max(incCount, decCount));
        }

        return ans;
    }
};