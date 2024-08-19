class Solution:
    def minSteps(self, n: int) -> int:
        @lru_cache(maxsize = None)
        def dp(curr: int, a_cnt: int) -> int:
            # base case
            if curr >= n:
                return 0 if curr == n else float('inf')
            
            # Paste of the count of 'A' or copy all and then paste the count of 'A'
            min_steps = 1 + dp(curr + a_cnt, a_cnt)
            a_cnt = curr
            min_steps = min(min_steps, 2 + dp(curr + a_cnt, a_cnt))
            
            return min_steps
        
        return 0 if n == 1 else 1 + dp(1, 1)