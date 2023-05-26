class Solution:
    @lru_cache(maxsize = None)
    def f(self, p: int, i: int, m: int) -> int:
        if i == self.n:
            return 0
        res = 1000000 if p == 1 else -1
        s = 0
        for x in range(1, min(2 * m, self.n - i) + 1):
            s += self.piles[i + x - 1]
            if p == 0:
                res = max(res, s + self.f(1, i + x, max(m, x)))
            else:
                res = min(res, self.f(0, i + x, max(m, x)))
        return res
    
    def stoneGameII(self, piles: List[int]) -> int:
        self.n, self.piles = len(piles), piles
        return self.f(0, 0, 1)
        
        