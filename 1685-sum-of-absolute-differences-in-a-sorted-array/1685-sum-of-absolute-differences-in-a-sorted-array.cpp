class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size(), leftSum = 0, totalSum = accumulate(nums.begin(), nums.end(), 0);
        vector<int> ans(n);
        
        for (int i = 0; i < n; ++i){
            int rightSum = totalSum - leftSum - nums[i];
            int leftCount = i, rightCount = n - 1 - i;
            int leftTotal = nums[i] * leftCount - leftSum, rightTotal = rightSum - rightCount * nums[i];
            
            ans[i] = leftTotal + rightTotal;
            leftSum += nums[i];
        }
        
        return ans;
    }
};