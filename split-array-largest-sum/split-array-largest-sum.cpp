class Solution {
private:
    int memo[1001][51];
    
public:
    int splitArray(vector<int>& nums, int k) {
        memset(memo, -1, sizeof(memo));
        
        int n = nums.size();
        vector<int> prefixSum(n + 1, 0);
        for (int i = 0; i < n; ++i){
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        
        for (int subarrCnt = 1; subarrCnt <= k; ++subarrCnt){
            for (int currIndex = 0; currIndex < n; ++currIndex){
                if (subarrCnt == 1) {
                    memo[currIndex][subarrCnt] = prefixSum[n] - prefixSum[currIndex];
                    continue;
                }
                
                int minLargestSplitSum = prefixSum[n];
                for (int i = currIndex; i <= n - subarrCnt; ++i){
                    int firstSplitSum = prefixSum[i + 1] - prefixSum[currIndex];
                    int largestSplitSum = max(firstSplitSum, memo[i + 1][subarrCnt - 1]);
                    minLargestSplitSum = min(minLargestSplitSum, largestSplitSum);
                    
                    if (firstSplitSum >= minLargestSplitSum) {
                        break;
                    }
                }
                
                memo[currIndex][subarrCnt] = minLargestSplitSum;
            }
        }
        
        return memo[0][k];
    }
};