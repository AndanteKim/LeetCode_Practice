class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n);
        for (int i = 0; i < n; ++i){
            int maxSubsetSize = 0;
            for (int k = 0; k < i; ++k){
                if (nums[i] % nums[k] == 0) maxSubsetSize = max(maxSubsetSize, dp[k]);
            }
            ++maxSubsetSize;
            dp[i] = maxSubsetSize;
        }
        
        int maxSize = 0, maxSizeIndex = 0;
        for (int i = 0; i < n; ++i) {
            if (dp[i] > maxSize){
                maxSize = max(maxSize, dp[i]);
                maxSizeIndex = i;
            }
        }
        
        vector<int> ans;
        int currSize = maxSize, currTail = nums[maxSizeIndex];
        for (int i = maxSizeIndex; i >= 0; --i){
            if (currSize == dp[i] && currTail % nums[i] == 0){
                ans.push_back(nums[i]);
                --currSize;
                currTail = nums[i];
            }
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};