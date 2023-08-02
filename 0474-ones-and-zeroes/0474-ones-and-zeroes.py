class Solution:
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        @lru_cache(maxsize = None)
        def dp(i: int, rem_m: int, rem_n: int) -> int:
            if i < 0:
                return 0
            
            subset = 0
            cnt_m = strs[i].count('0')
            cnt_n = len(strs[i]) - cnt_m
            if cnt_m <= rem_m and cnt_n <= rem_n:
                subset += max(1 + dp(i - 1, rem_m - cnt_m, rem_n - cnt_n), dp(i - 1, rem_m, rem_n))
            else:
                subset += dp(i - 1, rem_m, rem_n)
                
            return subset
        
        length = len(strs)
        return dp(length - 1, m, n)