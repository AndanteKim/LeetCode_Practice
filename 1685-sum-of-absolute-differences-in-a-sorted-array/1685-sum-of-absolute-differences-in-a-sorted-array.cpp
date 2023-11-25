class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size(), prefixSum = 0, suffixSum = accumulate(nums.begin(), nums.end(), 0);
        vector<int> ans;
        
        for (int i = 0; i < n; ++i){
            ans.push_back(i * nums[i] - prefixSum + suffixSum - (n - i) * nums[i]);
            prefixSum += nums[i];
            suffixSum -= nums[i];
        }
        
        return ans;
    }
};