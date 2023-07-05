class Solution:
    @lru_cache(maxsize = None)
    def permutation(self, i: int) -> int:
        if i <= 1:
            return 1
        return i * self.permutation(i - 1)
    
    def uniquePaths(self, m: int, n: int) -> int:
        return self.permutation(m + n - 2)//(self.permutation(m - 1) * (self.permutation(n - 1)))
