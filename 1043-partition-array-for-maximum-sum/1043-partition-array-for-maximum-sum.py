class Solution:
    def maxSumAfterPartitioning(self, arr: List[int], k: int) -> int:
        @lru_cache(maxsize = None)
        def dp(start: int, k: int) -> int:
            if start >= n:
                return 0
            
            curr_max, ans = 0, 0
            end = min(n, start + k)
            for i in range(start, end):
                curr_max = max(curr_max, arr[i])
                # Store the maximum of all options for the current subarray
                ans = max(ans, curr_max * (i - start + 1) + dp(i + 1, k))
            
            return ans
        
        n = len(arr)
        return dp(0, k)