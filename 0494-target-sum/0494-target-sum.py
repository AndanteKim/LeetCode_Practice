class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        n = len(nums)
        @lru_cache(maxsize = None)
        def dfs(idx: int, total: int) -> int:
            if idx == n and total == target:
                return 1
            if idx >= n and total != target:
                return 0
            
            ways = 0
            total += nums[idx]
            ways += dfs(idx + 1, total)
            total -= nums[idx]
            total -= nums[idx]
            ways += dfs(idx + 1, total)
            return ways        
        
        return dfs(0, 0)