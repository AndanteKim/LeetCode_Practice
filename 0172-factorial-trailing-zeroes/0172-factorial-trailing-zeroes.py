class Solution:
    def trailingZeroes(self, n: int) -> int:
        factorial = 1
        
        while n > 0:
            factorial *= n
            n -= 1
            
        ans = 0
        while factorial % 10 == 0:
            ans += 1
            factorial //= 10
        
        return ans