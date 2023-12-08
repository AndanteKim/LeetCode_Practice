class Solution:
    def canJump(self, nums: List[int]) -> bool:
        @lru_cache(maxsize = None)
        def dp(pos: int) -> bool:
            if pos >= dest:
                return True
            
            for i in range(1, nums[pos] + 1):
                if dp(pos + i):
                    return True
            
            return False
        
        dest = len(nums) - 1
        return dp(0)