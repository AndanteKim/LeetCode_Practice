class Solution:
    def f(self, p: int, i: int, m: int, piles: List[int], dp: List[List[List[int]]]) -> int:
        if i == self.n:
            return 0
        
        if dp[p][i][m] != -1:
            return dp[p][i][m]
        res = 1000000 if p == 1 else -1
        s = 0
        for x in range(1, min(2 * m, self.n - i) + 1):
            s += piles[i + x - 1]
            if p == 0:
                res = max(res, s + self.f(1, i + x, max(m, x), piles, dp))
            else:
                res = min(res, self.f(0, i + x, max(m, x), piles, dp))
        dp[p][i][m] = res
        return res
    
    def stoneGameII(self, piles: List[int]) -> int:
        self.n = len(piles)
        dp = [[[-1] * (self.n + 1) for i in range(self.n + 1)] for p in range(0, 2)]
        
        return self.f(0, 0, 1, piles, dp)
        