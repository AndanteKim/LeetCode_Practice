class Solution:
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        dp = [[0] * (n + 1) for _ in range(m + 1)]
        for s in strs:
            cnt0 = s.count('0')
            cnt1 = len(s) - cnt0
            
            for zeroes in range(m, cnt0 - 1, -1):
                for ones in range(n, cnt1 - 1, -1):
                    dp[zeroes][ones] = max(1 + dp[zeroes - cnt0][ones - cnt1], dp[zeroes][ones])
            
        return dp[m][n]
        