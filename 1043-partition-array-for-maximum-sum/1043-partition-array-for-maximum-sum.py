class Solution:
    def maxSumAfterPartitioning(self, arr: List[int], k: int) -> int:
        n, K = len(arr), k + 1
        dp = [0] * K
        
        for start in range(n - 1, -1, -1):
            curr_max, end = 0, min(n, start + k)
            
            for i in range(start, end):
                curr_max = max(curr_max, arr[i])
                dp[start % K] = max(dp[start % K], dp[(i + 1) % K] + curr_max * (i - start + 1))
       
        return dp[0]