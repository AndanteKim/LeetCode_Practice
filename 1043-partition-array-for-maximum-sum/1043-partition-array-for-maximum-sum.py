class Solution:
    def maxSumAfterPartitioning(self, arr: List[int], k: int) -> int:
        n = len(arr)
        dp = [0] * (n + 1)
        
        for start in range(n - 1, -1, -1):
            curr_max = 0
            end = min(n, start + k)
            
            for i in range(start, end):
                curr_max = max(curr_max, arr[i])
                # Store the maximum of all options for the current subarray.
                dp[start] = max(dp[start], dp[i + 1] + curr_max * (i - start + 1))

        return dp[0]