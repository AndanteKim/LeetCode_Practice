class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixSum(n), answer(n);
        prefixSum[0] = nums[0];
        
        for (int i = 1; i < n; ++i)
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        
        for (int i = 0; i < n; ++i){
            int leftSum = prefixSum[i] - nums[i], rightSum = prefixSum.back() - prefixSum[i];
            int leftCount = i, rightCount = n - 1 - i;
            int leftTotal = nums[i] * leftCount - leftSum, rightTotal = rightSum - nums[i] * rightCount;
            answer[i] = leftTotal + rightTotal;
        }
        
        return answer;
    }
};