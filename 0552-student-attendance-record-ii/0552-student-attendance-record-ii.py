class Solution:
    def checkRecord(self, n: int) -> int:
        def dp(day: int, absent: int, late: int) -> int:
            if day == n:
                return 1 if absent < 2 and late < 3 else 0
            
            if absent >= 2 or late >= 3:
                return 0
            
            if memo[day][absent][late] != -1:
                return memo[day][absent][late]
            
            # If today is present
            ways = dp(day + 1, absent, 0)
            
            # If today is late
            ways += dp(day + 1, absent, late + 1)
            
            # If today is absent
            ways += dp(day + 1, absent + 1, 0)
            
            memo[day][absent][late] = ways % mod
            return memo[day][absent][late]
        
        memo = [[[-1] * 3 for _ in range(4)] for _ in range(n + 1)]
        
        mod = 10 ** 9 + 7
        return dp(0, 0, 0)
        