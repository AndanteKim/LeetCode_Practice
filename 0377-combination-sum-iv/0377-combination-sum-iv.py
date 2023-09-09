class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        
        @lru_cache(maxsize = None)
        def backtrack(i: int, curr: int) -> int:
            if i >= n or curr > target:
                return 0
            if curr == target:
                return 1
            
            ways = 0
            for j in range(n):
                ways += backtrack(j, curr + nums[j])
                
            return ways
            
        n = len(nums)
        return backtrack(0, 0)