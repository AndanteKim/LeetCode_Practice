class Solution:
    def numRollsToTarget(self, n: int, k: int, target: int) -> int:
        
        @lru_cache(maxsize = None)
        def dp(currSum: int, remain: int, dice_max: int) -> int:
            if remain == 0:
                if currSum == target:
                    return 1
                return 0
            
            ways = 0
            for i in range(1, dice_max):
                ways = (ways + dp(currSum + i, remain - 1, dice_max)) % (10 ** 9 + 7)
            
            return ways
            
        
        return dp(0, n, k + 1) % (10 ** 9 + 7)