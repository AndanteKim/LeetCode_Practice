class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftSum(n), rightSum(n), ans(n);
        
        for (int i = 1; i < n; ++i){
            leftSum[i] = leftSum[i - 1] + nums[i - 1];
            rightSum[n - 1 - i] = rightSum[n - i] + nums[n - i];
        }
        
        for (int i = 0; i < n; ++i)
            ans[i] = abs(leftSum[i] - rightSum[i]);
        
        return ans;
    }
};