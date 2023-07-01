class Solution:
    def distributeCookies(self, cookies: List[int], k: int) -> int:
        n = len(cookies)
        dp = [[float('inf')] * (1 << n) for _ in range(k + 1)]
        total = [0] * (1 << n)
        
        for mask in range(1 << n):
            accumulation = 0
            for i in range(n):
                if mask & (1 << i):
                    accumulation += cookies[i]
            total[mask] = accumulation
        
        dp[0][0] = 0
        for person in range(1, k + 1):
            for mask in range(1 << n):
                submask = mask
                while submask > 0:
                    dp[person][mask] = min(dp[person][mask], max(total[submask], dp[person - 1][mask ^ submask]))
                    submask = (submask - 1) & mask
        
        return dp[k][(1 << n) - 1]