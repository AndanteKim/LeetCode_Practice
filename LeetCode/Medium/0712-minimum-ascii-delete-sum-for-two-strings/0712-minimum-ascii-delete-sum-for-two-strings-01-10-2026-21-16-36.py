class Solution:
    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        @lru_cache(maxsize = None)
        def dp(i: int, j: int) -> int:
            if i == m:
                s2_sum = 0
                for k in range(j, n):
                    s2_sum += ord(s2[k])
                return s2_sum
            
            if j == n:
                s1_sum = 0
                for k in range(i, m):
                    s1_sum += ord(s1[k])
                return s1_sum

            ans = float('inf')
            if s1[i] == s2[j]:
                ans = min(dp(i + 1, j + 1), ord(s1[i]) + dp(i + 1, j), ord(s2[j]) + dp(i, j + 1))
            else:
                ans = min(ord(s1[i]) + dp(i + 1, j), ord(s2[j]) + dp(i, j + 1))
            
            return ans
        
        m, n = len(s1), len(s2)
        return dp(0, 0)