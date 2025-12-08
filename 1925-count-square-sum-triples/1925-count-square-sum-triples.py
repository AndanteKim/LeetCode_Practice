class Solution:
    def countTriples(self, n: int) -> int:
        ans = 0
        
        for i in range(1, n):
            for j in range(1, n):
                s = i ** 2 + j ** 2
                if (s ** 0.5 == int(s ** 0.5)) and s <= n ** 2:
                    ans += 1
        
        return ans