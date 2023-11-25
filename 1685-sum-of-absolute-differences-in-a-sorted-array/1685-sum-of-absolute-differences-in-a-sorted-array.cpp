class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n), prefixSum(n + 1), suffixSum(n + 1);
        
        for (int i = 1; i <= n; ++i)
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
        
        for (int i = n - 1; i >= 0; --i)
            suffixSum[i] = suffixSum[i + 1] + nums[i];
        
        for (int i = 0; i < n; ++i){
            int curr = nums[i] * i - prefixSum[i] + suffixSum[i + 1] - nums[i] * (n - 1 - i);
            ans[i] = curr;
        }
        
        return ans;
    }
};