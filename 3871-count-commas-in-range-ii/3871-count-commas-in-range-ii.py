class Solution:
    def countCommas(self, n: int) -> int:
        ans, p = 0, 1000

        while p <= n:
            ans += n - p + 1
            p *= 1000
        
        return ans