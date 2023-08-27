class Solution:
    def canCross(self, stones: List[int]) -> bool:
        @lru_cache(maxsize = None)
        def dp(idx: int, k: int) -> bool:
            if idx == n - 1:
                return True
            if idx > n:
                return False
            
            can_reach, i = False, idx + 1
            
            while i <= n - 1:
                if stones[idx] + k - 1 == stones[i]:
                    can_reach = can_reach or dp(i, k - 1)
                if stones[idx] + k == stones[i]:
                    can_reach = can_reach or dp(i, k)
                if stones[idx] + k + 1 == stones[i]:
                    can_reach = can_reach or dp(i, k + 1)
                i += 1
            
            return can_reach
        
        n = len(stones)
        
        return dp(0, 0)